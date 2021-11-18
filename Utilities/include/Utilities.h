//
// Created by cui on 2021/11/7.
//

#ifndef MSDC_UTILITIES_H
#define MSDC_UTILITIES_H

#include <csignal>
#include <iostream>
#include "wiringPi.h"
#include "Joystick.hpp"

using namespace std;

struct PinSet
{
    int w_lf_1 = 23; // wheel left front
    int w_lf_2 = 24;
    int w_rf_1 = 2;
    int w_rf_2 = 3;
    int w_lr_1 = 21;
    int w_lr_2 = 22;
    int w_rr_1 = 7;
    int w_rr_2 = 0;

    int a_up_1   = 26;
    int a_up_2   = 27;
    int a_down_1 = 28;
    int a_down_2 = 29;
} static pinSet;

class Utilities
{
public:
    static void init();
    static void setup_gpio();
    static void reset_gpio(int sign);
    static void stop_progress(int sign);
};


#endif //MSDC_UTILITIES_H
