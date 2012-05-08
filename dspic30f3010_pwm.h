#ifndef _DSPIC30F3010_PWM_H_
#define _DSPIC30F3010_PWM_H_

#include "timer_pwm.h"

#define PWM_KF	((FCY)/((2^15)-1))

void init_pwm(int f);
void set_dc(int dc);

#endif //_DSPIC30F3010_PWM_H_