#include <QCoreApplication>
#include "util.h"
#include "PWMuniv.h"
#include "GPIOUniv.h"
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>
#include <sstream>
#define ADC_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"
using namespace BBB;
using namespace std;

int readAnalog(int number){
    stringstream ss;
    ss << ADC_PATH << number << "_raw";
    fstream fs;
    fs.open(ss.str().c_str(), fstream::in);
    fs >> number;
    fs.close();
    return number;
}


int main(int argc, char *argv[])
{

    //Configuramos el GPIO P9_22 como PWM
    PWM pwm_left_motors(PWM::P9_22);
    pwm_left_motors.setPolarity(PWM::ACTIVE_HIGH);
    pwm_left_motors.setPeriod((unsigned int)25000);
    pwm_left_motors.setDutyCycle((unsigned int)15000);
    cout << "ADC running" << endl;
    for (;;)
    {
    int value = readAnalog(0);
    cout << "The ADC value is " << value << " out of 4095." << endl;
    usleep(100000);
    }
    return 0;


    return 0;
}
