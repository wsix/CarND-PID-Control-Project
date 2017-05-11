# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets) == 0.13, but the master branch will probably work just fine
  * Follow the instructions in the [uWebSockets README](https://github.com/uWebSockets/uWebSockets/blob/master/README.md) to get setup for your platform. You can download the zip of the appropriate version from the [releases page](https://github.com/uWebSockets/uWebSockets/releases). Here's a link to the [v0.13 zip](https://github.com/uWebSockets/uWebSockets/archive/v0.13.0.zip).
  * If you run OSX and have homebrew installed you can just run the ./install-mac.sh script to install this
* Simulator. You can download these from the [project intro page](https://github.com/udacity/CarND-PID-Control-Project/releases) in the classroom.

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid` or `./pid twiddle` to tune hyperparameters with Twiddle algorithm.

## Reflections

In this project, I used one PID controller to control the steering angle. And proportional, integral and derivative hyperparameters were set to `0.119872, 0.0, 1.98053` with speed=70(`msgJson["throttle"] = 0.7`), which is tuned by Twiddle algorithm.

- The P error term is proportional to cross-track error (CTE) term and in this project this error mainly control the steering angle. So the increasing weight `Kp` increases the steering angle and enables the vehicle to better follows to sharp turns. But when `Kp` is too large, the car will oscillate around the target trajectory.
- The Integral in a PID controller is the sum of the instantaneous error over time and gives the accumulated offset that should have been corrected previously. The accumulated error is then multiplied by the integral gain (`Ki`) and added to the controller output. In this project, our car is in a simulation, we can assume that the steering drift in our car can be ignored. And when I apply twiddle algorithm to find suitable hyparameters, set `Ki=0` can reduce a lot of calculations.
- The Derivative in a PID controller can help the system damp down the oscillation, which can improve stability of the system.

Here I will explain my steps to chose suitable hyperparameters.

1. Manually select rough hyperparameters as the begining of twiddle algorithm. In this step, I selected `0.1, 0.0, 1,0`.
2. Set parameters of twiddle algorithm. In this step, I set `tolerance = 0.1`, `dp_[3] = {1.0, 0.0, 1.0}`.
3. Apply twiddle algotiyhm, wait for the algorithm converge.






