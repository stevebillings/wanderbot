# WanderBot

A robot built on Robot Operationg System 2 ("ROS 2") that wanders around avoiding walls and obstacles.

## Objective

I used this project to experiment with design approaches for both the finite state machine, and the navigation algorithm (and to work on my C++ skills).

## Design

### Finite State Machine

I started down the path of implementing the FSM with a switch statement, but ended up replacing that approach with a design based on the Gang of Four (GoF: the book "Design Patterns" by Gamma, Helm, Johnson, Vlissides) State Pattern. In my mind the GoF State Pattern provides a few significant advantages over the switch statement approach:

* It allows (actually, demands) that the code to handle each state is separated into its own class.
* It provides (actually, demands) a clear contract for the state handler classes.

Having the FSM split into a set of unit testable classes made it easy to develop and debug each state handler in isolation (using unit tests) before running everything together in the simulator.

While in the default ("Go") state, the robot navigates using VFF (see below). When it finds itself blocked (say, stuck in a corner), it briefly transitions to the "Back up" state (during which it backs up), and then to the "Change direction" state (during which it rotates to a new direction to try), before returning to the "Go" state.

### Navigation

While in the "Go" state, the robot uses a Virtual Force Field (VFF) algorithm to navigate. The VFF algorithm enables it to navigate around obstacles, but does not prevent it from getting stuck in corners (the section above on the Finite State Machine describes how it gets itself unstuck from corners).

### ROS dependency

The only source file with ROS dependencies is the main module wanderbot_node.cpp (WanderBotNode class). WanderBotNode is a ROS node that:

* Subscribes / listens to LaserScan messages for Lidar input data.
* Publishes Twist messages to move the robot.

## The robot

The robot (so far, at least) is simulated (I used gazebo). It provides lidar readings by publishing sensor_msgs::msg::LaserScan messages, and accepts motion control commands by listening for geometry_msgs::msg::Twist messages.

## To build

Prerequisite: ROS 2 Humble Hawksbill.

Build command: colcon build --symlink-install

## To run

To run the robot in the Gazebo simulator on a gazebo world that provides some challenges for the VFF navigation algorithm:

* In one window: ./scripts/start.sh
* In another window: source install/setup.bash && ros2 run wanderbot wanderbot

