#include "dspic30f_additional_settings.h"
#include "dspic30f3010_pwm.h"


void stop_pwm(void)
{
	PTCON &= ~0x8000;
}

void init_pwm(unsigned int uiPeriodUs)
{
	if( 0 == uiPeriodUs ) {
		return;
	} 
	else if( MIN_PWM_PERIOD_US > uiPeriodUs ){
		uiPeriodUs = MIN_PWM_PERIOD_US;
	}

    uiPeriodUs = (uiPeriodUs/MIN_PWM_PERIOD_US)*MIN_PWM_PERIOD_US;

	PTCON = 0x0;	// 1:1 prescaler
					// pwm Modulo disabled


	
}