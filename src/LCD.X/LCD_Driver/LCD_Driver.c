#include "LCD_Driver.h"

DIGIT_t digit1, digit2, digit3, digit4;
uint8_t numberLookup[] = {_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _A, _B, _C, _D, _E, _F};

void updateLCD() {
    // digit 1
    A1 = digit1.bits.a;
    B1 = digit1.bits.b;
    C1 = digit1.bits.c;
    D1 = digit1.bits.d;
    E1 = digit1.bits.e;
    F1 = digit1.bits.f;
    G1 = digit1.bits.g;

    // digit 2
    A2 = digit2.bits.a;
    B2 = digit2.bits.b;
    C2 = digit2.bits.c;
    D2 = digit2.bits.d;
    E2 = digit2.bits.e;
    F2 = digit2.bits.f;
    G2 = digit2.bits.g;

    // digit 3
    A3 = digit3.bits.a;
    B3 = digit3.bits.b;
    C3 = digit3.bits.c;
    D3 = digit3.bits.d;
    E3 = digit3.bits.e;
    F3 = digit3.bits.f;
    G3 = digit3.bits.g;

    // digit 4
    A4 = digit4.bits.a;
    B4 = digit4.bits.b;
    C4 = digit4.bits.c;
    D4 = digit4.bits.d;
    E4 = digit4.bits.e;
    F4 = digit4.bits.f;
    G4 = digit4.bits.g;
}

void setDigits(uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4) {
    digit1.value = numberLookup[d1];
    digit2.value = numberLookup[d2];
    digit3.value = numberLookup[d3];
    digit4.value = numberLookup[d4];
    updateLCD();
}

void setPoints(bool d1, bool d2, bool d3, bool col) {
    DP1 = d1;
    DP2 = d2;
    DP3 = d3;
    COLON = col;
}

void setLowerScript(bool bat, bool sp1, bool sp2, bool sp3, bool sp4) {
    BAT = bat;
    SP1 = sp1;
    SP2 = sp2;
    SP3 = sp3;
    SP4 = sp4;
}

void setSigns(bool up, bool down, bool minus) {
    UP_ARR = up;
    DOWN_ARR = down;
    SIGN = minus;
}

void setUnits(UNITS_t *units) {
    M_BAR = units->mbar;
    BAR = units->bar | units->mbar;
    TORR = units->torr;
    PA = units->pa;
    PERCENT = units->percent;
    
    M_SEC = units->m_s | units->m;
    SEP_SEC = units->m_s;
    SEC = units->m_s | units->sec;

    CELCIUS = units->celcius;
    FAHRENHEIT = units->fahrenheit;

    L_MIN = units->l_min | units->l;
    SEP_MIN = units->l_min;
    MIN = units->l_min | units->min;
}


