// Prof. Dr. Artem Ivanov
// HAW Landshut


#include <xc.h> // include processor description
#include "main.h"

int main(void)
{
	initialize_HW();
	
	// main loop:
	while(1)
	{
        if(!PORTBbits.RB3) { // was RB7 -- Key1 -- now its key3
            PORTCbits.RC12 = !PORTCbits.RC12;
        }
        if(!PORTDbits.RD8) {
            PORTCbits.RC15 = !PORTCbits.RC15;
        }
	}	
}	