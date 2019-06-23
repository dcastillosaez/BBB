#ifndef SERVOMANAGER_H
#define SERVOMANAGER_H
#include "Structs.h"
#include "util.h"
#include <fstream>
#include <string>
#include <sstream>
#include <deque>
#include <iomanip>
#include "util.h"
#include "PWMuniv.h"
#include <unistd.h>
#include <stdlib.h>  // Para transformar el argv en un entero

//!@brief Se definen las distintas velocidades a las que gira el servomotor
enum SERVO_VELOCITY{
    LOW_VELOCITY    = 20000,
    MEDIUM_VELOCITY = 15000,
    HIGH_VELOCITY   = 10000,
};

//typedef SERVO_VELOCITY SERVO_VELOCITY_ID;
//!@brief Se definen los modos de paos del Servomotor
enum SERVO_STEP{
    LOW_STEP    = 10000,
    MEDIUM_STEP = 15000,
    HIGH_STEP   = 20000,
};

using namespace BBB;
using namespace std;

class ServoManager
{
        SERVO_STEP      servo_step;
        SERVO_VELOCITY  servo_velocity;

public:

    ServoManager();

    void initMovement(long step_conv, long velocity_conv);
};

#endif // SERVOMANAGER_H
