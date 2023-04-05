// header file for main.c

#include "LCD_Driver/LCD_Driver.h"

// ISR
void _ISR _T2Interrupt(void);

void _ISR _T4Interrupt(void);

void _ISR _CNInterrupt(void);

void K2_Callback(void);

void K3_Callback(void);

void initialize_HW(void);	// initialisation procedure

