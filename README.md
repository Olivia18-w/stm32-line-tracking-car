# 8-Channel Grayscale Sensor Line-Tracking Car (STM32 HAL Library)

## Project Overview
This project is developed based on the STM32 microcontroller using the HAL library. It uses an 8-channel grayscale sensor module to realize automatic black line tracking for intelligent cars.

## Hardware Components
- STM32 Microcontroller: STM32F427VGT6
- 8-channel grayscale sensor module
- TB6612 module
- 12V lithium battery power supply
- DC motors and car chassis

## Software Environment
- VSCode
- STM32CubeMX

## Main Functions
- Detect black line trajectories on the ground
- Automatically control the car to drive straight and turn left or right

## Code Introduction
Core
- Src
  - `main.c`: Program entry and main loop logic
  - `gpio.c`: GPIO initialization configuration
  - `tim.c`: Timer and PWM configuration for motor speed control
  - `motor.c`: TB6612 motor driver functions (speed regulation)
  - `huidu.c`: Data reading and processing for 8-channel grayscale sensor
  - `pid.c`: Implementation of PID line-tracking control algorithm
  - `stm32f4xx_hal_msp.c` / `stm32f4xx_it.c`: HAL library initialization and interrupt service functions
  - `system_stm32f4xx.c`: System clock configuration

- Inc
  - Contains the corresponding `.h` header file declarations for all `.c` files
