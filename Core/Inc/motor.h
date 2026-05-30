#ifndef __motor_h
#define __motor_h

#include "main.h"
#include "tim.h"
#include "pid.h"

void run(float);
void car_stop();

void Set_motor(int16_t vel,int temp);

typedef struct // motor的元素
{
    double vel;
    uint8_t dir; // 1 zheng 0 fan
    Pid_t pid_vel;
    double target;
} MOTOR;


// extern int cnt;
extern MOTOR motor[2];


#define POSITIVE_0 HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_SET), HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET)
#define NEGATIVE_0 HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_RESET), HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET)
#define POSITIVE_1 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET), HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET)
#define NEGATIVE_1 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET), HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET)
// #define STOP HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0), HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0)
#endif // !__motor_