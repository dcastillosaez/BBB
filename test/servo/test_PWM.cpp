
#include <fstream>
#include <string>
#include <sstream>
#include <deque>
#include <iomanip>
#include "util.h"
#include "PWMuniv.h"

//Espacios de nombres utilizados
using namespace BBB;
using namespace std;
PWM pwmr(PWM::P9_14);
pwmg.setDutyCycle(99.0f);
pwmr.setPolarity(PWM::ACTIVE_HIGH);
pwmr.setPeriod(1000000);  //1kHz
pwmr.setDutyCycle((unsigned)0);
pwmr.run();
			
			
/*EJEMPLO 2*/

cout << "PWM running" << endl;
PWM pwm("pwmchip0/pwm0");//P9_22
pwm.setPeriod(20000000);         //50Hz     
pwm.setDutyCycle((unsigned)510000); 
pwm.setPolarity(PWM::ACTIVE_LOW);  
pwm.run();
for (int i=0; i<50; i++) {
	int value = readAnalog(0); //Leo el valor del potenciometro (QUE SERA DEL ULTRASONIDOS)
	unsigned duty_ref = 423*value + 470000; //duty ref entre 470000 y 2200000
	pwm.setDutyCycle(duty_ref);
	usleep(1000000);
}
pwm.stop();
cout << "PWM exit" << endl; 
return 0;int main() {
cout << "PWM running" << endl;
PWM pwm("pwmchip0/pwm0");
pwm.setPeriod(20000000); //50Hz
pwm.setDutyCycle((unsigned)510000);
pwm.setPolarity(PWM::ACTIVE_LOW);
pwm.run();
for (int i=0; i<100; i++) {
pwm.setDutyCycle((unsigned)2350000);
usleep(1000000);
pwm.setDutyCycle((unsigned)500000);
usleep(1000000);
}
pwm.stop();
cout << "PWM exit" << endl;
return 0;




//EJEMPLO INICIAL DEL PDF
