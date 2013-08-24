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

/***************************** PUBLIC DEFINITIONS *****************************/

typedef enum GpioDirection
{
    GpioDirection_INPUT,
    GpioDirection_OUTPUT

} GpioDirection_t;

/******************************* PUBLIC MACROS ********************************/

/****************************** PUBLIC FUNCTIONS ******************************/

/**
 *  Configures the GPIO with the given settings 
 */
void Gpio_Configure();

#ifdef	__cplusplus
}
#endif

#endif	/* GPIO_H */

