#include "ServoManager.h"


//Espacios de nombres utilizados
ServoManager::ServoManager()
{
}

void ServoManager::initMovement(long step_conv, long velocity_conv)
{

    //Cargamos la configuracion del PWM en concreto
    int step=step_conv;
    int time=velocity_conv;
    printf("Paso escogido\n: %d", step);
    printf("Tiempo de delay escogido\n: %d", time);
    //SERVO_STEP servo_step;
    if(step==1)
    {
       servo_step=LOW_STEP;
    }
    else if(step==2)
    {
       servo_step=MEDIUM_STEP;
    }
    else if(step==3)
    {
       servo_step=HIGH_STEP;
    }
    else
        exit(-1);

    if(time==1)
    {
       servo_velocity=LOW_VELOCITY;
    }
    else if(time==2)
    {
       servo_velocity=MEDIUM_VELOCITY;
    }
    else if(time==3)
    {
       servo_velocity=HIGH_VELOCITY;
    }
    else
        exit(-1);

    PWM pwm(PWM::P9_22);
    pwm.setDutyCycle((unsigned)500000);
    pwm.setPolarity(PWM::ACTIVE_HIGH);
    pwm.setPeriod(20000000);  //50kHz (20ms)
    pwm.setDutyCycle((unsigned)0);
    pwm.run();
    printf("Inicio de bucle\n");
    int min_val=500000;
    int max_val=2650000;
    for (int i=min_val; i<max_val; i+=servo_step) {
        unsigned int duration=i;
        pwm.setDutyCycle(duration);
        usleep(servo_velocity);
        printf("Iteracion %d\n",i);
        pwm.run();
    }
    for (int i=max_val; i>=min_val; i-=step) {
        unsigned int duration=i;
        pwm.setDutyCycle(duration);
        usleep(servo_velocity);
        printf("Iteracion %d\n",i);
        pwm.run();
    }
    pwm.stop();
}
