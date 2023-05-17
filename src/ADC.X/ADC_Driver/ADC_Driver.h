/* 
 * File:   ADC.h
 * Author: cosmo
 *
 * Created on 17. Mai 2023, 15:52
 */

#ifndef ADC_H
#define	ADC_H

#ifdef	__cplusplus
extern "C" {
#endif

#define VBAT_ADC 1
#define IN1_ADC 6

#include <xc.h>

void initADC();
unsigned int readChannel(uint8_t channel);
unsigned int rawToVoltage(unsigned int input);


#ifdef	__cplusplus
}
#endif

#endif	/* ADC_H */

