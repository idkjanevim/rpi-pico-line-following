#pragma once

#include "../callbacks/callbacks.h"

#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/pwm.h"
#include "hardware/irq.h"

#define LEFT_LED 15
#define RIGHT_LED 14

#define RIGHT_SENSOR 16
#define LEFT_SENSOR 17

#define M1I1 18
#define M1I2 19
#define M2I1 20
#define M2I2 21

#define M1SPEED 26
#define M2SPEED 27


void setup();
