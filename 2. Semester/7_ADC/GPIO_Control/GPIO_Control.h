/*
 * GPIO_Control.h
 *
 *  Created on: 04.10.2023
 *      Author: cosmo
 */

#ifndef GPIO_CONTROL_GPIO_CONTROL_H_
#define GPIO_CONTROL_GPIO_CONTROL_H_

#include <msp430.h>

/*!
 * @brief Place to init all GPIO related things and Functions
 */
void initGPIO();

/*!
 * @brief Disable all GPIOs for LPM
 */
void disableAllGPIO();

#endif /* GPIO_CONTROL_GPIO_CONTROL_H_ */
