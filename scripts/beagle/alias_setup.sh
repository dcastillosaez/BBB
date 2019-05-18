#!/bin/bash
#Configuracion de comandos rapidos

alias bbb_set_permisions='sudo chown -Rf debian /home/debian/BBB/* && sudo chgrp -Rfv debian /home/debian/BBB/*'

#alias bbb_kill_applications='/home/debian/BBB/application_terminate.sh'

alias update_repo='cd /home/debian/BBB && git pull'

alias actualizar='sudo apt-get update -y && sudo apt-get upgrade -y'

#Realiza una copia de seguridad de todo el repositorio en el directorio /temp/backups
#alias copia_seguridad='cd /home/debian/BBB/scripts/ && ./security_copy.sh'

alias limpia_cache='sudo rm -Rf  /home/debian/.cache/chromium/Default/Cache/* && sudo rm -Rf  /home/debian/.cache/chromium/Default/Media Cache/*'

