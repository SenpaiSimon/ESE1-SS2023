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
void GetTimestamp (FILEIO_TIMESTAMP * timeStamp);
extern FILEIO_SD_DRIVE_CONFIG sdCardMediaParameters;
const FILEIO_DRIVE_CONFIG gSdDrive =
{
    (FILEIO_DRIVER_IOInitialize)FILEIO_SD_IOInitialize,                      // Function to initialize the I/O pins used by the driver.
    (FILEIO_DRIVER_MediaDetect)FILEIO_SD_MediaDetect,                       // Function to detect that the media is inserted.
    (FILEIO_DRIVER_MediaInitialize)FILEIO_SD_MediaInitialize,               // Function to initialize the media.
    (FILEIO_DRIVER_MediaDeinitialize)FILEIO_SD_MediaDeinitialize,           // Function to de-initialize the media.
    (FILEIO_DRIVER_SectorRead)FILEIO_SD_SectorRead,                         // Function to read a sector from the media.
    (FILEIO_DRIVER_SectorWrite)FILEIO_SD_SectorWrite,                       // Function to write a sector to the media.
    (FILEIO_DRIVER_WriteProtectStateGet)FILEIO_SD_WriteProtectStateGet,     // Function to determine if the media is write-protected.
};
typedef enum
{
    DEMO_STATE_NO_MEDIA = 0,
    DEMO_STATE_MEDIA_DETECTED,
    DEMO_STATE_DRIVE_MOUNTED,
    DEMO_STATE_DONE,
    DEMO_STATE_FAILED
} DEMO_STATE;

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
    // initUART(115200, 16000000);

    // speaker stuff
    // initDacDriver();
    // speakerOn(false);

    // touch 
    // initTouchDriver();
    // initTimer2(16000000, 200, true);
    // startStopTimer2(true);

    // adc
    // initADC(); // not needed when using initOszi

    // never init these following two lines at the same time, they only work exclsuive ty
    // initOnboardVoltADC();
    // initTouchADC();

    // timers
    // initTimer1(16000000, 10, true);
    // startStopTimer1(true);

    // spi
    // initOszi();
    
    // displayTest(1);
    // generateSawToothBufferAndStart(22050, 440, 100);
    // generateSineBufferAndStart(22050, 440, 100);
    // playSampleSound();
	
    // setPoints(1,0,0,0);
    DEMO_STATE demoState = DEMO_STATE_NO_MEDIA;
    FILEIO_OBJECT file;
    BSP_RTCC_DATETIME dateTime;
    dateTime.bcdFormat = false;
    RTCC_BuildTimeGet(&dateTime);
    RTCC_Initialize (&dateTime);

    // Initialize the library
    if (!FILEIO_Initialize())
    {
        while(1);
    }
    FILEIO_RegisterTimestampGet (GetTimestamp);

    USER_SdSpiConfigurePins();

    uint8_t sampleData[10] = "DATA,10\r\n";

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

        switch (demoState)
        {
            case DEMO_STATE_NO_MEDIA:
                // Loop on this function until the SD Card is detected.
                if (FILEIO_MediaDetect(&gSdDrive, &sdCardMediaParameters) == true)
                {
                    demoState = DEMO_STATE_MEDIA_DETECTED;
                }
                break;
            case DEMO_STATE_MEDIA_DETECTED:
                // Try to mount the drive we've defined in the gSdDrive structure.
                // If mounted successfully, this drive will use the drive Id 'A'
                // Since this is the first drive we're mounting in this application, this
                // drive's root directory will also become the current working directory
                // for our library.
                if (FILEIO_DriveMount('A', &gSdDrive, &sdCardMediaParameters) == FILEIO_ERROR_NONE)
                {
                    demoState = DEMO_STATE_DRIVE_MOUNTED;
                }
                else
                {
                    demoState = DEMO_STATE_NO_MEDIA;
                }

                break;
            case DEMO_STATE_DRIVE_MOUNTED:
                // Open TESTFILE.TXT.
                // Specifying CREATE will create the file is it doesn't exist.
                // Specifying APPEND will set the current read/write location to the end of the file.
                // Specifying WRITE will allow you to write to the code.
                if (FILEIO_Open (&file, "TEST.CSV", FILEIO_OPEN_WRITE | FILEIO_OPEN_APPEND | FILEIO_OPEN_CREATE) == FILEIO_RESULT_FAILURE)
                {
                    demoState = DEMO_STATE_FAILED;
                    break;
                }
                if(FILEIO_Read(buf, 10, 10, &file) == FILEIO_RESULT_FAILURE) {
                    demoState = DEMO_STATE_FAILED;
                    break;
                }

                // Write some sample data to the card
                if (FILEIO_Write (sampleData, 1, 9, &file) != 9)
                {
                    demoState = DEMO_STATE_FAILED;
                    break;
                }

                // Close the file to save the data
                if (FILEIO_Close (&file) != FILEIO_RESULT_SUCCESS)
                {
                    demoState = DEMO_STATE_FAILED;
                    break;
                }

                // We're done with this drive.
                // Unmount it.
                FILEIO_DriveUnmount ('A');
                demoState = DEMO_STATE_DONE;
                break;
            case DEMO_STATE_DONE:
                // Now that we've written all of the data we need to write in the application, wait for the user
                // to remove the card
                if (FILEIO_MediaDetect(&gSdDrive, &sdCardMediaParameters) == false)
                {
                    demoState = DEMO_STATE_NO_MEDIA;
                }
                setNumber(9999);
                break;
            case DEMO_STATE_FAILED:
                // An operation has failed.  Try to unmount the drive.  This will also try to
                // close all open files that use this drive (it will at least deallocate them).
                FILEIO_DriveUnmount ('A');
                // Return to the media-detect state
                demoState = DEMO_STATE_NO_MEDIA;
                setNumber(0);
                break;
        }
	}

    return 0;	
}	

void GetTimestamp (FILEIO_TIMESTAMP * timeStamp)
{
    BSP_RTCC_DATETIME dateTime;

    dateTime.bcdFormat = false;

    RTCC_TimeGet(&dateTime);

    timeStamp->timeMs = 0;
    timeStamp->time.bitfield.hours = dateTime.hour;
    timeStamp->time.bitfield.minutes = dateTime.minute;
    timeStamp->time.bitfield.secondsDiv2 = dateTime.second / 2;

    timeStamp->date.bitfield.day = dateTime.day;
    timeStamp->date.bitfield.month = dateTime.month;
    // Years in the RTCC module go from 2000 to 2099.  Years in the FAT file system go from 1980-2108.
    timeStamp->date.bitfield.year = dateTime.year + 20;
}