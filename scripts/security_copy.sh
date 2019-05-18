#!/bin/bash

#COPIA DE SEGURIDAD DE LOS ARCHIVOS
PATH=/var/backups/
#borramos la anterior coia de seguridad
if [ -f $PATH/Documents.tar.gz ]
then
	rm -Rf Documents.tar.gaz
fi
#Ahora hacemos la nueva copia de seguridad
tar -zcvf /var/backups/Documents.tar.gz /home/odroid/
