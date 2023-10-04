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
    PJDIR |= BIT1 + BIT2 + BIT3; // set to output
    // set the function to the clock
    PJSEL0 = 0;
    PJSEL1 = 0;
}

