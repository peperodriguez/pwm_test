#ifndef _DSPIC30F3010_PWM_H_
#define _DSPIC30F3010_PWM_H_

#define MIN_PWM_PERIOD_US 10

void init_pwm(unsigned int uiPeriodUs);
void set_dc(unsigned int uiDCPercentage);
void start_pwm(unsigned int uiDCPercentage);
void stop_pwm(void);


#endif //_DSPIC30F3010_PWM_H_