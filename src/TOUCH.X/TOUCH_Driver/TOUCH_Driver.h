/* 
 * File:   TOUCH_Driver.h
 * Author: cosmo
 *
 * Created on 24. Mai 2023, 16:24
 */

#ifndef TOUCH_DRIVER_H
#define	TOUCH_DRIVER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>

typedef struct pad_storage {
    unsigned int pad1;
    unsigned int pad2;
    unsigned int pad3;
    unsigned int pad4;
} pad_storage_t;

typedef enum pad_select {
    PAD1 = 0,
    PAD2 = 1,
    PAD3 = 2,
    PAD4 = 3
} pad_select_t;

void initTouchDriver();
void getPadStates(pad_storage_t *storage);


#ifdef	__cplusplus
}
#endif

#endif	/* TOUCH_DRIVER_H */

