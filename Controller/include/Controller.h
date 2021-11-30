//
// Created by cui on 2021/11/7.
//

#ifndef MSDC_CONTROLLER_H
#define MSDC_CONTROLLER_H

#include <iostream>
#include <cmath>
#include "JoystickControl.h"
#include "Motor.h"

using namespace std;

class Controller
{
public:
    virtual void control(JoystickControl &js_controller) = 0;
};

class ChassisControl : Controller
{
public:
    ChassisControl();
    void control(JoystickControl &js_controller) override;
    inline void setPin();

private:
    void go_forward(int speed);
    void go_backward(int speed);
    void go_left(int speed);
    void go_right(int speed);
    void spin_left(int speed);
    void spin_right(int speed);

    Motor left_front_wheel, right_front_wheel, left_rear_wheel, right_rear_wheel;
};

class ArmControl : Controller
{
public:
    ArmControl();
    void control(JoystickControl &js_controller) override;
    inline void setPin();

private:
    Motor up_join_motor, down_join_motor;
    bool up_forward = true;
    bool down_forward = true;
};

#endif //MSDC_CONTROLLER_H