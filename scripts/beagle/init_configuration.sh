#!/bin/bash
#Initial System Configuration 
#Load Universal_Cape
#export SLOTS=/sys/devices/platform/bone_capemgr/slots
#echo BB-PWM0 > $SLOTS

export SLOTS=/sys/devices/platform/bone_capemgr/slots
echo cape-universaln > $SLOTS
config-pin -q P9.22
config-pin P9.22 pwm
