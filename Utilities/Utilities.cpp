//
// Created by cui on 2021/11/7.
//

#include "Utilities.h"

void Utilities::init()
{
    signal(SIGINT, stop_progress);
    signal(SIGILL, stop_progress);
    signal(SIGABRT, stop_progress);
    signal(SIGFPE, stop_progress);
    signal(SIGSEGV, stop_progress);
    signal(SIGTERM, stop_progress);
    signal(SIGKILL, stop_progress);
    signal(SIGQUIT, stop_progress);

    setup_gpio();
}

void Utilities::stop_progress(int sign)
{
    reset_gpio(sign);
    cout << "\033[1;32mStopping progress due to sign \033[1;36m" << sign << "\033[0m" << endl;
    exit(0);
}

void Utilities::setup_gpio()
{
    if (wiringPiSetup() == -1)
        exit(1);
    reset_gpio(1);
}

/**
 * @brief reset gpio by signal
 *
 * @param sign 0->normal_exit, 1->reset_after_setup, 2->SIGINT, 100->lost_connection, others->sys_signs
 */
void Utilities::reset_gpio(int sign)
{
    int *p = (int*)(&pinSet);
    constexpr int count = int(sizeof(pinSet) / sizeof(int));
    for (int i = 0; i < count; i++)
    {
        pinMode(*p++, INPUT);
    }
    cout << "\nGPIO reset due to sign: " << sign << endl;
}