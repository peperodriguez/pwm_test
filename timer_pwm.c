#include "timer_pwm.h"


unsigned int ms_crono[MAX_N_CRONOS];

void init_timer(void)
{
	unsigned int k;
	ms = 0;
	for(k = 0 ; k < MAX_N_CRONOS ; k++){
		ms_crono[k] = 0;
	}
	TMR1 = 0;
	PR1 = 29480;
	IFS0bits.T1IF = 0;
	IEC0bits.T1IE = 1;
	T1CON = 0x8000;
}

void __attribute__((interrupt,no_auto_psv)) _T1Interrupt(void)
{
	IFS0bits.T1IF = 0;
	
	for(k = 0 ; k < MAX_N_CRONOS ; k++){
		if(ms_crono[k]){
			ms_crono[k]--;
		}
	}
}

int start_crono(unsigned int uiMs )
{
	int iRet = -1;
	unsigned int k;

	k = 0;

	while( k < MAX_N_CRONOS ){
		if(0 == ms_crono[k]){
			ms_crono[k] = uiMs;
			iRet = (int)k;
			break;
		}
	}	
	
	return iRet;
}

unsigned int is_crono_finished(unsigned int uiCrono)
{
	unsigned int uiRet = 0;
	if(MAX_N_CRONOS > uiCrono){
		if( 0 == ms_crono[uiCrono] )
			uiRet = 1;
	}
	return uiRet;
}