//
// Created by cui on 2021/11/9.
//

#ifndef MSDC_JOYSTICKCONTROL_H
#define MSDC_JOYSTICKCONTROL_H

#include <cmath>
#include <iostream>
#include <vector>
#include <unistd.h>
#include "wiringPi.h"
#include "Joystick.hpp"
#include "Utilities.h"

using namespace std;

struct Button
{
    bool is_pressed = false;
};

struct Rocker
{
    int max_value = 32767;

    // cartesian form
    int x_value = 0;
    int y_value = 0;

    // polar form
    double get_angle() const;
    double get_distance() const;

    // percentage
    double get_percent_x() const;
    double get_percent_y() const;
    double get_percent_distance() const;
};

class JoystickControl
{
public:
    JoystickControl();
    void sample();

    bool toggle_exit = false;

    Button B_X, B_Y, B_A, B_B, B_LB, B_RB, B_LS, B_RS, B_Up, B_Down, B_Left, B_Right, B_Menu;
    Rocker R_LT, R_RT, R_LS, R_RS;

    bool update = false;

private:
    inline void parse_event();
    inline void setup_joystick();

    Joystick joystick;
    JoystickEvent event{};

    Button B_Nil;   // meaningless, just a placeholder
    vector<Button *> button_array{&B_A, &B_B, &B_Nil, &B_X, &B_Y, &B_Nil,
                                  &B_LB, &B_RB, &B_Nil, &B_Nil, &B_Nil,
                                  &B_Menu, &B_Nil, &B_LS, &B_RS};
};


#endif //MSDC_JOYSTICKCONTROL_H
