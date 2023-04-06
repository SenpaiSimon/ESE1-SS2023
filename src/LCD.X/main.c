// Prof. Dr. Artem Ivanov
// HAW Landshut


#include <xc.h> // include processor description
#include "main.h"

// GLOBALS
uint8_t buttonAllow = 1;

UNITS_t lcdUnits = {0};
UNITS_t allLCDUnitsON = {
    .mbar = 1,
    .torr = 1,
    .pa = 1,
    .percent = 1,
    .m_s = 1,
    .celcius = 1,
    .fahrenheit = 1,
    .l_min = 1
};

// ISR
void _ISR _T2Interrupt(void) {
    _T2IF = 0; // reset IR flag

    COLON = !COLON;
}

void _ISR _T4Interrupt(void) {
    _T4IF = 0;
    if(PORTBbits.RB3 && PORTDbits.RD8) {
        buttonAllow = 1;
    }
}

void _ISR _CNInterrupt(void) {
    
}

void K3_Callback(void) {
    // action
    LCDDATA1bits.S23C0 = !LCDDATA1bits.S23C0;

    // meta
    TMR4 = 0;
    buttonAllow = 0;
}

void K2_Callback(void) {
    // action
    PORTCbits.RC15 = !PORTCbits.RC15;


    // meta
    TMR4 = 0;
    buttonAllow = 0;
}


int main(void)
{
	initialize_HW();

    setDigits(8, 8, 8, 8);
    setPoints(true, true, true, true);
    setLowerScript(true, true, true, true, true);
    setSigns(true, true, true);
    setUnits(&allLCDUnitsON);
	
	// main loop:
	while(1)
	{
        if(!PORTBbits.RB3 && buttonAllow) {
            K3_Callback();
        }

        if(!PORTDbits.RD8 && buttonAllow) {
            K2_Callback();
        }           
	}

    return 0;	
}	