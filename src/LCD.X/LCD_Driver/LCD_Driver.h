/* 
 * File:   LCD_Driver.h
 * Author: cosmo
 *
 * Created on 5. April 2023, 21:47
 */

#ifndef LCD_DRIVER_H
#define	LCD_DRIVER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h> // so we can access all registers and stuff
#include <stdbool.h>

#include "LCD_MAP.h"
#include "LCD_Typedef.h"

void initLCD(LCD_STATE_t *stateStorage);
void updateLCD();
void displayTest(uint8_t state);
void setNumber(uint32_t number);
void setDigits(uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4);
void setPoints(bool d1, bool d2, bool d3, bool col);
void setLowerScript(bool bat, bool sp1, bool sp2, bool sp3, bool sp4);
void setSigns(bool up, bool down, bool minus);
void setUnits(UNITS_t *units);

#ifdef	__cplusplus
}
#endif

#endif	/* LCD_DRIVER_H */

