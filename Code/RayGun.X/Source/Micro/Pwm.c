
#include <stdint.h>          /* For uint32_t definition */
#include <stdbool.h>         /* For true/false definition */

#include "Pwm.h"
#include "../../system.h"
#include <xc.h>

/***************************** LOCAL DEFINITIONS ******************************/

/***************************** LOCAL CONSTANTS ********************************/

/***************************** LOCAL VARIABLES ********************************/

/** Previous frequency storage */
static uint16_t _previousFrequency = 0;

/***************************** LOCAL FUNCTION DECLARATIONS ********************/
static inline void _SetPeriod(uint16_t period);

/***************************** FUNCTION DEFINITIONS ***************************/

void Pwm_Init()
{
    OC1CON1 = 0u;
    OC1CON2 = 0u;

    Pwm_SetFrequency(_previousFrequency);

    /* configure the PWM */
    OC1CON2 = 0x001F;   /* Sync with This OC module    */
    OC1CON1 = 0x1C08;   /* Clock sourc Fcyc, trigger mode 1, Mode 0 (disable
                           OC1) */
    /* enable the PWM */
    OC1CON1 = OC1CON1 | 0x0006;   /* Mode 6, Edge-aligned PWM Mode */

}

void Pwm_SetFrequency(uint16_t frequency)
{
    uint16_t pwmPeriod;

    pwmPeriod = (FCY) / frequency;
    _SetPeriod(pwmPeriod);

    if (frequency == 0)
    {
        /* enable the PWM */
        OC1CON1 = OC1CON1 & ~0x0007;   /* Mode 0, Output disabled */
    }
    else if (_previousFrequency == 0)
    {
        /* enable the PWM */
        OC1CON1 = OC1CON1 | 0x0006;   /* Mode 6, Edge-aligned PWM Mode */
    }

    _previousFrequency = frequency;
}

static inline void _SetPeriod(uint16_t period)
{
    /* set PWM duty cycle to 50% */
    OC1R    = period >> 1; /* set the duty cycle to 50% */
    OC1RS   = period - 1;  /* set the period */
}