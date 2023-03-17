# Control and Trajectory Tracking for Autonomous Vehicle

# Proportional-Integral-Derivative (PID)

In this project, I was required to to design a PID controller to perform vehicle trajectory tracking. The controller was implemented in C++ and tested using [CARLA](https://carla.org/).

![local image](step1_1.png)

## Velocity Controller

At first, I had to setup the velocity controller. It was required to use the last element of the velocity profile as target. The below images depict different signal plots:
![local image](speed1.png)

![local image](speed2.png)
