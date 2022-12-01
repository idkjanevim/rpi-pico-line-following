#include "callbacks.h"


void sensor_callback(uint gpio)
{
    if(gpio == LEFT_SENSOR)
    {
        if(!gpio_get(LEFT_SENSOR))
        {

        }
        else
        {
            RIGHT_MOTOR_SPEED = 65535;
            LEFT_MOTOR_SPEED = 0;
            gpio_put(LEFT_LED, 0);
            gpio_put(RIGHT_LED, 1);
        }
    }
    else
    {
        if(!gpio_get(RIGHT_SENSOR))
        {

        }
        else
        {
            LEFT_MOTOR_SPEED = 65535;
            RIGHT_MOTOR_SPEED = 0;
            gpio_put(RIGHT_LED, 0);
            gpio_put(LEFT_LED, 1);
        }
    }
}

void button_callback(uint gpio)
{
    if(!gpio_get(BUTTON))
    {
        running = true; 
    }
}
