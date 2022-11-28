#pragma once

#include <iostream>

#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define LEFT_LED 15
#define RIGHT_LED 14

#define RIGHT_SENSOR 16
#define LEFT_SENSOR 17

#define M1SPEED 27
#define M2SPEED 26

extern int RIGHT_MOTOR_SPEED;
extern int LEFT_MOTOR_SPEED;

void sensor_callback(uint gpio);
