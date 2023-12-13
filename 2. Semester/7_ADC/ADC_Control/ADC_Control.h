/*
 * ADC_Control.h
 *
 *  Created on: 13.12.2023
 *      Author: cosmo
 */

#ifndef ADC_CONTROL_ADC_CONTROL_H_
#define ADC_CONTROL_ADC_CONTROL_H_

#include <msp430.h>
#include "stdint.h"


void initADC();
uint16_t readExternalInput();

#endif /* ADC_CONTROL_ADC_CONTROL_H_ */
