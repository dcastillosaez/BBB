#include "genericComms.h"

using namespace GenericCommunications;

static GenericComms* sThis = nullptr;


GenericComms::GenericComms()
{
    mSendingSocket_ = new QUdpSocket(this);
}

GenericComms::~GenericComms()
{
    if(mSendingSocket_)
        mSendingSocket_->deleteLater();
    for (QUdpSocket* socket : comm_hash_.values())
        socket->deleteLater();
}

int GenericComms::createComs(QString address, unsigned int port)
{
    GenericSocket* socket = new GenericSocket(this);
    QObject::connect(socket, SIGNAL(signalReadyMessage(int)), this, SLOT(readPendingDatagrams(int)));
    qDebug() << "Communication created at [GENERIC_COMS]. Reception socket in Address: "
             << address << "  Port:  " << port;
    setServerUDP(socket, address, port);
    comm_hash_[socket->getSocketID()] = socket;  //Almacenamos el socket en la lista
    return socket->getSocketID();                //Devuelve el identificador del socket
}

int GenericComms::sendMsg(GenericMsg* msg, QString address, int port)
{
    QHostAddress addr(address.toStdString().c_str());
    int dataSize = sizeof(GenericMsgHeader) + msg->header.size;
    char* data = new char[dataSize];
    memcpy(data, msg, sizeof(GenericMsgHeader));
    memcpy(data + sizeof(GenericMsgHeader), msg->payload, msg->header.size);
    int result = WriteDatagram(data, dataSize, addr, port);
    delete data;
    return result;
}

int GenericComms::WriteDatagram(const char* datagram, qint64 length_, QHostAddress sendIp, int sendPort)
{
    quint16 port_number = sendPort;
    QByteArray datos;
    datos = QByteArray((char*)datagram, length_);
    int result = mSendingSocket_->writeDatagram(datagram, length_, sendIp, port_number);
    return result;
}


void GenericComms::readPendingDatagrams(int socketID)
{
    GenericMsg* msg = new GenericMsg;   //Definimos una nueva estructura
    QUdpSocket* socket = comm_hash_[socketID];
    if (socket->hasPendingDatagrams()){
        QByteArray datagram;
        datagram.resize(socket->pendingDatagramSize());
        socket->readDatagram(datagram.data(), datagram.size());
        memcpy(msg, datagram.data(), sizeof(GenericMsgHeader));
        msg->payload = new char[msg->header.size];
        memcpy(msg->payload, datagram.data() + sizeof(GenericMsgHeader), msg->header.size);
    }
    emit signalLanMessageReady(msg, socketID);
}


void GenericComms::setServerUDP(GenericSocket *socket, QString ReceiveIp, int ReceivePort)
{
    QHostAddress host(ReceiveIp);
    if(!socket->bind(QHostAddress::AnyIPv4, ReceivePort)){
       qCritical() << socket->errorString();
       qCritical() << "[GENERIC_COMS] Failed to bind " << ReceivePort;
       exit(-1);
    }

    if(!socket->open(QIODevice::OpenModeFlag::ReadWrite))
    {
        qCritical() << socket->errorString();
        qCritical() << "[GENERIC_COMS] Failed to open ";
        exit(-1);
    }
}

bool GenericComms::isConnected()
{
    static const QMetaMethod valueChangedSignal = QMetaMethod::fromSignal(&QUdpSocket::readyRead);
    bool isConnected_ = QObject::isSignalConnected(valueChangedSignal);

    if(!isConnected_)
    {
        QObject::connect(mSendingSocket_, SIGNAL(readyRead()), this, SLOT(ReadPendingDatagrams()));
    }

    return isConnected_;
}





