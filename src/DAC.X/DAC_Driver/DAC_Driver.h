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

#if defined(__NEED_uint16_t) && !defined(__DEFINED_uint16_t)
typedef unsigned int           uint16_t;
#define __DEFINED_uint16_t
#endif

void initDacDriver(void);

void speakerOn(bool on);

void generateSawToothBufferAndStart(uint32_t desiredFreq, uint32_t peak);

void generateSineBufferAndStart(uint32_t desiredFreq, uint32_t peak);

void setupDMA0(unsigned int *destination, unsigned int *source, uint32_t elementCount);


#ifdef	__cplusplus
}
#endif

#endif	/* DAC_DRIVER_H */

