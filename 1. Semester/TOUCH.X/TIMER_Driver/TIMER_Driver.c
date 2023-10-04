#include "TIMER_Driver.h"


// prescaler 0b11 -> 256, 0b10 -> 64, 0b01 -> 8, 0b00 -> 1
uint8_t findCorrectPrescaler(uint32_t *reloadValue) {
    unsigned int maxValueOfReloadReg = 0xFFFF;
    if(*reloadValue < maxValueOfReloadReg) { // it fits
        return 0b00; // prescaler 0
    }

    *reloadValue /= 8; // now we try prescaler of 8
    if(*reloadValue < maxValueOfReloadReg) { // it fits
        return 0b01; // prescaler 8
    }

    *reloadValue /= 8; // now we try prescaler of 64
    if(*reloadValue < maxValueOfReloadReg) { // it fits
        return 0b10; // prescaler 64
    }

    *reloadValue /= 4; // now we only have prescaler of 256 left
    return 0b11; // prescaler 256
}


void initTimer4(uint32_t chipFreq, uint32_t desiredFreq, bool isrEnable) {
    T4CONbits.T45 = 0;

    uint32_t value = chipFreq / desiredFreq;

    T4CONbits.TCKPS = findCorrectPrescaler(&value);
    PR4 = value;

    // enable interrupts on this timer
    _T4IE = isrEnable ? 1 : 0; 
}

void startStopTimer4(bool start) {
    T4CONbits.TON = start ? 1 : 0;
}


void initTimer2(uint32_t chipFreq, uint32_t desiredFreq, bool isrEnable) {
    T2CONbits.T32 = 0;

    uint32_t value = chipFreq / desiredFreq;

    T2CONbits.TCKPS = findCorrectPrescaler(&value);
    PR2 = value;

    // enable interrupts on this timer
    _T2IE = isrEnable ? 1 : 0; 
}

void startStopTimer2(bool start) {
    T2CONbits.TON = start ? 1 : 0;
}


void initTimer1(uint32_t chipFreq, uint32_t desiredFreq, bool isrEnable) {
    uint32_t value = chipFreq / desiredFreq;

    T1CONbits.TCKPS = findCorrectPrescaler(&value);
    PR1 = value;

    // enable interrupts on this timer
    _T1IE = isrEnable ? 1 : 0; 
}

void startStopTimer1(bool start) {
    T1CONbits.TON = start ? 1 : 0;
}