#include "motor.h"
#include "tim.h"
MOTOR motor[2];

int cnt = 0;
void run(float vel){
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET); //AIN2
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET); //AIN1

    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_SET); //B2
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); //B1

    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 2000+vel);//zuo
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 2000-vel);//you
}

void car_stop(){
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 0);
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET); //AIN2
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET); //AIN1

    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_RESET); //B2
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); //B1
    for (int i ;i<1000;i++);
}

void Set_motor(int16_t duty , int lunzi) // 设置占空比-duty=ARR
{
    if (lunzi == 0)//左
    {
        if (duty > 0)
        {
           HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET);
           HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
           if (duty > 999)  duty = 999;


        }

        else    
        {
           HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
           HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET);
           duty = -duty;
           if (duty > 999)  duty = 999;


        }
         __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, duty );
    }
    if (lunzi  == 1)//右
    {
        if (duty > 0)
        {
            HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
            if (duty > 999)  duty = 999;
        }
        if (duty < 0)
        {
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_RESET);
            duty = -duty;
            if (duty > 999)  duty = 999;

            
        }
        __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_2, duty );

    }
}

// // int getTIMx_DetaCnt(TIM_HandleTypeDef *htim)
// // {
// //     // int cnt;
// //     cnt = htim->Instance->CNT - 0x7FFF;
// //     htim->Instance->CNT = 0x7FFF;
// //     return cnt;
// // }
// void Get_Motor_duty(double *vel, TIM_HandleTypeDef *htim)
// {
//     *vel = (double)((int)(htim->Instance->CNT - 0x7FFF)) / 1560 / 0.1; // r/s
//     htim->Instance->CNT = 0x7FFF;
// } // 得到MOTOR速度

// void Get_Motor_Speed()
// {
//     motor[0].vel=(double)((int)(htim1.Instance->CNT - 0x7FFF)) / 1560 / 0.1; // r/s
//     //motor[1].vel=(double)((int)(htim2.Instance->CNT - 0x7FFF)) / 1560 / 0.1;
//     htim1.Instance->CNT = 0x7FFF;
//     // cnt 65535
//     //  1560
// } // 得到MOTOR速度