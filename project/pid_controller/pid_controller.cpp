/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd, double output_lim_max, double output_lim_min) {
   /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   **/
   parameter_p = Kp;
   parameter_i = Ki;
   parameter_d = Kd;
   output_max  = output_lim_max;
   output_min  = output_lim_min;
}


void PID::UpdateError(double cte) {
    /**
    * TODO: Update PID errors based on cte.
    **/
    
    // Handle invalid delta time
    double dt = std::max(0.0, delta_time);

    // Save previous cte in local variable
    double previous_error_p = error_p;

    // Update cte with new value
    error_p = cte;

    // Compute numerical derivative of the D-error
    // Assign zero to disable the D-component of the controller if div-by-zero is detected.
    error_d = 0.0;
    if (std::abs(dt) >= DIV_ZERO_THRESH)
    {
        // Normally, we should filter numerical derivatives to reduce noise.
        double new_error_d = (error_p - previous_error_p) / dt;

        // Filter error_d
        error_d = (1.0 - FILTER_D) * error_d + FILTER_D * new_error_d;
    }

    // Increase reset counter if cte is zero
    if (std::abs(cte) >= DIV_ZERO_THRESH)
    {
        reset_counter_i = 0;
    }
    else
    {
        reset_counter_i++;
    }
    
    if (reset_counter_i >= COUNTER_RESET_I)
    {
        // Reset I error
        error_i = 0.0;
        reset_counter_i = 0;
    }
    else
    {
        // Numerical integration for error_p.
        // For simplicity, use trapezoidal rule:
        // increment = 0.5 * delta_time * (cte + previous_cte)
        double increment = 0.5 * dt * (error_p + previous_error_p);
        
        // Add increment to I-error.
        error_i += increment;
    }
}

double PID::TotalError() {
    /**
    * TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
    */
    output_p = parameter_p * error_p;
    output_i = parameter_i * error_i;
    output_d = parameter_d * error_d;

    // Compute control value
    double control = output_p + output_i + output_d;

    // Limit control output
    control = std::max(control, output_min);
    control = std::min(control, output_max);

    return control;
}

void PID::UpdateDeltaTime(double new_delta_time) {
    /**
    * TODO: Update the delta time with new value
    */
   delta_time = new_delta_time;
}