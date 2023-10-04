// Prof. Dr. Artem Ivanov
// HAW Landshut


#include <xc.h> // include processor description
#include "main.h"

// GLOBALS
uint8_t buttonAllow = 1;
uint8_t buttonPressed = 0;

unsigned int currentNumber = 5000;
uint8_t buf[10];
uint8_t numbersReceived = 0;

LCD_STATE_t lcdState;

// uart receive isr
void _ISR _U1RXInterrupt(void) {
    U1STAbits.OERR = 0;

    buf[numbersReceived] = receiveUART();
    numbersReceived++;

    if(numbersReceived == 4) { // we got all the numbers
        numbersReceived = 0;
        setDigits(buf[0], buf[1], buf[2], buf[3]);
    }

    _U1RXIF = 0;
}

void _ISR _U1TXInterrupt(void) {
    U1STAbits.OERR = 0;
    _U1TXIF = 0;
}

// 1 Hz timer
void _PSV _ISR _T1Interrupt(void) {
    _T1IF = 0; // reset flag
}

// dac controller and dma interrupts -- 22050 Hz
void _PSV _ISR _T2Interrupt(void) {
    _T2IF = 0; // reset IR flag

    // actions
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

    // send current display number
    buf[0] = currentNumber & 0xFF;
    buf[1] = (currentNumber >> 8 ) & 0xFF;
    sendBytesBlocking(buf, 2);

    // meta
    TMR4 = 0;
    buttonAllow = 0;
}

// k2 button action
void K2_Callback(void) {
    // action
    currentNumber++;
    setNumber(currentNumber);
    // meta
    TMR4 = 0;
    buttonAllow = 0;
}

void K1_Callback(void) {
    // action
    currentNumber--;
    setNumber(currentNumber);
    sendBytesBlocking("test\n\r", strlen("test\n\r"));

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
    initDacDriver();
    speakerOn(false);

    //displayTest(1);
    // generateSawToothBufferAndStart(22050, 440, 100);
    // generateSineBufferAndStart(22050, 440, 100);
    // playSampleSound();

    setNumber(currentNumber);
	
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