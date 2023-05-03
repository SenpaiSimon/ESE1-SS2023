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

/*!
 * @brief init the lcd peripheral 
 * @param stateStorage pointer to @ref LCD_STATE_t where state will be stored
 */
void initLCD(LCD_STATE_t *stateStorage);

/*!
 * @brief updates the lcd with the insides of stateStorage from initLCD()
 */
void updateLCD();

/*!
 * @brief display a time
 * @param secondsPassed seconds which will be calculated to a time
 */
void setTime(uint32_t secondsPassed);

/*!
 * @brief controls all the available points
 * @param state which state all points should be set
 */
void displayTest(uint8_t state);

/*!
 * @brief display a 4 digit number
 * @param number which 4 digit number to display
 */
void setNumber(uint32_t number);

/*!
 * @brief display digits
 * @param d1 thousands digit
 * @param d2 hundreds digit
 * @param d3 tens digit
 * @param d4 ones digit
 */
void setDigits(uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4);

/*!
 * @brief Control all dots
 * @param d1 first decimal point
 * @param d2 second decimal point
 * @param d3 third decimal point
 * @param col middle collon
 */
void setPoints(bool d1, bool d2, bool d3, bool col);

/*!
 * @brief control lower script
 * @param bat bat sign
 * @param sp1 sp1 sing
 * @param sp2 sp2 sign
 * @param sp3 sp3 sign
 * @param sp4 sp4 sign
 */
void setLowerScript(bool bat, bool sp1, bool sp2, bool sp3, bool sp4);

/*!
 * @brief control pre script
 * @param up up arrow
 * @param down down arrow
 * @param minues minus sign
 */
void setSigns(bool up, bool down, bool minus);

/*!
 * @brief Control all the units
 * @param units pointer to \ref UNITS_t typedef which holds the data
 */
void setUnits(UNITS_t *units);

#ifdef	__cplusplus
}
#endif

#endif	/* LCD_DRIVER_H */

