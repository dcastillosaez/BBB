#include <QCoreApplication>
#include "DcMotorManager.h"
int main()
{
    DcMotorManager dc_manager;
    dc_manager.move_front();
    sleep(3);
    dc_manager.move_back();
    sleep(3);
    return 0;
}
