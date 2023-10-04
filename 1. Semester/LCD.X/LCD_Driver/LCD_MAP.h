/* 
 * File:   LCD_MAP.h
 * Author: cosmo
 *
 * Created on 6. April 2023, 10:20
 */

#ifndef LCD_MAP_H
#define	LCD_MAP_H

#ifdef	__cplusplus
extern "C" {
#endif

// digits are counter from left to right, so digit 1 is the most left one
// digit 1
#define A1 _S22C3
#define B1 _S22C2
#define C1 _S23C3
#define D1 _S22C0
#define E1 _S23C1
#define F1 _S23C2
#define G1 _S22C1
#define DP1 _S23C0
#define SP1 _S25C1

// digit 2
#define A2 _S20C3
#define B2 _S20C2
#define C2 _S21C3
#define D2 _S20C0
#define E2 _S21C1
#define F2 _S21C2
#define G2 _S20C1
#define DP2 _S21C0
#define SP2 _S25C2

// digit 3
#define A3 _S16C3
#define B3 _S16C2
#define C3 _S17C3
#define D3 _S16C0
#define E3 _S17C1
#define F3 _S17C2
#define G3 _S16C1
#define DP3 _S17C0
#define SP3 _S25C3

// digit 4
#define A4 _S14C3
#define B4 _S14C2
#define C4 _S15C3
#define D4 _S14C0
#define E4 _S15C1
#define F4 _S15C2
#define G4 _S14C1
#define SP4 _S26C2

// signs
#define SIGN _S24C2
#define UP_ARR _S24C3
#define DOWN_ARR _S24C1
#define BAT _S24C0
#define COLON _S26C1

// units
#define BAR _S27C0
#define M_BAR _S62C0
#define TORR _S62C1
#define PA _S47C0
#define PERCENT _S62C2
#define SEC _S62C3
#define M_SEC _S47C1
#define SEP_SEC _S47C2
#define CELCIUS _S27C3
#define FAHRENHEIT _S47C3
#define MIN _S27C2
#define L_MIN _S26C3
#define SEP_MIN _S27C1


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



#ifdef	__cplusplus
}
#endif

#endif	/* LCD_MAP_H */

