/*
 * GPIO_Control.c
 *
 *  Created on: 04.10.2023
 *      Author: cosmo
 */

#include "GPIO_Control.h"

void initGPIO() {
    PM5CTL0 &= ~LOCKLPM5;        // Disable the GPIO power-on default high-impedance mode
                                  // to activate previously configured port settings

    // ---------------- Onboard LEDs - PJ6 & PJ7 ---------------------------------------
    PJOUT &= ~(BIT6 + BIT7);        // Reset OUT state of the pins
    PJDIR |= BIT6 + BIT7;           // Set to outputs


    // ---------------- Map Clocks to a GPIO -------------------------------------------
    // output clocks to pins -- PJ1 - PJ2 - PJ3 
    // --> see device specific datasheet s.111
    //
    PJDIR |= BIT1 + BIT2 + BIT3; // set to output
    // set the function to the clock
    // PJ0
    PJSEL1 &= ~BIT0; // reset bit0
    PJSEL0 |= BIT0; // and set bit0
    // PJ1
    PJSEL1 &= ~BIT1; // reset bit1
    PJSEL0 |= BIT1; // and set bit1
    // PJ2
    PJSEL1 &= ~BIT2; // reset bit2
    PJSEL0 |= BIT2; // and set bit2
}

