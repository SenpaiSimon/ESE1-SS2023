// Prof. Dr. Artem Ivanov
// HAW Landshut


#include <xc.h> // include processor description
#include "main.h"

// GLOBALS
uint8_t buttonAllow = 1;

// this is 12:00 
uint32_t timePassed = 43200;

LCD_STATE_t lcdState;

// 1 Hz timer
void _ISR _T1Interrupt(void) {
    _T1IF = 0; // set flag

    // one seconds gone
    timePassed++;
    if(timePassed >= 86400) {
        // 86400 -> 24:00
        // 0     -> 00:00
        timePassed = 0;
    }
    setTime(timePassed);
}

// colon blinking 0.5 Hz
void _ISR _T2Interrupt(void) {
    _T2IF = 0; // reset IR flag

    lcdState.dots.col = !lcdState.dots.col;
    COLON = lcdState.dots.col;
}

// de-bounce button
void _ISR _T4Interrupt(void) {
    _T4IF = 0;
    if(PORTBbits.RB3 && PORTDbits.RD8 && PORTBbits.RB7) {
        buttonAllow = 1;
    }
}

void _ISR _CNInterrupt(void) {
    
}

// k3 button action
void K3_Callback(void) {
    // action
    timePassed += 60;
    setTime(timePassed);

    // meta
    TMR4 = 0;
    buttonAllow = 0;
}

// k2 button action
void K2_Callback(void) {
    // action
    // decrement number
    lcdState.number--;
    setNumber(lcdState.number);

    // meta
    TMR4 = 0;
    buttonAllow = 0;
}

void K1_Callback(void) {
    // action
    // increment number
    lcdState.number++;
    setNumber(lcdState.number);

    // meta 
    TMR4 = 0;
    buttonAllow = 0;
}


int main(void)
{
	initialize_HW();
    initLCD(&lcdState);

    //displayTest(1);
	
	// main loop:
	while(1)
	{
        if(!PORTBbits.RB3 && buttonAllow) {
            K3_Callback();
        }

        if(!PORTDbits.RD8 && buttonAllow) {
            K2_Callback();
        }   

        if(!PORTBbits.RB7 && buttonAllow) {
            K1_Callback();
        }        
	}

    return 0;	
}	