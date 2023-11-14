#include "main.h"

void enterLPM35() {
    PMMCTL0_H = PMMPW_H;
    PMMCTL0_L |= PMMREGOFF;

    // enter lpm3.5 with IR enable
    __bis_SR_register(LPM4_bits | GIE);
}

void enterLPM45(bool svs) {
    PMMCTL0_H = PMMPW_H; // unlock da boi

    if(!svs) {
        PMMCTL0 &= ~(SVSHE);
    }

    PMMCTL0_L |= PMMREGOFF;
    PMMCTL0_H = 0; // lock da boi

    // enter lpm4.5 with IR enable
    __bis_SR_register(LPM4_bits);
}

void initMSPAfterLPM() {
    // first stop the watchdog
    WDTCTL = WDTPW | WDTHOLD;       // Stop WDT

    disableAllGPIO();
    // all the other inits
    initRTCAfterLPM();
    initClocks();
    initGPIO();

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


    // ---------------------------------- setup timer 
    // ACLK source -- up mode (compare mode)
    // TA0CCTL0 = CCIE; // compare interrupt enable
    // TA0CCR0 = 16384; // half of quartz freq --> toogle freq of 2hz --> whole freq of 1hz
    // TA0CTL = TASSEL__ACLK | MC__UP;
    // ----------------------------------

    // enable Global IR
    __bis_SR_register(GIE);
}

void initMSP() {
    // first stop the watchdog
    WDTCTL = WDTPW | WDTHOLD;       // Stop WDT

    disableAllGPIO();
    // all the other inits
    initRTC();
    initClocks();
    initGPIO();

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


    // ---------------------------------- setup timer 
    // ACLK source -- up mode (compare mode)
    // TA0CCTL0 = CCIE; // compare interrupt enable
    // TA0CCR0 = 16384; // half of quartz freq --> toogle freq of 2hz --> whole freq of 1hz
    // TA0CTL = TASSEL__ACLK | MC__UP;
    // ----------------------------------
}

int main(void) {
    if(SYSRSTIV == SYSRSTIV_LPM5WU) { // we are here after 20 seconds
        // we woke up from a lpm5 state
        initMSPAfterLPM();
        initRTCAfterLPM();
        __enable_interrupt();
        while(1) {

        };
    } else {
        // its a normal power on
        initMSP();
        // enterLPM45(false);
        enterLPM35();
        // after here is dead end
    }
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
    __no_operation();
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
