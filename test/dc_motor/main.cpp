#include <QCoreApplication>
#include "DcMotorManager.h"
int main()
{
    int opcion;
    char if_continue;
    DcMotorManager dc_manager;
    while(1)
    {
        printf("Comienzo del programa.... Coja el coche\n");
        printf("Seleccione el comando deseado: \n");
        printf("OPCION [1] : MOVER_HACIA_DELANTE\n");
        printf("OPCION [2] : MOVER_HACIA_DETRAS\n");
        printf("OPCION [3] : MOVER_HACIA_DERECHA\n");
        printf("OPCION [4] : MOVER_HACIA_IZQUIERDA\n");
        scanf("%d",opcion);
        switch(opcion)
        {
        case 1:
            dc_manager.move_forward();
            break;
        case 2:
            dc_manager.move_back();
            break;
        case 3:
            dc_manager.move_right();
            break;
        case 4:
            dc_manager.move_left();
            break;
        }

        sleep(3);
        dc_manager.stop_motor_left();
        dc_manager.stop_motor_right();
        printf("¿Desea continuar con el programa? (S/N)\n");
        scanf("%c",if_continue);
        if(if_continue=='N' || if_continue=='n')
        {
            printf("PROGRAMA FINALIZADO\n");
            exit(0);
        }

    }

    return 0;
}
