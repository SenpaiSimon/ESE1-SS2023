// Prof. Dr. Artem Ivanov
// HAW Landshut


#include <xc.h> // include processor description
#include "main.h"

// GLOBALS
uint8_t buttonAllow = 1;

// ISR
void _ISR _T4Interrupt(void) {
    _T4IF = 0;
    if(PORTBbits.RB3 && PORTDbits.RD8) {
        buttonAllow = 1;
    }
}

int main(void)
{
	initialize_HW();
	
	// main loop:
	while(1)
	{
        if(buttonAllow) {
            if(!PORTBbits.RB3) {
                PORTCbits.RC12 = !PORTCbits.RC12;
                TMR4 = 0;
                buttonAllow = 0;
            }

            if(!PORTDbits.RD8) {
                PORTCbits.RC15 = !PORTCbits.RC15;
                TMR4 = 0;
                buttonAllow = 0;
            }            
        }
	}	

}	