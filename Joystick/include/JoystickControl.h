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
#include "Motor.h"

using namespace std;

struct Button
{
    bool is_pressed = false;
};

struct Rocker
{
    int x_value = 0;
    int y_value = 0;
    int max_value = 32767;
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

    Button B_Nil;
    vector<Button *> button_array{&B_A, &B_B, &B_Nil, &B_X, &B_Y, &B_Nil,
                                  &B_LB, &B_RB, &B_Nil, &B_Nil, &B_Nil,
                                  &B_Menu, &B_Nil, &B_LS, &B_RS};
};


#endif //MSDC_JOYSTICKCONTROL_H
