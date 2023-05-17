/* 
 * File:   TIMER_Driver.h
 * Author: cosmo
 *
 * Created on 28. April 2023, 11:01
 */

#ifndef TIMER_DRIVER_H
#define	TIMER_DRIVER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
#include <stdbool.h>
#include <math.h>

uint8_t findCorrectPrescaler(uint32_t *reloadValue);

/*!
 * @param chipFreq Freq which clocks the Timer Module
 * @param desiredFreq Freq at which the timer should reset and trigger an isr
 * @param isrEnable if isr should be enabled
 */
void initTimer4(uint32_t chipFreq, uint32_t desiredFreq, bool isrEnable);

/*!
 * @param start true is timer should be on, false to disable timer
 */
void startStopTimer4(bool start);

/*!
 * @param chipFreq Freq which clocks the Timer Module
 * @param desiredFreq Freq at which the timer should reset and trigger an isr
 * @param isrEnable if isr should be enabled
 */
void initTimer2(uint32_t chipFreq, uint32_t desiredFreq, bool isrEnable);

/*!
 * @param start true is timer should be on, false to disable timer
 */
void startStopTimer2(bool start);

/*!
 * @param chipFreq Freq which clocks the Timer Module
 * @param desiredFreq Freq at which the timer should reset and trigger an isr
 * @param isrEnable if isr should be enabled
 */
void initTimer1(uint32_t chipFreq, uint32_t desiredFreq, bool isrEnable);

/*!
 * @param start true is timer should be on, false to disable timer
 */
void startStopTimer1(bool start);



#ifdef	__cplusplus
}
#endif

#endif	/* TIMER_DRIVER_H */

