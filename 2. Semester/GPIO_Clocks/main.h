/*
 * main.h
 *
 *  Created on: 04.10.2023
 *      Author: cosmo
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <msp430.h>
#include "GPIO_Control/GPIO_Control.h"

/*!
 * @brief Collection of all init functions, should always be run first
 */
void initMSP();

/*!
 * Main Entry-Point of the program
 */
int main();


#endif /* MAIN_H_ */
