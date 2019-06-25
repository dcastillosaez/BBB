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
        LOW_VELOCITY    = 1200000,
        HIGH_VELOCITY   = 2000000,
    };
public:

    DcMotorManager();

    //!<@brief Mueve el motor hacia delante
    void move_forward();

    //!<@brief Mueve el motor hacia atras
    void move_back();

    //!<@brief Mueve el motor hacia la derecha
    void move_right();

    //!<@brief Mueve el motor hacia la izquierda
    void move_left();

    //!<@brief Detiene el motor de la derecha
    void stop_motor_right();

    //!<@brief Detiene el motor de la izquierda
    void stop_motor_left();

    //!<@brief Establee la velocidad del motor de DC
    void set_velocity(int motor_id,DCMOTOR_VELOCITY);

private:

    GPIO* gpio_forward_right;
    GPIO* gpio_forward_left;
    GPIO* gpio_back_right;
    GPIO* gpio_back_left;
    PWM* pwm_right_motors;
    PWM* pwm_left_motors;

};

#endif // DCMOTORMANAGER_H

