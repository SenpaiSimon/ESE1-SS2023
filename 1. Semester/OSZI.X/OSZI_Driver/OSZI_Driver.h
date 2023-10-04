/* 
 * File:   OSZI_Driver.h
 * Author: cosmo
 *
 * Created on 7. Juni 2023, 16:11
 */

#ifndef OSZI_DRIVER_H
#define	OSZI_DRIVER_H

#ifdef	__cplusplus
extern "C" {
#endif

#define ANALOG_FRONT_ADC 0


#include <xc.h>
#include "../UART_Driver/UART_Driver.h"
#include "../ADC_Driver/ADC_Driver.h"
#include "../DAC_Driver/DAC_Driver.h"
#include "../LCD_Driver/LCD_Driver.h"


typedef union pga_instruction {
    struct bits {
        int data : 8;
        int indirect_addr : 1;
        int :4;
        int command_bytes : 3;
    } bits_t;
    unsigned int data;
}pga_instruction_t;


typedef struct oszi_config {
    uint8_t vertical;
    uint8_t tad_fak_low;
    uint8_t tad_fak_high;
    uint8_t trigger_low;
    uint8_t trigger_high;
    char trigger_mode;
    char trigger_edge;
} oszi_config_t;

typedef enum od {
    HIZ,
    OD
} od_t;

void fill_adc_buffer();
void sendOsziDataToPC();
void configurePGA();
void receiveOsziConfig();
void sendOsziConfig();
oszi_config_t* getOsziConfig();
void spiWrite(unsigned int *data, uint8_t dataCount);
void spiControlCS(od_t od);
void initSpi();
void initOszi();
void sendInstruction(pga_instruction_t *instruction);
void initOsziADC();
unsigned int getAnalogFrontADC();


#ifdef	__cplusplus
}
#endif

#endif	/* OSZI_DRIVER_H */

