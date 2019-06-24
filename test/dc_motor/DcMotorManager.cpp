#include "DcMotorManager.h"

DcMotorManager::DcMotorManager()
{
    gpio_front= new GPIO(GPIO::P8_7);
    gpio_back= new GPIO(GPIO::P8_8);
    pwm= new PWM(PWM::P9_22);
    gpio_front->setDirection(GPIO::OUTPUT);
    gpio_back->setDirection(GPIO::OUTPUT);
    pwm->setPolarity(PWM::ACTIVE_HIGH);
    pwm->setPeriod(1000000);  
}

void DcMotorManager::move_front()
{
    //Activamos el GPIO 66 y desactivamos el GPIO67
    gpio_front->setValue(GPIO::HIGH);
    gpio_back->setValue(GPIO::LOW);
    set_velocity(DCMOTOR_VELOCITY::HIGH_VELOCITY);

}

void DcMotorManager::move_back()
{
    //Activamos el GPIO 67 y desactivamos el GPIO66
    gpio_back->setValue(GPIO::HIGH);
    gpio_front->setValue(GPIO::LOW);
    set_velocity(DCMOTOR_VELOCITY::HIGH_VELOCITY);
}

void DcMotorManager::set_velocity(DCMOTOR_VELOCITY)
{
    //Le da un valor al PWM P9_22 que equivale a la velocidad
    pwm->setDutyCycle((unsigned int)1000000);
    pwm->run();
}


void DcMotorManager::stop_pwm()
{
   pwm->stop();
}
