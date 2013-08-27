/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

/* Device header file */
#if defined(__XC16__)
    #include <xc.h>
#elif defined(__C30__)
    #if defined(__PIC24E__)
    	#include <p24Exxxx.h>
    #elif defined (__PIC24F__)||defined (__PIC24FK__)
	#include <p24Fxxxx.h>
    #elif defined(__PIC24H__)
	#include <p24Hxxxx.h>
    #endif
#endif

#include <stdint.h>        /* Includes uint16_t definition                    */
#include <stdbool.h>       /* Includes true/false definition                  */

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp              */
#include "Source/Platform/Board.h"
#include "Source/Micro/Pwm.h"
#include "Source/Micro/Gpio.h"
#include "libpic30.h"

/******************************************************************************/
/* Global Variable Declaration                                                */
/******************************************************************************/

/* i.e. uint16_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

int16_t main(void)
{
    uint16_t iteration = 0u;
    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize IO ports and peripherals */
    InitApp();

    /* TODO <INSERT USER APPLICATION CODE HERE> */

    TRISB = 0x00; /* set all of port A as outputs */
    TRISAbits.TRISA6 = false;
    _LATB7 = true; /* turn on RB7 */

    Pwm_Init(); 

    while(1)
    {
        _LATB6 ^= true;     /* toggle B6 */
        switch(iteration++)
        {
            case 0:
                Pwm_SetFrequency(1046); /* C6 */
                //GPIO_SET(LED_0_PORT,LED_0_PIN);
                GPIO_CLEAR1(LED_0);
                break;

            case 1:
                Pwm_SetFrequency(1175);  /* D6 */
//                GPIO_CLEAR(LED_0_PORT,LED_0_PIN);
                GPIO_SET1(LED_0);
                break;

            case 2:
                Pwm_SetFrequency(1319); /* E6 */
//                GPIO_SET(LED_0_PORT,LED_0_PIN);
                GPIO_CLEAR1(LED_0);
                break;

            case 3:
                Pwm_SetFrequency(1397); /* F6 */
//                GPIO_CLEAR(LED_0_PORT,LED_0_PIN);
                GPIO_SET1(LED_0);
                break;

            case 4:
                Pwm_SetFrequency(1568); /* G6 */
                break;

            case 5:
                Pwm_SetFrequency(1760); /* A6 */
                break;

            case 6:
                Pwm_SetFrequency(1976); /* B6 */
                break;

            case 7:
                Pwm_SetFrequency(2093); /* C7 */
                break;

            default:
                Pwm_SetFrequency(0);    /* off */
                break;
        }

        __delay_ms(250ul);
    }
}
