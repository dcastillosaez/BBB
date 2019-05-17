#!/bin/bash
#Configuracion de comandos rapidos

alias bbb_set_permisions=`sudo chown -Rf debian $HOME/BBB/* && sudo chgrp -Rfv debian $HOME/BBB/*`

#alias bbb_kill_applications ='$SCRIPTS/application_terminate.sh'

alias actualizar_repositorio =`cd $HOME/BBB/ && sudo git pull`

alias actualizar='sudo apt-get update -y && sudo apt-get upgrade -y'

#Realiza una copia de seguridad de todo el repositorio en el directorio /temp/backups
alias copia_seguridad=`cd $HOME/BBB/scripts/ && ./security_copy.sh`

alias limpia_cache='sudo rm -Rf  /home/odroid/.cache/chromium/Default/Cache/* && sudo rm -Rf  /home/odroid/.cache/chromium/Default/Media Cache/*'

