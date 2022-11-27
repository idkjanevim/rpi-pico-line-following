#include <iostream>

#include "setup/setup.h"
#include "callbacks/callbacks.h"

#include "pico/multicore.h"


int main()
{
    setup();
    
    while (1)
    {
        pwm_set_gpio_level(M1SPEED, RIGHT_MOTOR_SPEED);
        pwm_set_gpio_level(M2SPEED, LEFT_MOTOR_SPEED);
    }

}
