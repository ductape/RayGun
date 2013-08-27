/* 
 * File:   Pwm.h
 * Author: ductape
 *
 * Created on August 24, 2013, 4:19 PM
 */

#ifndef PWM_H
#define	PWM_H

#ifdef	__cplusplus
extern "C" {
#endif

/***************************** PUBLIC DEFINITIONS *****************************/

/******************************* PUBLIC MACROS ********************************/

/****************************** PUBLIC FUNCTIONS ******************************/

/**
 * Initializes the PWM module with the default settings
 */
void Pwm_Init(void);

/**
 * Sets the PWM output to a specified frequency
 *
 * @param frequency - frequency (in Hertz) to output
 */
void Pwm_SetFrequency(uint16_t frequency);


#ifdef	__cplusplus
}
#endif

#endif	/* PWM_H */

