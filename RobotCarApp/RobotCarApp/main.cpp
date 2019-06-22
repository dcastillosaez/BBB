#include <QCoreApplication>
#include "ServoManager.h"

//Espacios de nombres utilizados
using namespace std;

int main(int argc, char* argv[])
{
    if(argc<2)
    {
        printf("Seleccione como argumento el Paso y Velocidad\n");
        printf("Paso     : [1] Bajo     [2] Medio       [3] Alto  \n");
        printf("Velocidad: [1] Baja     [2] Media       [3] Alta  \n");
        exit(-1);
    }
    //Asignamos velocidades y pasos del servomotor
    char *p;
    long step_conv = strtol(argv[1], &p, 10);
    long time_conv = strtol(argv[2], &p, 10);
    ServoManager servo;
    servo.initMovement(step_conv,time_conv);



}



