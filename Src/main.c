/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "stm32f4xx_hal.h"
#include "uart.h"
#include "adc.h"

ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;
uint32_t  sensor_value[2];

int main()
{
  HAL_Init();
  //WWDG_Disable();
  USART2_Init();
  adc_multichannel_dma_init();
  HAL_ADC_Start_DMA(&hadc1,(uint32_t *)sensor_value,2);

  /* Loop forever */
	while(1)
  {
	  printf("Sensor 1 data :  %d \n\r",(int)sensor_value[0]);
	  printf("Sensor 2 data :  %d \n\r",(int)sensor_value[1]);
    HAL_Delay(100);
  }
}

void SysTick_Handler()
{
  HAL_IncTick();
}
