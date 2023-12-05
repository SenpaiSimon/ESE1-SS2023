/*
 * EPaper_Control.h
 *
 *  Created on: 29.11.2023
 *      Author: cosmo
 */

#ifndef EPAPER_CONTROL_EPAPER_CONTROL_H_
#define EPAPER_CONTROL_EPAPER_CONTROL_H_

#include <msp430.h>
#include "segments.h"

#define CYCYLES_PER_MS 1000
#define DEFAULT_DELAY 250000
#define WAIT_MS(MS) (CYCYLES_PER_MS * MS)

#define TopE_high    P1OUT &= ~BIT1; P1OUT &= ~BIT2        /* T6 off, T7 on*/
#define TopE_low    P1OUT |= BIT2; P1OUT |= BIT1        /* T7 off, T6 on*/
#define TopE_Tris    P1OUT &= ~BIT1; P1OUT |= BIT2        /* T6 off, T7 off*/

void initEpaper();

void epaperClear();

void epaperShow();



#endif /* EPAPER_CONTROL_EPAPER_CONTROL_H_ */
