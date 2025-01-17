/* 
 * File:   Gpio.h
 * Author: ductape
 *
 * Created on August 24, 2013, 12:50 PM
 */

#ifndef GPIO_H
#define	GPIO_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>

/***************************** PUBLIC DEFINITIONS *****************************/

typedef enum GpioDirection
{
    GpioDirection_INPUT,
    GpioDirection_OUTPUT

} GpioDirection_t;

/******************************* PUBLIC MACROS ********************************/

#define GPIO_SET(portpin)      portpin = true;
#define GPIO_CLEAR(portpin)    portpin = false; 

/****************************** PUBLIC FUNCTIONS ******************************/

/**
 *  Configures the GPIO with the given settings 
 */
void Gpio_Configure(void);

#ifdef	__cplusplus
}
#endif

#endif	/* GPIO_H */

