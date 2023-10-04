/* 
 * File:   LCD_Typedef.h
 * Author: cosmo
 *
 * Created on 6. April 2023, 10:23
 */

#ifndef LCD_TYPEDEF_H
#define	LCD_TYPEDEF_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
#include <stdint.h>

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

typedef struct UNITS {
    bool bar;
    bool mbar;
    bool torr;
    bool pa;
    bool percent;
    bool m_s;
    bool m;
    bool sec;
    bool celcius;
    bool fahrenheit;
    bool l_min;
    bool l;
    bool min;
} UNITS_t;

typedef struct DOTS {
    bool dp1;
    bool dp2;
    bool dp3;
    bool col;
} DOTS_t;

typedef struct MISC {
    bool bat;
    bool sp1;
    bool sp2;
    bool sp3;
    bool sp4;
    bool minus;
    bool upArr;
    bool downArr;
} MISC_t;

typedef struct LCD_SATE {
    uint8_t digit1;
    uint8_t digit2;
    uint8_t digit3;
    uint8_t digit4;
    uint32_t number;
    DOTS_t dots;
    UNITS_t units;
    MISC_t misc;
} LCD_STATE_t;




#ifdef	__cplusplus
}
#endif

#endif	/* LCD_TYPEDEF_H */

