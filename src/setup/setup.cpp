#include "setup.h"

int RIGHT_MOTOR_SPEED = 0;
int LEFT_MOTOR_SPEED = 0;

template <size_t N>
void setup_pins(int (&pins)[N], bool mode, bool sensor) {
    for (int pin : pins)
    {
        gpio_init(pin);
        gpio_set_dir((uint)pins, mode);
        if(sensor)
        {
            gpio_pull_up(pin);
        }
    }
}

void setup()
{
    //LEDS
    //gpio_init(LEFT_LED);
    //gpio_set_dir(LEFT_LED, GPIO_OUT);
    //gpio_init(RIGHT_LED);
    //gpio_set_dir(RIGHT_LED, GPIO_OUT);
    int led_pins[] = {LEFT_LED, RIGHT_LED};
    setup_pins(led_pins, GPIO_OUT, 0);

    //SENSORS
    //gpio_init(RIGHT_SENSOR);
    //gpio_set_dir(RIGHT_SENSOR, GPIO_IN);
    //gpio_pull_up(RIGHT_SENSOR);
    //gpio_init(LEFT_SENSOR);
    //gpio_set_dir(LEFT_SENSOR, GPIO_IN);
    //gpio_pull_up(LEFT_SENSOR);
    int sensor_pins[] = {RIGHT_SENSOR, LEFT_SENSOR};
    setup_pins(sensor_pins, GPIO_IN, 1);

    //MOTOR CONTROL
    //gpio_init(M1I1);
    //gpio_init(M1I2);
    //gpio_init(M2I1);
    //gpio_init(M2I2);
    //gpio_set_dir(M1I1, GPIO_OUT);
    //gpio_set_dir(M1I2, GPIO_OUT);
    //gpio_set_dir(M2I1, GPIO_OUT);
    //gpio_set_dir(M2I2, GPIO_OUT);
    int motor_control_pins[] = {M1I1, M1I2, M2I1, M2I2};
    setup_pins(motor_control_pins, GPIO_OUT, 0);

    //MOTOR SPEED CONTROL
    //gpio_init(M1SPEED);
    //gpio_init(M2SPEED);
    //gpio_set_dir(M1SPEED, GPIO_OUT);
    //gpio_set_dir(M2SPEED, GPIO_OUT);
    int motor_speed_control_pins[] = {M1SPEED, M2SPEED};
    setup_pins(motor_speed_control_pins, GPIO_OUT, 0); 

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
    gpio_put(M1I1, 0);
    gpio_put(M1I2, 1);
    gpio_put(M2I1, 0);
    gpio_put(M2I2, 1);

    
    stdio_init_all();
}