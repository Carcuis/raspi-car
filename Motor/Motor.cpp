//
// Created by cui on 2021/11/7.
//

#include "Motor.h"

void Motor::init(int _pin_1, int _pin_2)
{
    this->pin_1 = _pin_1;
    this->pin_2 = _pin_2;

    pinMode(_pin_1, OUTPUT);
    pinMode(_pin_2, OUTPUT);

    this->stop();
}

void Motor::set_forward(int speed) const
{
    pinMode(pin_2, OUTPUT);
    digitalWrite(pin_2, LOW);
    if (speed <= 100 && speed > 0)
    {
        pinMode(pin_1, PWM_OUTPUT);
        softPwmCreate(pin_1, 0, 100);
        softPwmWrite(pin_1, speed);
    } else
    {
        pinMode(pin_1, OUTPUT);
        digitalWrite(pin_1, HIGH);
    }
}

void Motor::set_backward(int speed) const
{
    pinMode(pin_1, OUTPUT);
    digitalWrite(pin_1, LOW);
    if (speed <= 100 && speed > 0)
    {
        pinMode(pin_2, PWM_OUTPUT);
        softPwmCreate(pin_2, 0, 100);
        softPwmWrite(pin_2, speed);
    } else
    {
        pinMode(pin_2, OUTPUT);
        digitalWrite(pin_2, HIGH);
    }
}

void Motor::stop() const
{
    pinMode(pin_1, OUTPUT);
    pinMode(pin_2, OUTPUT);
    digitalWrite(pin_1, LOW);
    digitalWrite(pin_2, LOW);
}
