/* 
 * File:   DAC_Driver.h
 * Author: cosmo
 *
 * Created on 19. April 2023, 16:15
 */

#ifndef DAC_DRIVER_H
#define	DAC_DRIVER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

#include "../TIMER_Driver/TIMER_Driver.h"

/*!
 * @brief init the dac peripheral
 */
void initDacDriver(void);

/*!
 * @brief toggle speaker driver
 * @param on on/off
 */
void speakerOn(bool on);

/*!
 * @brief play sawtooth wave over dma
 * @param sampleFreq freq at which data is sampled
 * @param desiredFreq which freq the sawtooth will have
 * @param peak peak sawtooth value
 */
void generateSawToothBufferAndStart(uint32_t sampleFreq, uint32_t desiredFreq, uint32_t peak);

/*!
 * @brief play sine wave over dma
 * @param sampleFreq freq at which data is sampled
 * @param desiredFreq which freq the sine will have
 * @param peak peak sine value
 */
void generateSineBufferAndStart(uint32_t sampleFreq, uint32_t desiredFreq, uint32_t peak);

/*!
 * @brief setup dma0
 * @param destination pointer to destination peripheral
 * @param source source buffer storage
 * @param elementCount how many elements are in buffer
 */
void setupDMA0(unsigned int *destination, unsigned int *source, uint32_t elementCount);

/*!
 * @brief play a sample sound
 */
void playSampleSound();

/*!
 * @brief play a whole buffer
 * @param sampleFreq freq at which data is sampled
 * @param sound pointer to sound buffer
 * @param length length of sound buffer
 */
void playSound(unsigned short int sampleFreq, unsigned short int *sound, uint32_t length);

#ifdef	__cplusplus
}
#endif

#endif	/* DAC_DRIVER_H */

