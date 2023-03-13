/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

class PID {
public:

   /**
   * TODO: Create the PID class
   **/

    /*
    * Errors
    */
    double error_p{0.0};
    double error_i{0.0};
    double error_d{0.0};

    /*
    * Coefficients
    */
    double parameter_p{0.0};
    double parameter_i{0.0};
    double parameter_d{0.0};

    /*
    * Partial outputs
    */
    double output_p{0.0};
    double output_i{0.0};
    double output_d{0.0};

    /*
    * Output limits
    */
    double output_max{0.0};
    double output_min{0.0};
  
    /*
    * Delta time
    */
    double delta_time{1.0};

    /*
    * Constructor
    */
    PID();

    /*
    * Destructor.
    */
    virtual ~PID();

    /*
    * Initialize PID.
    */
    void Init(double Kp, double Ki, double Kd, double output_lim_max, double output_lim_min);

    /*
    * Update the PID error variables given cross track error.
    */
    void UpdateError(double cte);

    /*
    * Calculate the total PID error.
    */
    double TotalError();
  
    /*
    * Update the delta time.
    */
    void UpdateDeltaTime(double new_delta_time);

private:

    static constexpr double DIV_ZERO_THRESH{0.0001};
    static constexpr double FILTER_D{0.8};
};

#endif //PID_CONTROLLER_H


