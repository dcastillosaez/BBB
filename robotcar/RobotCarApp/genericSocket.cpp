#include "genericSocket.h"

static int socketCount = 0;

GenericSocket::GenericSocket(QObject *parent)
    : QUdpSocket(parent)
{
    socketID_ = socketCount++;

    connect(this,SIGNAL(readyRead()),this,SLOT(onMessageReadyRead()));
}

int GenericSocket::getSocketID()
{
    return socketID_;
}

void GenericSocket::onMessageReadyRead()
{
    emit signalReadyMessage(socketID_);
}
