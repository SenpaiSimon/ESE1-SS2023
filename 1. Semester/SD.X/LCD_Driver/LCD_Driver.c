#include "LCD_Driver.h"

DIGIT_t digit1, digit2, digit3, digit4;
const uint8_t numberLookup[] = {_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _A, _B, _HC, _D, _E, _F};
LCD_STATE_t *currentState;

LCD_STATE_t* getLCDStorage() {
    return currentState;
}

void initLCD(LCD_STATE_t *stateStorage) {
    // config
    LCDCONbits.LCDEN    = 1; // enbable the driver
    LCDCONbits.CS       = 0b00; // clock is FRC
    LCDCONbits.LMUX     = 0b011; // 1/4 Mux --> COM3 - COM0

    LCDPSbits.WFT       = 0; // waveform A
    LCDPSbits.LP        = 0b0011; // prescaler 1:4

    LCDREFbits.LCDIRE   = 1; // enable reistor ladder
    LCDREFbits.LCDCST   = 0b0; // maximum contrast
    LCDREFbits.LRLBP    = 0b10; // high power mode for mode B
    LCDREFbits.LRLAP    = 0b11; // high power mode for mode A
    LCDREFbits.LRLAT    = 0b011; // 3 clocks A, 13 clocks B

    // select outputs pins enable
    // uC PIN          - PANEL PIN
    LCDSE0bits.SE14 = 1; // pin18
    LCDSE0bits.SE15 = 1; // pin17
    LCDSE1bits.SE16 = 1; // pin16
    LCDSE1bits.SE17 = 1; // pin15
    LCDSE1bits.SE20 = 1; // pin14
    LCDSE1bits.SE21 = 1; // pin13
    LCDSE1bits.SE22 = 1; // pin12
    LCDSE1bits.SE23 = 1; // pin11
    LCDSE1bits.SE24 = 1; // pin10
    LCDSE1bits.SE25 = 1; // pin9
    LCDSE1bits.SE26 = 1; // pin8
    LCDSE1bits.SE27 = 1; // pin7
    LCDSE2bits.SE47 = 1; // pin6
    LCDSE3bits.SE62 = 1; // pin5

    // NOTE
    // PANEL COM - uC COM
    // COM1      - COM3
    // COM2      - COM2
    // COM3      - COM0
    // COM4      - COM1

    currentState = stateStorage;
}

void updateLCD() {
    // update the value with coding
    digit1.value = numberLookup[currentState->digit1];
    digit2.value = numberLookup[currentState->digit2];
    digit3.value = numberLookup[currentState->digit3];
    digit4.value = numberLookup[currentState->digit4];
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

    // dots
    DP1 = currentState->dots.dp1;
    DP2 = currentState->dots.dp2;
    DP3 = currentState->dots.dp3;
    COLON = currentState->dots.col;

    // misc
    BAT = currentState->misc.bat;
    SP1 = currentState->misc.sp1;
    SP2 = currentState->misc.sp2;
    SP3 = currentState->misc.sp3;
    SP4 = currentState->misc.sp4;
    UP_ARR = currentState->misc.upArr;
    DOWN_ARR = currentState->misc.downArr;
    SIGN = currentState->misc.minus;

    // units
    M_BAR = currentState->units.mbar;
    BAR = currentState->units.bar | currentState->units.mbar;
    TORR = currentState->units.torr;
    PA = currentState->units.pa;
    PERCENT = currentState->units.percent;
    
    M_SEC = currentState->units.m_s | currentState->units.m;
    SEP_SEC = currentState->units.m_s;
    SEC = currentState->units.m_s | currentState->units.sec;

    CELCIUS = currentState->units.celcius;
    FAHRENHEIT = currentState->units.fahrenheit;

    L_MIN = currentState->units.l_min | currentState->units.l;
    SEP_MIN = currentState->units.l_min;
    MIN = currentState->units.l_min | currentState->units.min;
}

void setTime(uint32_t secondsPassed) {
    uint32_t localSeconds = secondsPassed;
    uint32_t minutes, hours;

    // extract hours and seconds
    hours = localSeconds / 3600;
    localSeconds -= hours * 3600;
    minutes = localSeconds / 60;

    // convert it to a standalone number
    setNumber((hours * 100) + minutes);
}

void setNumber(uint32_t number) {
    uint32_t localNumber = number;

    currentState->digit1 = localNumber / 1000;
    localNumber -= currentState->digit1 * 1000;

    currentState->digit2 = localNumber / 100;
    localNumber -= currentState->digit2 * 100;

    currentState->digit3 = localNumber / 10;
    localNumber -= currentState->digit3 * 10;

    currentState->digit4 = localNumber;

    setDigits(currentState->digit1, currentState->digit2, currentState->digit3, currentState->digit4);
}

void setDigits(uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4) {
    currentState->digit1 = d1;
    currentState->digit2 = d2;
    currentState->digit3 = d3;
    currentState->digit4 = d4;
    currentState->number = (d1 * 1000) + (d2 * 100) + (d3 * 10) + d4;
    updateLCD();
}

void setPoints(bool d1, bool d2, bool d3, bool col) {
    currentState->dots.dp1 = d1;
    currentState->dots.dp2 = d2;
    currentState->dots.dp3 = d3;
    currentState->dots.col = col;
    updateLCD();
}

void setLowerScript(bool bat, bool sp1, bool sp2, bool sp3, bool sp4) {
    currentState->misc.bat = bat;
    currentState->misc.sp1 = sp1;
    currentState->misc.sp2 = sp2;
    currentState->misc.sp3 = sp3;
    currentState->misc.sp4 = sp4;
    updateLCD();
}

void setSigns(bool up, bool down, bool minus) {
    currentState->misc.upArr = up;
    currentState->misc.downArr = down;
    currentState->misc.minus = minus;
    updateLCD();
}

void setUnits(UNITS_t *units) {
    currentState->units.mbar = units->mbar;
    currentState->units.bar = units->bar;
    currentState->units.torr = units->torr;
    currentState->units.pa = units->pa;
    currentState->units.percent = units->percent;
    currentState->units.m_s = units->m_s;
    currentState->units.m = units->m;
    currentState->units.sec = units->sec;
    currentState->units.celcius = units->celcius;
    currentState->units.fahrenheit = units->fahrenheit;
    currentState->units.l = units->l;
    currentState->units.l_min = units->l_min;
    currentState->units.min = units->min;
    updateLCD();
}

void displayTest(uint8_t state) {
    currentState->digit1 = (state ? 8 : 0);
    currentState->digit2 = (state ? 8 : 0);
    currentState->digit3 = (state ? 8 : 0);
    currentState->digit4 = (state ? 8 : 0);
    currentState->number = (state ? 8888 : 0);

    currentState->dots.dp1 = state;
    currentState->dots.dp2 = state;
    currentState->dots.dp3 = state;
    currentState->dots.col = state;

    currentState->misc.bat = state;
    currentState->misc.downArr = state;
    currentState->misc.minus = state;
    currentState->misc.upArr = state;
    currentState->misc.sp1 = state;
    currentState->misc.sp2 = state;
    currentState->misc.sp3 = state;
    currentState->misc.sp4 = state;

    currentState->units.mbar = state;
    currentState->units.torr = state;
    currentState->units.pa = state;
    currentState->units.percent = state;
    currentState->units.m_s = state;
    currentState->units.celcius = state;
    currentState->units.fahrenheit = state;
    currentState->units.l_min = state;

    updateLCD();
}

