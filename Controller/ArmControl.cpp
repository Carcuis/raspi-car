//
// Created by cui on 2021/11/29.
//

#include "Controller.h"

ArmControl::ArmControl()
{ this->setPin(); }

void ArmControl::control(JoystickControl &js_controller)
{
    // up
    up_forward = !js_controller.B_LB.is_pressed;

    if (js_controller.R_LT.y_value > 1000)
    {
        if (up_forward)
            up_join_motor.set_forward(-1);
        else
            up_join_motor.set_backward(-1);
    } else
    {
        up_join_motor.stop();
    }

    // down
    down_forward = !js_controller.B_RB.is_pressed;

    if (js_controller.R_RT.y_value > 1000)
    {
        if (down_forward)
            down_join_motor.set_forward(-1);
        else
            down_join_motor.set_backward(-1);
    } else
    {
        down_join_motor.stop();
    }
}

void ArmControl::setPin()
{
    up_join_motor.init(pinSet.a_up_1, pinSet.a_up_2);
    down_join_motor.init(pinSet.a_down_1, pinSet.a_down_2);
}
