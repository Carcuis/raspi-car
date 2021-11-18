#include <iostream>
#include "JoystickControl.h"
#include "Utilities.h"
#include "Controller.h"

using namespace std;

int main(int argc, char *argv[])
{
    Utilities::init();
    JoystickControl js_controller;
    ChassisControl chassis_controller;
    ArmControl arm_controller;

    while (true)
    {
        js_controller.sample();

        if (js_controller.update)
        {
            chassis_controller.control(js_controller);
            arm_controller.control(js_controller);
        }

        if (js_controller.toggle_exit)
            break;
    }

    Utilities::stop_progress(0);
}
