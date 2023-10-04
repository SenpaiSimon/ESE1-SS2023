// Initialization of the hardware

#include <xc.h> // include processor description
#include "TIMER_Driver/TIMER_Driver.h"
#include "SD_Driver/sd_spi.h"
#include "SD_Driver/system_config.h"
#include "SD_Driver/system.h"
#include <xc.h>
#include <stdbool.h>


// Set cofiguration registers:-------------------------------------------------------------
// CONFIG4
#pragma config DSWDTPS = DSWDTPS1F      // Deep Sleep Watchdog Timer Postscale Select bits (1:68719476736 (25.7 Days))
#pragma config DSWDTOSC = LPRC          // DSWDT Reference Clock Select (DSWDT uses LPRC as reference clock)
#pragma config DSBOREN = OFF            // Deep Sleep BOR Enable bit (DSBOR Disabled)
#pragma config DSWDTEN = OFF            // Deep Sleep Watchdog Timer Enable (DSWDT Disabled)
#pragma config DSSWEN = OFF             // DSEN Bit Enable (Deep Sleep operation is always disabled)
#pragma config RTCBAT = ON              // RTC Battery Operation Enable (RTC operation is continued through VBAT)
#pragma config PLLDIV = NODIV           // PLL Input Prescaler Select bits (Oscillator used directly (4 MHz input))
#pragma config I2C2SEL = SEC            // Alternate I2C2 Location Select bit (I2C2 is multiplexed to SDA2/RF4 and SCL2/RF5)
#pragma config IOL1WAY = OFF            // PPS IOLOCK Set Only Once Enable bit (The IOLOCK bit can be set and cleared using the unlock sequence)

// CONFIG3
#pragma config WPFP = WPFP0             // Write Protection Flash Page Segment Boundary (Page 0 (0x00))
#pragma config SOSCSEL = ON             // SOSC Selection bits (SOSC circuit selected)
#pragma config WDTWIN = PS25_0          // Window Mode Watchdog Timer Window Width Select (Watch Dog Timer Window Width is 25 percent)
#pragma config BOREN = ON               // Brown-out Reset Enable (Brown-out Reset Enable)
#pragma config WPDIS = WPDIS            // Segment Write Protection Disable (Disabled)
#pragma config WPCFG = WPCFGDIS         // Write Protect Configuration Page Select (Disabled)
#pragma config WPEND = WPSTARTMEM       // Segment Write Protection End Page Select (Write Protect from page 0 to WPFP)

// CONFIG2
#pragma config POSCMD = NONE            // Primary Oscillator Select (Primary Oscillator Disabled)
#pragma config WDTCLK = LPRC            // WDT Clock Source Select bits (WDT uses LPRC)
#pragma config OSCIOFCN = ON            // OSCO Pin Configuration (OSCO/CLKO/RC15 functions as CLKO (FOSC/2))
#pragma config FCKSM = CSDCMD           // Clock Switching and Fail-Safe Clock Monitor Configuration bits (Clock switching and Fail-Safe Clock Monitor are disabled)
#pragma config FNOSC = FRCPLL           // Initial Oscillator Select (Fast RC Oscillator with PLL module (FRCPLL))
#pragma config ALTADREF = AVREF_RB      // External 12-Bit A/D Reference Location Select bit (AVREF+/AVREF- are mapped to RB0/RB1)
#pragma config ALTCVREF = CVREF_RB      // External Comparator Reference Location Select bit (CVREF+/CVREF- are mapped to RB0/RB1)
#pragma config WDTCMX = LPRC            // WDT Clock Source Select bits (WDT always uses LPRC as its clock source)
#pragma config IESO = OFF               // Internal External Switchover (Disabled)

// CONFIG1
#pragma config WDTPS = PS32768          // Watchdog Timer Postscaler Select (1:32,768)
#pragma config FWPSA = PR128            // WDT Prescaler Ratio Select (1:128)
#pragma config WINDIS = OFF             // Windowed WDT Disable (Standard Watchdog Timer)
#pragma config FWDTEN = WDT_SW          // Watchdog Timer Enable (WDT controlled with the SWDTEN bit)
#pragma config ICS = PGx3               // Emulator Pin Placement Select bits (Emulator functions are shared with PGEC3/PGED3)
#pragma config LPCFG = ON               // Low power regulator control (Low voltage regulator controlled in sw by RETEN bit)
#pragma config GWRP = OFF               // General Segment Write Protect (Disabled)
#pragma config GCP = OFF                // General Segment Code Protect (Code protection is disabled)
#pragma config JTAGEN = OFF             // JTAG Port Enable (Disabled)


//#pragma config ICS = PGx2
// #pragma config PLL_96MHZ = ON
// #pragma config OSCIOFNC = ON
// #pragma config POSCMOD = HS
// #pragma config FNOSC = PRIPLL
// #pragma config PLLDIV = DIV2
// #pragma config IOL1WAY = ON

//==========================================================================================

// Prototypes
void initGPIO(void);

void initCLOCK(void);

void initTIMERS(void);

void USER_SdSpiSetCs(uint8_t a);
bool USER_SdSpiGetCd(void);
bool USER_SdSpiGetWp(void);
void USER_SdSpiConfigurePins (void);

// Declarations

void initTIMERS(void) {
    // TIMER1 -----------------------------------------------------------------------------

    initTimer1(16000000, 1, true);
    startStopTimer1(true);


    // TIMER2 -----------------------------------------------------------------------------

    initTimer2(16000000, 22050, true);
    startStopTimer2(true);


    // TIMER 4 -----------------------------------------------------------------------------
    uint32_t delay_in_ms = 10;
    uint32_t delay_in_hz = (1/(delay_in_ms/1000.0));

    initTimer4(16000000, delay_in_hz, true);
    startStopTimer4(true);
}

void initGPIO(void) {
    // Pin functions --------------------------------------------------------
    // 1. Analog / digital: (0 - Digital | 1 = Analog)

    // PORT B
    ANSBbits.ANSB2 = 0;
    ANSBbits.ANSB7 = 0; 
    ANSBbits.ANSB3 = 0;
    // PORT D
    ANSDbits.ANSD8 = 0;

    // 2. Digital Input / Output: (0 - Output | 1 - Input)

    // PORT B
    TRISBbits.TRISB2 = 0;
    TRISBbits.TRISB7 = 1;
    TRISBbits.TRISB3 = 1;
    // PORT C
    TRISCbits.TRISC12 = 0;
    TRISCbits.TRISC15 = 0;
    // PORT D
    TRISDbits.TRISD8 = 1;

    // 3. Output level on digital pins: (1 - High | 0 = Low)

    // PORT B
    LATBbits.LATB2 = 0; // Alternative -- PORTBbits.RB2 = 0;
    // PORT C
    LATCbits.LATC12 = 1; // Alternative -- PORTCbits.RC12 = 1;
    LATCbits.LATC15 = 1;


    // 4. Open drain settings: (1 - Open Drain | 0 - Push/Pull)

    // PORT B
    ODCBbits.ODB2 = 1;
    ODCBbits.ODB7 = 0;
    // PORT C
    ODCCbits.ODC12 = 0;


    // 5. Pull UP/Pull Down
    
    // KEY 1 - 18 / RB7 / CN25
    _CN25IE = 1;

    // KEY 2 - 42 / RD8 / CN53
    _CN53IE = 1;

    // KEY 3 - 13 / RB3 / CN5
    CNPU1bits.CN5PUE = 1; // pull up
    _CN5IE = 1;

    // enanle CN interrupts
    _CNIE = 1;
}

void initCLOCK(void) {
    // Oscillator Configuration----------------------------------------------
    // setting F_cy = Fosc/2 = 16MHz:
	CLKDIVbits.RCDIV = 1;			// divide by 2 (actually default)
	CLKDIVbits.CPDIV = 0;			// no division Clock=32MHz (default) 
    
    // Clock tuning to get nice 16 Mhz
    OSCTUNbits.TUN = 0b111100;	
}

void initialize_HW(void){
    initCLOCK();
    
    initGPIO();

    initTIMERS();

    // AD1PCFGL = 0xFFFF;
}	

void USER_SdSpiConfigurePins (void)
{
    //Initialize the SPI
    // RPINR20bits.SDI1R = 23;
    // RPOR7bits.RP15R = 7;
    // RPOR0bits.RP0R = 8;  
    // CS --> RE7
    // MOSI --> RP21
    // CLK --> RP26
    // MISO --> RP19  
    ANSGbits.ANSG7 = 0; // digital
    ANSGbits.ANSG6 = 0; // digital
    ANSGbits.ANSG8 = 0; // digital
    RPOR13bits.RP26R = 8; // RP26 should be spi 1 clock
    RPOR10bits.RP21R = 7; // RP21 should be spi 1 mosi

    ANSGbits.ANSG8 = 0;
    RPINR20bits.SDI1R = 19; // RP19 should be spi 1 miso

    //enable a pull-up for the card detect, just in case the SD-Card isn't attached
    //  then lets have a pull-up to make sure we don't think it is there.
    CNPU5bits.CN68PUE = 1;

    // Deassert the chip select pin
    LATEbits.LATE7 = 1;
    // Configure CS pin as an output
    ANSEbits.ANSE7 = 1;
    TRISEbits.TRISE7 = 0;
    // Configure CD pin as an input
    TRISFbits.TRISF0 = 1;
    // Configure WP pin as an input
    // TRISFbits.TRISF1 = 1;
}

void USER_SdSpiSetCs(uint8_t a)
{
    LATEbits.LATE7 = a;
}

bool USER_SdSpiGetCd(void)
{
    // return (!PORTFbits.RF0) ? true : false;
    return true;
}

bool USER_SdSpiGetWp(void)
{
    // return (PORTFbits.RF1) ? true : false;
    return false;
}


// The sdCardMediaParameters structure defines user-implemented functions needed by the SD-SPI fileio driver.
// The driver will call these when necessary.  For the SD-SPI driver, the user must provide
// parameters/functions to define which SPI module to use, Set/Clear the chip select pin,
// get the status of the card detect and write protect pins, and configure the CS, CD, and WP
// pins as inputs/outputs (as appropriate).
// For this demo, these functions are implemented in system.c, since the functionality will change
// depending on which demo board/microcontroller you're using.
// This structure must be maintained as long as the user wishes to access the specified drive.
FILEIO_SD_DRIVE_CONFIG sdCardMediaParameters =
{
    1,                                  // Use SPI module 2
    USER_SdSpiSetCs,                    // User-specified function to set/clear the Chip Select pin.
    USER_SdSpiGetCd,                    // User-specified function to get the status of the Card Detect pin.
    USER_SdSpiGetWp,                    // User-specified function to get the status of the Write Protect pin.
    USER_SdSpiConfigurePins             // User-specified function to configure the pins' TRIS bits.
};