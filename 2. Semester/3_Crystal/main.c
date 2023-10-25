#include "main.h"


void initMSP() {
    // first stop the watchdog
    WDTCTL = WDTPW | WDTHOLD;       // Stop WDT

    // disableAllGPIO();
    // all the other inits
    initClocks();
    initGPIO();

    // wait for osc to work properly
    PJOUT |= BIT6; // toggle led on
    CSCTL4 &= ~LFXTOFF;

    do {
        CSCTL5 &= ~LFXTOFFG;
        SFRIFG1 &= ~OFIFG;
    } while(SFRIFG1 & OFIFG);

    PJOUT &= ~BIT6; // toggle led off again
    // now that osc is running enable fault isr
    SFRIE1 |= OFIE;


    // setup timer 
    // ACLK source -- up mode (compare mode)
    TA0CCTL0 = CCIE; // compare interrupt enable
    TA0CCR0 = 16384; // half of quartz freq --> toogle freq of 2hz --> whole freq of 1hz
    TA0CTL = TASSEL__ACLK | MC__UP;

    // set low power mode
    __bis_SR_register(LPM3_bits | GIE);
}

int main(void) {
    initMSP();

    // while(1)    
    // {
    //     // PJOUT ^= BIT6 + BIT7;                // Toggle Pins
    //     // PJOUT ^= BIT6;
    //     // __delay_cycles(100000);
    // }
    while(1) {

    }
    __no_operation();
}


// isr handler for TIMER0_A0
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=TIMER0_A0_VECTOR
__interrupt void TIMER0_A0_ISR(void)
#elif defined(__GNUC__)
void __attriubte__ ((interrupt(TIMER0_A0_VECTOR))) TIMER0_A0_ISR (void)
#else
#error Compiler not supported
#endif
{
    PJOUT ^= BIT6;
}
