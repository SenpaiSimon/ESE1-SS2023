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

#define PAD1_ADC 30
#define PAD2_ADC 11
#define PAD3_ADC 13
#define PAD4_ADC 15

#include <xc.h>

typedef struct adc_storage {
    unsigned int vbat;
    unsigned int iin;
} adc_storage_t;

void initADC();
unsigned int readChannel(uint8_t channel);
unsigned int rawToVoltage(unsigned int input);
void readBothChannels(adc_storage_t *storage);
void initOnboardVoltADC();
void initTouchADC();

#ifdef	__cplusplus
}
#endif

#endif	/* ADC_H */

