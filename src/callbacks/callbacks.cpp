#include "callbacks.h"


void sensor_callback(uint gpio)
{
    if(gpio == LEFT_SENSOR)
    {
        if(!gpio_get(LEFT_SENSOR))
        {
            LEFT_MOTOR_SPEED = 65535;
            gpio_put(LEFT_LED, 1);
            std::cout << "LEFT ON" << std::endl;
        }
        else
        {
            LEFT_MOTOR_SPEED = 0;
            gpio_put(LEFT_LED, 0);
            std::cout << "LEFT OFF" << std::endl;
        }
    }
    else
    {
        if(!gpio_get(RIGHT_SENSOR))
        {
            RIGHT_MOTOR_SPEED = 65535;
            gpio_put(RIGHT_LED, 1);
            std::cout << "RIGHT ON" << std::endl;
        }
        else
        {
            RIGHT_MOTOR_SPEED = 0;
            gpio_put(RIGHT_LED, 0);
            std::cout << "RIGHT OFF" << std::endl;
        }
    }
}
