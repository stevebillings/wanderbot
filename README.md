# WanderBot

A robot built on Robotic Operationg System 2 ("ROS 2") that wanders around avoiding walls and obstacles.

## Objective

I used this project to experiment with design approaches for:

* Finite state machine (FSM) based robot software.
* Navigation.

## Design

### Finite State Machine

I started down the path of implementing the FSM with a switch statement, but ended up ditching that approach in favor of a design based on the Gang of Four (GoF: the book "Design Patterns" by Gamma, Helm, Johnson, Vlissides) State Pattern. In my mind the GoF State Pattern provided a few significant advantages over the switch statement approach:

* It allows (actually, demands) that the code to handle each state is separated into its own class.
* It provides (actually, demands) a clear contract for each state handler class.

Having the FSM split into a set of unit testable classes made it easy to develop and debug each state handler in isolation (with all the benefits of the IDE debugger) before running everything together in the simulator.

While in the default ("Go") state, the robot navigates using VFF (see below). When it finds itself blocked (say, stuck in a corner), it briefly transitions to the "Blocked" state (during which it backs up), and then to the "Change direction" state (during which it rotates to a new direction to try), before returning to the "Go" state.

### Navigation

The robot uses a Virtual Force Field (VFF) algorithm to navigate. The VFF algorithm enables it to smoothly navigate around obstacles, but does not prevent it from getting stuck in corners.

## The robot

The robot is simulated (I used gazebo). It provides lidar readings by publishing sensor_msgs::msg::LaserScan messages, and accepts motion control commands by listening for geometry_msgs::msg::Twist messages.

