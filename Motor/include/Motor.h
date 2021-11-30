//
// Created by cui on 2021/11/7.
//

#ifndef MSDC_MOTOR_H
#define MSDC_MOTOR_H

#include "wiringPi.h"
#include "softPwm.h"

class Motor
{
public:
    void init(int _pin_1, int _pin_2);

    void set_forward(int speed) const;
    void set_backward(int speed) const;
    void stop() const;

//    void set_soft_pwm_speed(int value) const;

private:
    int pin_1 = 0, pin_2 = 0;
};

#endif //MSDC_MOTOR_H