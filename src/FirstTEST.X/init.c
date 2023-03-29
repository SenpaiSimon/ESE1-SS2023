// Initialization of the hardware

#include <xc.h> // include processor description


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

//==========================================================================================

// Prototypes
void initGPIO(void);

void initCLOCK(void);

void initTIMERS(void);

// Declarations

void initTIMERS(void) {
    // TIMER1 -----------------------------------------------------------------------------

    /*
     * We want the counter to reset in 1Hz intervals
     * --> clock source for the timer is at 16Mhz
     * --> 16Mhz/1Hz = 16.000.000 -- or in other words this is FOSC/2
     * --> split this value up in PreScaler and Auto Reload value 
     * --> with prescaler of 256 we have 62500 left for auto reloading
     * --> this is okay since the timer is 16bit and the max number it can display is 65535
     */
    T1CONbits.TCKPS = 0b11; // prescaler 256
    PR1 = 31250; // auto reload register --> divide this by 2 because we toogle at every event
    
    // Start Timer
    T1CONbits.TON = 1;


    // TIMER2 -----------------------------------------------------------------------------

    // same calculation but with 0.5Hz instead of 1Hz
    T2CONbits.T32 = 0;
    T2CONbits.TCKPS = 0b11;
    PR2 = 62500;

    // enable interrupts on this timer
    _T2IE = 1; // needs to be timer 3! because timer 2 in 32 bit mode sets ir flag on timer 3

    // timer start
    T2CONbits.TON = 1;


    // TIMER 4 -----------------------------------------------------------------------------
    uint32_t delay_in_ms = 200;

    T4CONbits.T45 = 0;
    T4CONbits.TCKPS = 0b11; // 256
    //      Clock            1/T              Prescaler
    PR4 = (uint16_t)((16000000 / (1/(delay_in_ms/1000.0))) / 256.0);
    _T4IE = 1;

    T4CONbits.TON = 1;
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

    initTIMERS();

	initGPIO();
}	