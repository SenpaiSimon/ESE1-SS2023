// header file for main.c

#include "LCD_Driver/LCD_Driver.h"
#include "DAC_Driver/DAC_Driver.h"
#include "UART_Driver/UART_Driver.h"
#include "ADC_Driver/ADC_Driver.h"
#include "TOUCH_Driver/TOUCH_Driver.h"
#include "OSZI_Driver/OSZI_Driver.h"
#include <string.h>

#define _PSV __attribute__((auto_psv))

// ISR
void _PSV _ISR _T1Interrupt(void);

void _PSV _ISR _T2Interrupt(void);

void _PSV _ISR _T4Interrupt(void);

void _PSV _ISR _CNInterrupt(void);

void _PSV _ISR _U1RXInterrupt(void);

void _PSV _ISR _ADC1Interrupt(void);

void K1_Callback(void);

void K2_Callback(void);

void K3_Callback(void);

void initialize_HW(void);	// initialisation procedure

