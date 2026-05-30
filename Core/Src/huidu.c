#include "huidu.h"

double distance;
int x[8];
l=0;

int Gary_Sensor_Read_Digital(void)
{ static int flag = 0;
  static int sum = 0;

    x[0] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6);
    x[1] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8);
    x[2] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_9);
    x[3] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10);
    x[4] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3);
    x[5] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2);
    x[6] = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_9);
    x[7] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7);

    sum = (8 - (x[0] + x[1] + x[2] + x[3] + x[4] + x[5] + x[6] + x[7]));
    distance = (float)(x[0] * 4 + x[1] * 3 + x[2] * 2 + x[3] * 1 + x[4] * (-1) + x[5] * (-2) + x[6] * (-3) + x[7] * (-4));
    return distance;
}
  