/*
 * ADC_Control.h
 *
 *  Created on: 13.12.2023
 *      Author: cosmo
 */

#ifndef ADC_CONTROL_ADC_CONTROL_H_
#define ADC_CONTROL_ADC_CONTROL_H_

#define CALADC12_20V_30C  *((unsigned int *)0x1A1E)   // device specific datasheet s.113
#define CALADC12_20V_85C  *((unsigned int *)0x1A20)

#include <msp430.h>
#include "stdint.h"

typedef struct adc_values {
    uint16_t ext;
    uint16_t temp;
    uint16_t vbat;
} adc_values_t;

typedef enum switch_state {
    closed = 0,
    open = 1
} switch_state_t;


void initADC();
uint16_t readExternalInput();
uint16_t readTemp();
uint16_t readAVCC();
void internalSwitchControl(switch_state_t state);

#endif /* ADC_CONTROL_ADC_CONTROL_H_ */
