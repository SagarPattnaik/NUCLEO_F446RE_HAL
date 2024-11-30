/*
 * uart.c
 *
 *  Created on: Nov 30, 2024
 *      Author: LENOVO
 */

#include "stm32f4xx_hal.h"

/* Peripheral Initializations */
UART_HandleTypeDef huart2;

int __io_putchar(int ch)
{
	HAL_UART_Transmit(&huart2,(uint8_t*)&ch,1,10);
	return ch;
}

void USART2_Init()
{
 
    /* BTN = PC13, BUS = AHB1EN bit0 */
    /* LED = PA5,  BUS = AHB1EN bit2 */

    GPIO_InitTypeDef GPIO_InitStruct = {0};
    /* Use PA2 for USART2_Tx and PA3 for USART2_Rx */
    __HAL_RCC_GPIOA_CLK_ENABLE();
    /* Enable USART module */
    __HAL_RCC_USART2_CLK_ENABLE();
    /* Configure GPIO pins for USART2 alternate functionality AF7 */
    GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(GPIOA,&GPIO_InitStruct);
  
    /* USART2 Initialization */
	huart2.Instance = USART2;
	huart2.Init.BaudRate = 115200;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.StopBits = UART_STOPBITS_1;
	huart2.Init.Parity = UART_PARITY_NONE;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart2.Init.Mode = UART_MODE_TX_RX;
	if ( HAL_UART_Init(&huart2) != HAL_OK )
	{
		//There is a problem
        while(1);
	}
}