//
// Created by cui on 2021/11/7.
//

#include "Motor.h"

void Motor::init(int _pin_1, int _pin_2)
{
    this->pin_1 = _pin_1;
    this->pin_2 = _pin_2;

//    pinMode(pin_1, OUTPUT);
//    pinMode(pin_1, PWM_OUTPUT);
    softPwmCreate(_pin_1, 0, 100);
    pinMode(_pin_2, OUTPUT);

    this->stop();
}

void Motor::set_forward() const
{
    digitalWrite(pin_1, HIGH);
    digitalWrite(pin_2, LOW);
}

void Motor::set_backward() const
{
    digitalWrite(pin_1, LOW);
    digitalWrite(pin_2, HIGH);
}

void Motor::stop() const
{
    digitalWrite(pin_1, LOW);
    digitalWrite(pin_2, LOW);
}

void Motor::set_soft_pwm_speed(int value) const
{
//    pwmWrite(pin_1, value);
    softPwmWrite(pin_1, value);
}
