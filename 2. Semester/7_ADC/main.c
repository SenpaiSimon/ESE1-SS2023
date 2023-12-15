#include "main.h"

DISP_STATE_t display;
adc_values_t adcStorage;
int minutesPassed = 0;

static const uint8_t adcSampleFreq = 10; //Hz

void initMSP() {
    // first stop the watchdog
    WDTCTL = WDTPW | WDTHOLD;       // Stop WDT

    disableAllGPIO();
    // all the other inits
    initRTC();
    initClocks();
    initGPIO();
    initEpaper(&display);
    initADC();
    initCrystal();


    // ---------------------------------- setup timer 
    // ACLK source -- up mode (compare mode)
    TA0CCTL0 = CCIE; // compare interrupt enable
    TA0CCR0 = (unsigned int)(32768/adcSampleFreq);
    TA0CTL = TASSEL__ACLK | MC__UP;
    // ----------------------------------

    // global ISR enable
    __bis_SR_register(GIE);
}

int main(void) {
    initMSP();

    setMisc(false, true, false);

    while(1) {    
        setNumber(adcStorage.ext);
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
    ADC12CTL0 |= ADC12ENC | ADC12SC; // enable and start conversion for the adc
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
            
        break; 
           
        case RTCIV_RTCAIFG: break;
        
        case RTCIV_RT0PSIFG: break;

        case RTCIV_RT1PSIFG: // should be 4 Hz for us
            // PJOUT ^= BIT6;
        break;
        default: break;
    }
}

#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector = ADC12_VECTOR
__interrupt void ADC12_ISR(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(ADC12_VECTOR))) ADC12_ISR (void)
#else
#error Compiler not supported!
#endif
{
    switch (__even_in_range(ADC12IV, ADC12IV_ADC12RDYIFG)) {
        case ADC12IV_NONE:        break;        // Vector  0:  No interrupt
        case ADC12IV_ADC12OVIFG:  break;        // Vector  2:  ADC12MEMx Overflow
        case ADC12IV_ADC12TOVIFG: break;        // Vector  4:  Conversion time overflow
        case ADC12IV_ADC12HIIFG:  break;        // Vector  6:  ADC12BHI
        case ADC12IV_ADC12LOIFG:  break;        // Vector  8:  ADC12BLO
        case ADC12IV_ADC12INIFG:  break;        // Vector 10:  ADC12BIN
        case ADC12IV_ADC12IFG0:   break;        // Vector 12:  ADC12MEM0
        case ADC12IV_ADC12IFG1:   break;        // Vector 14:  ADC12MEM1
        case ADC12IV_ADC12IFG2:   
            adcStorage.ext = readExternalInput();
            adcStorage.temp = readTemp();
            adcStorage.vbat = readAVCC();
        break;        // Vector 16:  ADC12MEM2
        case ADC12IV_ADC12IFG3:   break;        // Vector 18:  ADC12MEM3
        case ADC12IV_ADC12IFG4:   break;        // Vector 20:  ADC12MEM4
        case ADC12IV_ADC12IFG5:   break;        // Vector 22:  ADC12MEM5
        case ADC12IV_ADC12IFG6:   break;        // Vector 24:  ADC12MEM6
        case ADC12IV_ADC12IFG7:   break;        // Vector 26:  ADC12MEM7
        case ADC12IV_ADC12IFG8:   break;        // Vector 28:  ADC12MEM8
        case ADC12IV_ADC12IFG9:   break;        // Vector 30:  ADC12MEM9
        case ADC12IV_ADC12IFG10:  break;        // Vector 32:  ADC12MEM10
        case ADC12IV_ADC12IFG11:  break;        // Vector 34:  ADC12MEM11
        case ADC12IV_ADC12IFG12:  break;        // Vector 36:  ADC12MEM12
        case ADC12IV_ADC12IFG13:  break;        // Vector 38:  ADC12MEM13
        case ADC12IV_ADC12IFG14:  break;        // Vector 40:  ADC12MEM14
        case ADC12IV_ADC12IFG15:  break;        // Vector 42:  ADC12MEM15
        case ADC12IV_ADC12IFG16:  break;        // Vector 44:  ADC12MEM16
        case ADC12IV_ADC12IFG17:  break;        // Vector 46:  ADC12MEM17
        case ADC12IV_ADC12IFG18:  break;        // Vector 48:  ADC12MEM18
        case ADC12IV_ADC12IFG19:  break;        // Vector 50:  ADC12MEM19
        case ADC12IV_ADC12IFG20:  break;        // Vector 52:  ADC12MEM20
        case ADC12IV_ADC12IFG21:  break;        // Vector 54:  ADC12MEM21
        case ADC12IV_ADC12IFG22:  break;        // Vector 56:  ADC12MEM22
        case ADC12IV_ADC12IFG23:  break;        // Vector 58:  ADC12MEM23
        case ADC12IV_ADC12IFG24:  break;        // Vector 60:  ADC12MEM24
        case ADC12IV_ADC12IFG25:  break;        // Vector 62:  ADC12MEM25
        case ADC12IV_ADC12IFG26:  break;        // Vector 64:  ADC12MEM26
        case ADC12IV_ADC12IFG27:  break;        // Vector 66:  ADC12MEM27
        case ADC12IV_ADC12IFG28:  break;        // Vector 68:  ADC12MEM28
        case ADC12IV_ADC12IFG29:  break;        // Vector 70:  ADC12MEM29
        case ADC12IV_ADC12IFG30:  break;        // Vector 72:  ADC12MEM30
        case ADC12IV_ADC12IFG31:  break;        // Vector 74:  ADC12MEM31
        case ADC12IV_ADC12RDYIFG: break;        // Vector 76:  ADC12RDY
        default: break;
    }
}
