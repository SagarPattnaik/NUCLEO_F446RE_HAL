/*
 * gpio.h
 *
 *  Created on: Nov 30, 2024
 *      Author: LENOVO
 */

#ifndef GPIO_H_
#define GPIO_H_

void LED_Init();
void Button_Init();

#define BTN_PORT GPIOC
#define BTN_PIN GPIO_PIN_13

#define LED_PORT GPIOA
#define LED_PIN GPIO_PIN_5

uint8_t button_state = 0;


#endif /* GPIO_H_ */
