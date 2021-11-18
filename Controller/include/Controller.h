//
// Created by cui on 2021/11/7.
//

#ifndef MSDC_CONTROLLER_H
#define MSDC_CONTROLLER_H

#include <iostream>
#include "JoystickControl.h"
#include "Motor.h"

using namespace std;

class Controller
{
public:
    virtual void control(JoystickControl &js_controller) = 0;
    inline virtual void setPin() = 0;
};

class ChassisControl : Controller
{
public:
    void control(JoystickControl &js_controller) override;
    inline void setPin() override;

private:
    void go_forward();
    void go_backward();
    void spin_left();
    void spin_right();

    Motor left_front_wheel, right_front_wheel, left_rear_wheel, right_rear_wheel;
};

class ArmControl : Controller
{
public:
    void control(JoystickControl &js_controller) override;
    inline void setPin() override;

private:
    Motor up_join_motor, down_join_motor;
};

#endif //MSDC_CONTROLLER_H