#include "p30f3010.h"
#include "dspic30f3010_pwm.h"
#include "timer_pwm.h"

_FOSC(FRC_PLL16)
_FWDT(WDT_OFF)




int main(void)
{
	int dc = 1;	
	init_pwm(100);
	set_dc(dc);
	init_timer();

	while(1){
		if( 0 == ms_crono ){
			dc+=1;
			if( 100 == dc )
				dc = 10;
			set_dc(dc);
			ms_crono = 250;
		}
	}
}



