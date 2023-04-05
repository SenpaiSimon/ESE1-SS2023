// Prof. Dr. Artem Ivanov
// HAW Landshut


#include <xc.h> // include processor description
#include "main.h"

// ISR
void _ISR _T2Interrupt(void) {
    _T2IF = 0; // reset IR flag
    PORTCbits.RC15 = !PORTCbits.RC15;
}

int main(void)
{
	initialize_HW();
	
	// main loop:
	while(1)
	{
        // wait for timer1 reset
        while(!_T1IF); 
        PORTCbits.RC12 = !PORTCbits.RC12; // toggle D5
        _T1IF = 0; // reset the flag
	}	

}	