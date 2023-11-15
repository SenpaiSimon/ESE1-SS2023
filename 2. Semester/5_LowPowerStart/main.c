#include "main.h"

int first = 1;
int unlocked = 0;

inline void initMSP() {
    // first stop the watchdog
    WDTCTL = WDTPW | WDTHOLD;       // Stop WDT

    disableAllGPIO();
    // all the other inits
    initRTC();

    unlocked = 1;
    __bis_SR_register(LPM3_bits | GIE);
}


int main(void) {

    initMSP();

    while(1) {
        __no_operation();
    }
}


// isr handler for RTC
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=RTC_VECTOR
__interrupt void RTC_ISR(void)
#elif defined(__GNUC__)
void __attriubte__ ((interrupt(RTC_VECTOR))) RTC_ISR (void)
#else
#error Compiler not supported
#endif
{
    switch(__even_in_range(RTCIV, RTCIV_RT1PSIFG)) {
        case RTCIV_NONE: break; // no isr
        
        case RTCIV_RTCOFIFG: break;
        
        case RTCIV_RTCRDYIFG:  // hits every second
        break;
        
        case RTCIV_RTCTEVIFG: // every minute
            if(first && unlocked) {
                //configure the rest
                first = 0;
                initGPIO();

                //only set up aclk nothing else ---------------------

                // unlock clocks --> erata s.104
                CSCTL0_H = CSKEY_H;
                // // ACLK -- should be crystal
                // // enable osc pins to work
                PJSEL0 |= BIT4 | BIT5;

                // ---------------------------------- Crystal Stuff
                // wait for osc to work properly
                CSCTL4 &= ~LFXTOFF;

                do {
                    CSCTL5 &= ~LFXTOFFG;
                    SFRIFG1 &= ~OFIFG;
                } while(SFRIFG1 & OFIFG);

                // now that osc is running enable fault isr
                SFRIE1 |= OFIE;
                // ----------------------------------

            }
            PJOUT ^= BIT7; 
        break; 
           
        case RTCIV_RTCAIFG: break;
        
        case RTCIV_RT0PSIFG: break;

        case RTCIV_RT1PSIFG: // should be 4 Hz for us

            PJOUT ^= BIT6;
        break;
        default: break;

    }
}
