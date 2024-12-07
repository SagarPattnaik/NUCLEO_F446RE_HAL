/*
 * adc.h
 *
 *  Created on: Dec 1, 2024
 *      Author: LENOVO
 */

#ifndef ADC_H_
#define ADC_H_

#include "stm32f4xx_hal.h"

extern ADC_HandleTypeDef hadc1;
extern uint32_t adc_read(void);
extern void adc_start(void);
extern void adc_continous_conv_init(void);
extern void adc_single_conv_init(void);
extern void adc_interrupt_init(void);
extern void adc_dma_init(void);

#endif /* ADC_H_ */
