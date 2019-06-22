#!/bin/bash
export SLOTS=/sys/devices/platform/bone_capemgr/slots
echo cape-universaln > $SLOTS
config-pin -q P9.22
config-pin P9.22 pwm
echo "Universal_Cape_Configurado" > /home/debian/log.txt
