#ifndef DCMOTORMANAGER_H
#define DCMOTORMANAGER_H
#include "Structs.h"
#include "util.h"
#include <fstream>
#include <string>
#include <sstream>
#include <deque>
#include <iomanip>
#include "util.h"
#include "PWMuniv.h"
#include "GPIOUniv.h"
#include <unistd.h>
#include <stdlib.h>  // Para transformar el argv en un entero

using namespace BBB;
using namespace std;

class DcMotorManager
{

    //!@brief Velocidades del motor DC
    enum DCMOTOR_VELOCITY{
        LOW_VELOCITY    = 1500000,
        HIGH_VELOCITY   = 2000000,
    };
public:

    DcMotorManager();

    //!<@brief Mueve el motor hacia delante
    void move_front();

    //!<@brief Mueve el motor hacia atras
    void move_back();

    //!<@brief Establee la velocidad del motor de DC
    void set_velocity(DCMOTOR_VELOCITY);

private:

    GPIO gpio_front;
    GPIO gpio_back;
    PWM pwm;

};

#endif // DCMOTORMANAGER_H
