#!/bin/bash
export SLOTS=/sys/devices/platform/bone_capemgr/slots
echo cape-universaln > $SLOTS
config-pin -q P9.22
config-pin P9.22 pwm
config-pin -q P9.14
config-pin P9.14 pwm
#Configuracion de Pines que actuaran como GPIOS
config-pin P8.7 gpio
config-pin -q P8.7 
config-pin P8.8 gpio
config-pin -q P8.8
config-pin P8.9 gpio
config-pin -q P8.9
config-pin P8.10 gpio
config-pin -q P8.10


