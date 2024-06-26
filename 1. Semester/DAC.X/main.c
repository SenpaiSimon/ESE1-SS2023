// Prof. Dr. Artem Ivanov
// HAW Landshut


#include <xc.h> // include processor description
#include "main.h"

// GLOBALS
uint8_t buttonAllow = 1;
uint8_t buttonPressed = 0;

uint32_t currentFreq = 0;

LCD_STATE_t lcdState;

// 1 Hz timer
void _ISR _T1Interrupt(void) {
    _T1IF = 0; // set flag

}

// dac controller and dma interrupts -- 22050 Hz
void _ISR _T2Interrupt(void) {
    _T2IF = 0; // reset IR flag

    // sawToothgenerator();
}

// de-bounce button
void _ISR _T4Interrupt(void) {
    _T4IF = 0;
    if(PORTBbits.RB3 && PORTDbits.RD8 && PORTBbits.RB7) {
        buttonAllow = 1;
    }
}

void _ISR _CNInterrupt(void) {
    // clear ISR Flag
    IFS1bits.CNIF = 0;
    // we have a button event
    buttonPressed = 1;
}

// k3 button action
void K3_Callback(void) {
    // action
    // toggle speaker
    speakerOn(PORTBbits.RB12);

    // meta
    TMR4 = 0;
    buttonAllow = 0;
}

// k2 button action
void K2_Callback(void) {
    // action
    currentFreq -= 100;
    if(currentFreq < 100) { currentFreq = 100; }


    setNumber(currentFreq);

    // meta
    TMR4 = 0;
    buttonAllow = 0;
}

void K1_Callback(void) {
    // action
    currentFreq += 100;
    if(currentFreq > 9900) { currentFreq = 9900; }

    setNumber(currentFreq);

    // meta 
    TMR4 = 0;
    buttonAllow = 0;
}


int main(void)
{
	initialize_HW();
    initLCD(&lcdState);

    // speaker stuff
    initDacDriver();
    speakerOn(false);

    //displayTest(1);
    // generateSawToothBufferAndStart(22050, 440, 100);
    // generateSineBufferAndStart(22050, 440, 100);
    playSampleSound();
	
	// main loop:
	while(1)
	{
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