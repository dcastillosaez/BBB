#!/bin/bash
#Configuracion de comandos rapidos

alias bbb_set_permisions='sudo chown -Rf odroid /home/odroid/BBB/* && sudo chgrp -Rfv odroid /home/odroid/BBB/*'

#alias bbb_kill_applications='/home/odroid/BBB/application_terminate.sh'

alias update_repo='cd "$HOME"/BBB && git pull'

alias actualizar='sudo apt-get update -y && sudo apt-get upgrade -y'

#Realiza una copia de seguridad de todo el repositorio en el directorio /temp/backups
#alias copia_seguridad='cd /home/odroid/BBB/scripts/ && ./security_copy.sh'

alias limpia_cache='sudo rm -Rf  /home/odroid/.cache/chromium/Default/Cache/* && sudo rm -Rf  /home/odroid/.cache/chromium/Default/Media Cache/*'

