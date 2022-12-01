#include "setup.h"

int RIGHT_MOTOR_SPEED = 0;
int LEFT_MOTOR_SPEED = 0;

void setup()
{
    //LEDS
    gpio_init(LEFT_LED);
    gpio_set_dir(LEFT_LED, GPIO_OUT);
    gpio_init(RIGHT_LED);
    gpio_set_dir(RIGHT_LED, GPIO_OUT);

    //SENSORS
    gpio_init(RIGHT_SENSOR);
    gpio_set_dir(RIGHT_SENSOR, GPIO_IN);
    gpio_pull_up(RIGHT_SENSOR);
    gpio_init(LEFT_SENSOR);
    gpio_set_dir(LEFT_SENSOR, GPIO_IN);
    gpio_pull_up(LEFT_SENSOR);

    //MOTOR CONTROL
    gpio_init(M1I1);
    gpio_init(M1I2);
    gpio_init(M2I1);
    gpio_init(M2I2);
    gpio_set_dir(M1I1, GPIO_OUT);
    gpio_set_dir(M1I2, GPIO_OUT);
    gpio_set_dir(M2I1, GPIO_OUT);
    gpio_set_dir(M2I2, GPIO_OUT);

    //MOTOR SPEED CONTROL
    gpio_init(M1SPEED);
    gpio_init(M2SPEED);
    gpio_set_dir(M1SPEED, GPIO_OUT);
    gpio_set_dir(M2SPEED, GPIO_OUT);

    //SETTING UP PWM FOR MOTORS

    gpio_set_function(M1SPEED, GPIO_FUNC_PWM);
    gpio_set_function(M2SPEED, GPIO_FUNC_PWM);

    uint slice_r = pwm_gpio_to_slice_num(M1SPEED);
    uint slice_l = pwm_gpio_to_slice_num(M2SPEED);

    //SETTING UP PWM CONFIG
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 4.f);
    
    //STARTING PWM
    pwm_init(slice_r, &config, true);
    pwm_init(slice_l, &config, true);

    //INITIAL MOTOR SPEEDS
    LEFT_MOTOR_SPEED = 65535;
    RIGHT_MOTOR_SPEED = 65535;

    //INITIAL LED STATE
    gpio_put(LEFT_LED, 1);
    gpio_put(RIGHT_LED, 1);

    //SETTING UP SENSOR IRQ
    gpio_set_irq_enabled_with_callback(RIGHT_SENSOR, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true, (gpio_irq_callback_t)&sensor_callback);
    gpio_set_irq_enabled_with_callback(LEFT_SENSOR, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true, (gpio_irq_callback_t)&sensor_callback);

    //TURNING ON MOTORS
    gpio_put(M1I1, 1);
    gpio_put(M1I2, 0);
    gpio_put(M2I1, 1);
    gpio_put(M2I2, 0);

    
    stdio_init_all();
}