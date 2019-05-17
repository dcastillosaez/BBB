#!/bin/bash
#Configuracion de comandos rapidos

alias bbb_set_permisions='sudo chown -Rf odroid /home/odroid/BBB/* && sudo chgrp -Rfv odroid /home/odroid/BBB/scripts/*'
export bbb_set_permisions
#alias bbb_kill_applications ='$SCRIPTS/application_terminate.sh'

alias actualizar_repositorio ='cd /home/odroid/BBB/ && sudo git pull'
export actualizar_repositorio

alias actualizar='sudo apt-get update -y && sudo apt-get upgrade -y'
export actualizar
#Realiza una copia de seguridad de todo el repositorio en el directorio /temp/backups
alias copia_seguridad='cd /home/odroid/BBB/scripts/ && ./security_copy.sh'
export copia_seguridad

alias limpiar_cache='sudo rm -Rf  /home/odroid/.cache/chromium/Default/Cache/* && sudo rm -Rf  /home/odroid/.cache/chromium/Default/Media Cache/*'
export limpiar_cache
