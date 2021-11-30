//
// Created by cui on 2021/11/9.
//

#include "Joystick.hpp"
#include "JoystickControl.h"

JoystickControl::JoystickControl()
{
    this->setup_joystick();
}

void JoystickControl::setup_joystick()
{
    if (!this->joystick.isFound())
    {
        cout << "\033[1;33m[Warning] Joystick not found.\033[0m" << endl;
        exit(1);
    }
}

void JoystickControl::sample()
{
    usleep(1000);
    if (!joystick.sample(&event))
    {
//        if (!this->joystick.isFound())
//        {
//            cout << "\033[1;31m[Warning] Joystick lost connection!\033[0m" << endl;
//            Utilities::stop_progress(100);
//        }
        this->update = false;
        return;
    }
    this->update = true;

    this->parse_event();

    if (B_X.is_pressed && B_B.is_pressed)
        this->toggle_exit = true;
}

void JoystickControl::parse_event()
{
    if (event.isButton())
    {
        button_array[uint(event.number)]->is_pressed = event.value == 1;
    } else if (event.isAxis())
    {
        switch (event.number)
        {
            case 0:
                R_LS.x_value = event.value; break;
            case 1:
                R_LS.y_value = - event.value; break;
            case 2:
                R_RS.x_value = event.value; break;
            case 3:
                R_RS.y_value = - event.value; break;
            case 4:
                R_RT.x_value = R_RT.y_value = event.value; break;
            case 5:
                R_LT.x_value = R_LT.y_value = event.value; break;
            case 6:
                if (event.value > 0)
                    B_Right.is_pressed = true;
                else if (event.value < 0)
                    B_Left.is_pressed = true;
                break;
            case 7:
                if (event.value > 0)
                    B_Down.is_pressed = true;
                else if (event.value < 0)
                    B_Up.is_pressed = true;
                break;
        }
    }
}

double Rocker::get_angle() const
{
    return atan2(this->y_value, this->x_value) * 57.3;
}

double Rocker::get_distance() const
{
    return sqrt(pow(this->x_value, 2) + pow(this->y_value, 2));
}

double Rocker::get_percent_x(bool with_sign) const
{
    double percent = fmax(fmin((float)this->x_value / (float)this->max_value * 100, 100), -100);
    return with_sign ? percent : fabs(percent);
}

double Rocker::get_percent_y(bool with_sign) const
{
    double percent = fmax(fmin((float)this->y_value / (float)this->max_value * 100, 100), -100);
    return with_sign ? percent : fabs(percent);
}

double Rocker::get_percent_distance(bool with_sign) const
{
    double percent = fmax(fmin(this->get_distance() / this->max_value * 100, 100), -100);
    return with_sign ? percent : fabs(percent);
}
