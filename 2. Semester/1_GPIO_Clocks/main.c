#include "main.h"


void initMSP() {
    // first stop the watchdog
    WDTCTL = WDTPW | WDTHOLD;       // Stop WDT

    // all the other inits
    initGPIO();
}

int main(void) {
    initMSP();


    while(1)    
    {
        PJOUT ^= BIT6 + BIT7;                // Toggle Pins
        __delay_cycles(101000);
    }
}
