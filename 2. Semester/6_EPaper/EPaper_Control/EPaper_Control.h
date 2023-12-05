/*
 * EPaper_Control.h
 *
 *  Created on: 29.11.2023
 *      Author: cosmo
 */

#ifndef EPAPER_CONTROL_EPAPER_CONTROL_H_
#define EPAPER_CONTROL_EPAPER_CONTROL_H_

#include <msp430.h>
#include <stdbool.h>
#include <stdint.h>

#define CYCYLES_PER_MS 1000
#define DEFAULT_DELAY 250000
#define WAIT_MS(MS) (CYCYLES_PER_MS * MS)

#define TopE_high    P1OUT &= ~BIT1; P1OUT &= ~BIT2        /* T6 off, T7 on*/
#define TopE_low    P1OUT |= BIT2; P1OUT |= BIT1        /* T7 off, T6 on*/
#define TopE_Tris    P1OUT &= ~BIT1; P1OUT |= BIT2        /* T6 off, T7 off*/

// codierung
#define _0 0x3F
#define _1 0x06
#define _2 0x5B
#define _3 0x4F
#define _4 0x66
#define _5 0x6D
#define _6 0x7D
#define _7 0x07
#define _8 0x7F
#define _9 0x6F
#define _A 0x77
#define _B 0x7C
#define _C 0x39
#define _D 0x5E
#define _E 0x79
#define _F 0x71

typedef struct BITS {
    bool a : 1;
    bool b : 1;
    bool c : 1;
    bool d : 1;
    bool e : 1;
    bool f : 1;
    bool g : 1;
}BITS_t;

typedef union DIGIT {
    BITS_t bits;
    uint8_t value;
}DIGIT_t;

typedef struct DISP_STATE {
    DIGIT_t hundred;
    DIGIT_t tens;
    DIGIT_t ones;
    bool percent;
    bool dp1;
    bool dp2;
} DISP_STATE_t;




void initEpaper(DISP_STATE_t *state);

void epaperClear();

void epaperShow();

void setNumber(uint32_t number);

void setMisc(bool dp1, bool dp2, bool percent);

// bla bla bla bla
void      a1(int x);
void      a3(int x);
void      a5(int x);
void      a7(int x);
void      a9(int x);
void     a11(int x);
void     a13(int x);
void      b1(int x);
void      b3(int x);
void      b5(int x);
void      b7(int x);
void      b9(int x);
void     b11(int x);
void     b13(int x);
void      c1(int x);
void      c3(int x);
void      c5(int x);
void      c7(int x);
void      c9(int x);
void     c11(int x);
void     c13(int x);
void percent(int x);
void     dp1(int x);
void     dp2(int x);

#endif /* EPAPER_CONTROL_EPAPER_CONTROL_H_ */
