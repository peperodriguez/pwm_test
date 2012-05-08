#include "dspic30f_additional_settings.h"
#include "dspic30f3010_pwm.h"


void init_pwm(int f)
{
	//Preescalado mínimo que voy a necesitar
	int pre = PWM_KF/f;
	
	if( f < 15 ) return;

	if( 1 > pre )
		pre = 0;
	else if( 4 > pre )
		pre = 1;
	else if( 16 > pre )
		pre = 2;
	else
		pre = 3;

	PTPER = (FCY/f)/(1<< (pre*2));

	// Independientes y negados
	PWMCON1 = 0x077;
	PTCON = 0x8000 | (pre<<2);

	return;
	
}

void set_dc(int dc)
{
	PDC1 = dc*(2*PTPER/100);
	PDC2 = dc*(2*PTPER/100);
	PDC3 = dc*(2*PTPER/100);
}