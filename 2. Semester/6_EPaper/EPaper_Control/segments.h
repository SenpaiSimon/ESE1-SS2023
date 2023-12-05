/*
 * segments.h
 *
 *  Created on: 05.12.2023
 *      Author: cosmo
 */

#ifndef EPAPER_CONTROL_SEGMENTS_H_
#define EPAPER_CONTROL_SEGMENTS_H_

#include <msp430.h>

#define       a1(x) ({x ? P3OUT |= BIT1 : P3OUT &= ~BIT1})
#define       a3(x) ({x ? P3OUT |= BIT2 : P3OUT &= ~BIT2})
#define       a5(x) ({x ? P3OUT |= BIT3 : P3OUT &= ~BIT3})
#define       a7(x) ({x ? P4OUT |= BIT7 : P4OUT &= ~BIT7})
#define       a9(x) ({x ? P1OUT |= BIT4 : P1OUT &= ~BIT4})
#define      a11(x) ({x ? P1OUT |= BIT5 : P1OUT &= ~BIT5})
#define      a13(x) ({x ? PJOUT |= BIT0 : PJOUT &= ~BIT0})
#define       b1(x) ({x ? PJOUT |= BIT2 : PJOUT &= ~BIT2})
#define       b3(x) ({x ? PJOUT |= BIT3 : PJOUT &= ~BIT3})
#define       b5(x) ({x ? P4OUT |= BIT0 : P4OUT &= ~BIT0})
#define       b7(x) ({x ? P4OUT |= BIT1 : P4OUT &= ~BIT1})
#define       b9(x) ({x ? P2OUT |= BIT0 : P2OUT &= ~BIT0})
#define      b11(x) ({x ? P2OUT |= BIT1 : P2OUT &= ~BIT1})
#define      b13(x) ({x ? P2OUT |= BIT2 : P2OUT &= ~BIT2})
#define       c1(x) ({x ? P3OUT |= BIT5 : P3OUT &= ~BIT5})
#define       c3(x) ({x ? P3OUT |= BIT6 : P3OUT &= ~BIT6})
#define       c5(x) ({x ? P3OUT |= BIT7 : P3OUT &= ~BIT7})
#define       c7(x) ({x ? P1OUT |= BIT6 : P1OUT &= ~BIT6})
#define       c9(x) ({x ? P1OUT |= BIT7 : P1OUT &= ~BIT7})
#define      c11(x) ({x ? P4OUT |= BIT4 : P4OUT &= ~BIT4})
#define      c13(x) ({x ? P4OUT |= BIT5 : P4OUT &= ~BIT5})
#define percent (x) ({x ? P4OUT |= BIT6 : P4OUT &= ~BIT6})


#endif /* EPAPER_CONTROL_SEGMENTS_H_ */
