/*
 * gpio.c
 *
 *  Created on: Nov 30, 2024
 *      Author: LENOVO
 */

#include "stm32f4xx_hal.h"

GPIO_InitTypeDef GPIO_InitStruct = {0};

void LED_Init()
{
  /* 1. Configure PA5 as output pin */
    __HAL_RCC_GPIOA_CLK_ENABLE();


    GPIO_InitStruct.Pin = GPIO_PIN_5;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL; 
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct); 
}

void Button_Init()
{
  /* 2. Configure PC13 as input pin */
    __HAL_RCC_GPIOC_CLK_ENABLE();

    GPIO_InitStruct.Pin = GPIO_PIN_13;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL; 
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct); 
}
