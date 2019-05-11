#!/bin/bash

#VARIABLES DE ENTORNO
export odroid='/home/odroid/'
export repo_path='/home/odroid/BBB/'
export documentos='/home/odroid/Documents/'

#ALIAS
alias actualiz='apt-get update'
alias actualizar='sudo apt-get update && sudo apt-get upgrade'
alias actualizar_repo='cd /home/odroid/BBB/ && git pull'
alias reiniciar='sudo shutdown -r now'
