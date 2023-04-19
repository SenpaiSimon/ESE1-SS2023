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

void initDacDriver(void);

void speakerOn(bool on);

void sawToothgenerator();



#ifdef	__cplusplus
}
#endif

#endif	/* DAC_DRIVER_H */

