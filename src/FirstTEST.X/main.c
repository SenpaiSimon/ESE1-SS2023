// Prof. Dr. Artem Ivanov
// HAW Landshut


#include <xc.h> // include processor description
#include "main.h"

#define TOGGLE_BUTTONS
// #define BUTTON_INTERRUPT

// GLOBALS
uint8_t buttonAllow = 1;

// ISR
void _ISR _T2Interrupt(void) {
    _T2IF = 0; // reset IR flag
#ifndef TOGGLE_BUTTONS
    PORTCbits.RC15 = !PORTCbits.RC15;
#endif
}

void _ISR _T4Interrupt(void) {
    _T4IF = 0;
    buttonAllow = 1;
}

void _ISR _CNInterrupt(void) {
    PORTCbits.RC12 = !PORTCbits.RC12;
}




int main(void)
{
	initialize_HW();
	
	// main loop:
	while(1)
	{
#ifdef TOGGLE_BUTTONS
#ifndef BUTTON_INTERRUPT
        if(buttonAllow) {
            if(!PORTBbits.RB3) {
                PORTCbits.RC12 = !PORTCbits.RC12;
            }

            if(!PORTDbits.RD8) {
                PORTCbits.RC15 = !PORTCbits.RC15;
            }

            TMR4 = 0;
            buttonAllow = 0;
        }
#endif
#else

        // wait for timer1 reset
        while(!_T1IF); 
        PORTCbits.RC12 = !PORTCbits.RC12; // toggle D5
        _T1IF = 0; // reset the flag
#endif
	}	

}	