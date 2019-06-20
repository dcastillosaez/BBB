#include <QCoreApplication>
#include "util.h"
#include <fstream>
#include <string>
#include <sstream>
#include <deque>
#include <iomanip>
#include "util.h"
#include "PWMuniv.h"
#include <unistd.h>

//Espacios de nombres utilizados
using namespace BBB;
using namespace std;
int main()
{
    //Cargamos la configuracion del PWM en concreto

    PWM pwm(PWM::P9_22);
    pwm.setDutyCycle((unsigned)510000);
    pwm.setPolarity(PWM::ACTIVE_HIGH);
    pwm.setPeriod(20000000);  //50kHz (20ms)
    pwm.setDutyCycle((unsigned)0);
    pwm.run();
    printf("Inicio de bucle\n");
    int min_val=500000;
    int max_val=2000000;
    for (int i=min_val; i<max_val; i+=25000) {
        unsigned int duration=i;
        pwm.setDutyCycle(duration);
        usleep(5*1000*100);
        printf("Iteracion %d\n",i);
        pwm.run();
    }
    pwm.stop();
    return 0;
}



