#include "DcMotorManager.h"

DcMotorManager::DcMotorManager()
{
    printf("Iniciando constructor \n");
    gpio_forward_right = new GPIO(GPIO::P8_7); //gpio66
    gpio_forward_left   = new GPIO(GPIO::P8_8); //gpio67
    gpio_back_right    = new GPIO(GPIO::P8_9); //gpio69
    gpio_back_left     = new GPIO(GPIO::P8_10);//gpio68

    pwm_left_motors    = new PWM(PWM::P9_22);
    pwm_right_motors   = new PWM(PWM::P9_14);

    gpio_forward_right->setDirection(GPIO::OUTPUT);
    gpio_forward_left->setDirection(GPIO::OUTPUT);
    gpio_back_right->setDirection(GPIO::OUTPUT);
    gpio_back_left->setDirection(GPIO::OUTPUT);

    pwm_left_motors->setPolarity(PWM::ACTIVE_HIGH);
    pwm_left_motors->setPeriod(1000000);  //1kHz
    pwm_right_motors->setPolarity(PWM::ACTIVE_HIGH);
    pwm_right_motors->setPeriod(1000000);  //1kHz
}

void DcMotorManager::move_forward()
{
    gpio_forward_right->setValue(GPIO::HIGH);
    gpio_forward_left->setValue(GPIO::HIGH);
    gpio_back_left->setValue(GPIO::LOW);
    gpio_back_right->setValue(GPIO::LOW);
    set_velocity(1,DCMOTOR_VELOCITY::HIGH_VELOCITY);
    set_velocity(2,DCMOTOR_VELOCITY::HIGH_VELOCITY);

}

void DcMotorManager::move_back()
{
    gpio_forward_right->setValue(GPIO::LOW);
    gpio_forward_left->setValue(GPIO::LOW);
    gpio_back_left->setValue(GPIO::HIGH);
    gpio_back_right->setValue(GPIO::HIGH);
    set_velocity(1,DCMOTOR_VELOCITY::HIGH_VELOCITY);
    set_velocity(2,DCMOTOR_VELOCITY::HIGH_VELOCITY);
}

void DcMotorManager::move_right()
{
    //Los motores de la izquierda deben moverse mas rapido que los de la izquierda
    gpio_forward_right->setValue(GPIO::HIGH);
    gpio_forward_left->setValue(GPIO::HIGH);
    gpio_back_left->setValue(GPIO::LOW);
    gpio_back_right->setValue(GPIO::LOW);
    set_velocity(1,DCMOTOR_VELOCITY::HIGH_VELOCITY);
    set_velocity(2,DCMOTOR_VELOCITY::LOW_VELOCITY);
}

void DcMotorManager::move_left()
{
    gpio_forward_right->setValue(GPIO::HIGH);
    gpio_forward_left->setValue(GPIO::HIGH);
    gpio_back_left->setValue(GPIO::LOW);
    gpio_back_right->setValue(GPIO::LOW);
    set_velocity(1,DCMOTOR_VELOCITY::LOW_VELOCITY);
    set_velocity(2,DCMOTOR_VELOCITY::HIGH_VELOCITY);
}

void DcMotorManager::stop_motor_right()
{
    pwm_right_motors->stop();
}

void DcMotorManager::stop_motor_left()
{
    pwm_left_motors->stop();
}

void DcMotorManager::set_velocity(int motor_id, DCMOTOR_VELOCITY)
{
    if(motor_id==1) //Parte izquierda
    {
        //Le da un valor al PWM P9_22 que equivale a la velocidad
        pwm_left_motors->setDutyCycle((unsigned)1000000);
        pwm_left_motors->run();
    }
    else
    {
        //Le da un valor al PWM P9_14 que equivale a la velocidad
        pwm_right_motors->setDutyCycle((unsigned)1000000);
        pwm_right_motors->run();
    }

}

