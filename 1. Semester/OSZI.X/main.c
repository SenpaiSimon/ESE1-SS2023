// Simon Obermeier & Sven Menzel
// HAW Landshut


#include <xc.h> // include processor description
#include "main.h"

// GLOBALS
uint8_t buttonAllow = 1;
uint8_t buttonPressed = 0;

uint8_t sampleNow = 0;

unsigned int currentNumber = 5000;
uint8_t buf[10];
uint8_t numbersReceived = 0;

adc_storage_t adc_results;
pad_storage_t pad_results;

unsigned int adcResultBuffer[4];
uint8_t selectedChannel = VBAT_ADC;

LCD_STATE_t lcdState;
pad_select_t padCounter = PAD1;
bool fullRefresh = false;

// #define SAMPLE_ONE

void _PSV _ISR _SPI1Interrupt(void) {
    _SPI1IF = 0;

    spiControlCS(HIZ);
}


// adc done isr --> do the reading of the pads
void _PSV _ISR _ADC1Interrupt(void) {
    _AD1IF = 0; // reset isr flag

    CTMUCON1bits.IDISSEN = 1; // close switch for old channel
    #ifndef SAMPLE_ONE
    switch(padCounter) {
        case PAD1: // pad 1
            pad_results.pad1 = ADRES0;
            ADTBL0bits.ADCH = PAD2_ADC;
            padCounter = PAD2;
        break;
        case PAD2: // pad 2
            pad_results.pad2 = ADRES0;
            ADTBL0bits.ADCH = PAD3_ADC;
            padCounter = PAD3;
        break;

        case PAD3: // pad 3
            pad_results.pad3 = ADRES0;
            ADTBL0bits.ADCH = PAD4_ADC;
            padCounter = PAD4;
        break;

        case PAD4: // pad 4  
            pad_results.pad4 = ADRES0;
            ADTBL0bits.ADCH = PAD1_ADC;
            padCounter = PAD1;
            fullRefresh = true;
        break;
    }
    #else
    pad_results.pad1 = ADRES0;
    #endif

    setNumber(rawToVoltage(pad_results.pad1));
}

//oc1 isr
void _PSV _ISR _OC1Interrupt(void) {
    _OC1IF = 0;
}

// uart receive isr
void _PSV _ISR _U1RXInterrupt(void) {
    U1STAbits.OERR = 0;

    _U1RXIF = 0;
}

// uart tx isr
void _PSV _ISR _U1TXInterrupt(void) {
    U1STAbits.OERR = 0;
    
    _U1TXIF = 0;
}

void _PSV _ISR _T1Interrupt(void) {
    _T1IF = 0; // reset flag

    // actions
    sampleNow = 1;
}

void _PSV _ISR _T2Interrupt(void) {
    _T2IF = 0; // reset IR flag
    // actions

    CTMUCON1bits.IDISSEN = 0; // open the switch
    CTMUCON2 &= ~(0b1100000000); // reset edge stats
}

// de-bounce button
void _PSV _ISR _T4Interrupt(void) {
    _T4IF = 0;
    if(PORTBbits.RB3 && PORTDbits.RD8 && PORTBbits.RB7) {
        buttonAllow = 1;
    }
}

void _PSV _ISR _CNInterrupt(void) {
    // clear ISR Flag
    IFS1bits.CNIF = 0;
    // we have a button event
    buttonPressed = 1;
}

// k3 button action
void K3_Callback(void) {
    // action
    // toggle speaker
    // speakerOn(PORTBbits.RB12);

    // meta
    TMR4 = 0;
    buttonAllow = 0;
}

// k2 button action
void K2_Callback(void) {
    // action
    // selectedChannel = IN1_ADC;
    
    // meta
    TMR4 = 0;
    buttonAllow = 0;
}

void K1_Callback(void) {
    // action

    // meta 
    TMR4 = 0;
    buttonAllow = 0;
}


int main(void)
{
	initialize_HW();
    initLCD(&lcdState);

    // init uart
    initUART(115200, 16000000);

    // speaker stuff
    // initDacDriver();
    // speakerOn(false);

    // touch 
    initTouchDriver();
    initTimer2(16000000, 200, true);
    startStopTimer2(true);

    // adc
    // initADC(); // not needed when using initOszi

    // never init these following two lines at the same time, they only work exclsuive ty
    // initOnboardVoltADC();
    // initTouchADC();

    // timers
    initTimer1(16000000, 10, true);
    startStopTimer1(true);

    // spi
    initOszi();
    
    // displayTest(1);
    // generateSawToothBufferAndStart(22050, 440, 100);
    // generateSineBufferAndStart(22050, 440, 100);
    // playSampleSound();
	
    setPoints(1,0,0,0);

	// main loop:
	while(1)
	{
        if(sampleNow) {
            // readBothChannels(&adc_results);
            // adc_results.vbat = rawToVoltage(adc_results.vbat);
            // adc_results.iin = rawToVoltage(adc_results.iin);

            // setNumber((selectedChannel == VBAT_ADC) ? adc_results.vbat : adc_results.iin);

            // adcResultBuffer[0] = pad_results.pad1;
            // adcResultBuffer[1] = pad_results.pad2;
            // adcResultBuffer[2] = pad_results.pad3;
            // adcResultBuffer[3] = pad_results.pad4;
            // transmitDataToPcTool(adcResultBuffer, 4);



            sampleNow = 0;
        }

        fill_adc_buffer(); // read the samples
        sendOsziDataToPC();

        if(buttonPressed && buttonAllow) {
            if(!PORTBbits.RB3) { // K3
                K3_Callback();
            }

            if(!PORTDbits.RD8) { // K2
                K2_Callback();
            }   

            if(!PORTBbits.RB7) { // K1
                K1_Callback();
            }        

            buttonPressed = 0;
        }
	}

    return 0;	
}	