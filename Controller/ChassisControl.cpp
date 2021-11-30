//
// Created by cui on 2021/11/7.
//

#include "Controller.h"

ChassisControl::ChassisControl()
{ this->setPin(); }

void ChassisControl::control(JoystickControl &js_controller)
{
    bool spin_lock = false;
    int speed_spin = int(js_controller.R_LS.get_percent_x());
    if (js_controller.R_LS.x_value < -1000)
    {
        this->spin_left(speed_spin);
//        cout << "speed_spin: " << speed_spin << endl;
        spin_lock = true;
    } else if (js_controller.R_LS.x_value > 1000)
    {
        this->spin_right(speed_spin);
//        cout << "speed_spin: " << speed_spin << endl;
        spin_lock = true;
    }

    if (spin_lock)
        return;

    double angle = js_controller.R_RS.get_angle();
    if (fabs(angle) > 135)
    {
        int speed_left = int(js_controller.R_RS.get_percent_x());
//        cout << "speed_left: " << speed_left << endl;
        this->go_right(speed_left);

    } else if (fabs(angle) < 45)
    {
        int speed_right = int(js_controller.R_RS.get_percent_x());
//        cout << "speed_right: " << speed_right << endl;
        this->go_left(speed_right);
    } else
    {
        int speed_forw_backw = int(js_controller.R_RS.get_percent_y());
//        cout << "speed_forw_backw: " << speed_forw_backw << endl;
        if (angle > 0)
            this->go_forward(speed_forw_backw);
        else
            this->go_backward(speed_forw_backw);
    }
}

void ChassisControl::go_forward(int speed)
{
    left_front_wheel.set_forward(speed);
    left_rear_wheel.set_forward(speed);
    right_front_wheel.set_forward(speed);
    right_rear_wheel.set_forward(speed);
}

void ChassisControl::go_backward(int speed)
{
    left_front_wheel.set_backward(speed);
    left_rear_wheel.set_backward(speed);
    right_front_wheel.set_backward(speed);
    right_rear_wheel.set_backward(speed);
}

void ChassisControl::go_left(int speed)
{
    left_front_wheel.set_forward(speed);
    left_rear_wheel.set_backward(speed);
    right_front_wheel.set_backward(speed);
    right_rear_wheel.set_forward(speed);
}

void ChassisControl::go_right(int speed)
{
    left_front_wheel.set_backward(speed);
    left_rear_wheel.set_forward(speed);
    right_front_wheel.set_forward(speed);
    right_rear_wheel.set_backward(speed);
}

void ChassisControl::spin_left(int speed)
{
    left_front_wheel.set_backward(speed);
    left_rear_wheel.set_backward(speed);
    right_front_wheel.set_forward(speed);
    right_rear_wheel.set_forward(speed);
}

void ChassisControl::spin_right(int speed)
{
    left_front_wheel.set_forward(speed);
    left_rear_wheel.set_forward(speed);
    right_front_wheel.set_backward(speed);
    right_rear_wheel.set_backward(speed);
}

void ChassisControl::setPin()
{
    left_front_wheel.init(pinSet.w_lf_1, pinSet.w_lf_2);
    right_front_wheel.init(pinSet.w_rf_1, pinSet.w_rf_2);
    left_rear_wheel.init(pinSet.w_lr_1, pinSet.w_lr_2);
    right_rear_wheel.init(pinSet.w_rr_1, pinSet.w_rr_2);
}
