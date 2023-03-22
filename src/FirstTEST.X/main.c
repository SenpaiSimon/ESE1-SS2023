// Prof. Dr. Artem Ivanov
// HAW Landshut


#include <xc.h> // include processor description
#include "main.h"

// #define TOGGLE_BUTTONS

// ISR
void _ISR _T3Interrupt(void) {
    _T3IF = 0; // reset IR flag
    PORTCbits.RC15 = !PORTCbits.RC15;
}


int main(void)
{
	initialize_HW();
	
	// main loop:
	while(1)
	{
        #ifdef TOGGLE_BUTTONS
        if(!PORTBbits.RB3) { // was RB7 -- Key1 -- now its key3
            PORTCbits.RC12 = !PORTCbits.RC12;
        }
        if(!PORTDbits.RD8) {
            PORTCbits.RC15 = !PORTCbits.RC15;
        }
        #else
        // wait for timer1 reset
        while(!_T1IF); 
        PORTCbits.RC12 = !PORTCbits.RC12; // toggle D5
        _T1IF = 0; // reset the flag
        #endif
	}	

}	