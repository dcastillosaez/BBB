#!/bin/sh

REPOSRC=https://github.com/dcastillosaez/BBB.git
LOCALREPO=$HOME/BBB/

# We do it this way so that we can abstract if from just git later on
LOCALREPO_VC_DIR=$LOCALREPO/.git

if [ ! -d $LOCALREPO ]
then
    mkdir $HOME/BBB
fi

if [ ! -d $LOCALREPO_VC_DIR ]
then
    git clone $REPOSRC $LOCALREPO
    echo "Repositorio clonado" >>/root/bootlog.txt
else
    cd $LOCALREPO
    git pull $REPOSRC
    echo "Repositorio actualizado en $HOME/BBB" >>/root/bootlog.txt
    apt-get update -y && apt-get upgrade -y 
    echo "ODROID ACTUALIZADA en /$HOME/BBB" >>/root/bootlog.txt
    
fi

#Montar la unidad USB
usb_path=/media/usb

if [ -d usb_path]
then
	echo "Ya existe path /media/usb" >>/root/bootlog.txt
else
	mkdir /media/usb/
fi

# End
