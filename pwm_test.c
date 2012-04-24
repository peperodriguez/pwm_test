#include "dspic30f3010.h"
#include "dspic30f_additional_settings.h"
#include "dspic30f3010_pwm.h"


_FOSC(FRC_PLL16)
_FWDT(WDT_OFF)

int main(void)
{
	//PWM Module Init.
	// - T = 10 ms
	// - DC = from 50% to 90% changing 1% every 250ms
	
	return 0;
}