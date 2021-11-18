//
// Created by cui on 2021/11/7.
//

#include "Controller.h"

void ChassisControl::control(JoystickControl &js_controller)
{
    setPin();

//    int num = int((fabs(R_RS.y_value/R_RS.max_value)) * 1024);
//    num /= 3;
//    num += 710;

    int num = int((fabs(js_controller.R_RT.y_value + js_controller.R_RT.max_value)/js_controller.R_RT.max_value) * 50);
    cout << "num: " << num << endl;
    cout << js_controller.R_RT.y_value << endl;
    left_front_wheel.set_soft_pwm_speed(num);
    left_rear_wheel.set_soft_pwm_speed(num);
    right_front_wheel.set_soft_pwm_speed(num);
    right_rear_wheel.set_soft_pwm_speed(num);

}

void ChassisControl::go_forward()
{

}

void ChassisControl::go_backward()
{

}

void ChassisControl::spin_left()
{

}

void ChassisControl::spin_right()
{

}

void ChassisControl::setPin()
{
    left_front_wheel.init(pinSet.w_lf_1, pinSet.w_lf_2);
    right_front_wheel.init(pinSet.w_rf_1, pinSet.w_rf_2);
    left_rear_wheel.init(pinSet.w_lr_1, pinSet.w_lr_2);
    right_rear_wheel.init(pinSet.w_rr_1, pinSet.w_rr_2);
}

void ArmControl::control(JoystickControl &js_controller)
{
    setPin();

//    if (js_controller.R_LS.y_value > 0)
//    {
//        left_front_wheel.set_forward();
////        left_rear_wheel.set_forward();
//    } else if (js_controller.R_LS.y_value < 0)
//    {
//        left_front_wheel.set_backward();
////        left_rear_wheel.set_backward();
//    } else
//    {
//        left_front_wheel.stop();
////        left_rear_wheel.stop();
//    }
//
//    if (js_controller.R_RS.y_value > 0)
//    {
////        left_front_wheel.set_forward();
//        left_rear_wheel.set_forward();
//    } else if (js_controller.R_RS.y_value < 0)
//    {
////        left_front_wheel.set_backward();
//        left_rear_wheel.set_backward();
//    } else
//    {
////        left_front_wheel.stop();
//        left_rear_wheel.stop();
//    }
}

void ArmControl::setPin()
{
    up_join_motor.init(pinSet.a_up_1, pinSet.a_up_2);
    down_join_motor.init(pinSet.a_down_1, pinSet.a_down_2);
}
