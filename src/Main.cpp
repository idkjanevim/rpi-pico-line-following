#include <iostream>

#include "setup/setup.h"
#include "callbacks/callbacks.h"

#include "pico/multicore.h"


int main()
{
    setup();
    //RIGHT_MOTOR_SPEED = 65535;
    //LEFT_MOTOR_SPEED = 65535;
    while (1)
    {
        if(running)
        {
            pwm_set_gpio_level(M1SPEED, RIGHT_MOTOR_SPEED);
            pwm_set_gpio_level(M2SPEED, LEFT_MOTOR_SPEED);

            //if(!gpio_get(RIGHT_SENSOR))
            //{
            //
            //}
            //else
            //{
            //    LEFT_MOTOR_SPEED = 65535;
            //    RIGHT_MOTOR_SPEED = 0;
            //    gpio_put(RIGHT_LED, 0);
            //    gpio_put(LEFT_LED, 1);
            //}
            //if(!gpio_get(LEFT_SENSOR))
            //{
            //
            //}
            //else
            //{
            //    RIGHT_MOTOR_SPEED = 65535;
            //    LEFT_MOTOR_SPEED = 0;
            //    gpio_put(LEFT_LED, 0);
            //    gpio_put(RIGHT_LED, 1);
            //}
        }
    }

}
