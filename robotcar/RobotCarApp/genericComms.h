//! @file GenericComms.h
//! @brief Communication Class. Create ServerUDP and analyze sockets information
//! @author dcastillo
//! @date 07/05/2019
#pragma once
#include <QObject>
#include <QUdpSocket>
#include <QMutex>
#include <QtCore/QObject>
#include <QtCore/QThread>
#include <QSharedPointer>
#include <QtCore/QSharedPointer>
#include <QtNetwork/QHostAddress>
#include <QIODevice>
#include <QMetaMethod>
#include "genericsocket.h"

#include <arpa/inet.h>


namespace Communications_Message
{

    enum Result_Message{
        MessageSendERROR        = 1,    //Error al enviar el mensaje
        MessageSendOK           = 2,    //Mensaje enviado correctamente
        MessagerReceiveERROR    = 3,    //Error al recibir el mensaje
        MessageReceiveOK        = 4     //Mensaje recibido correctamente
    };
    enum Rol_ID
    {
        None                    = 0,    //Valor por Defecto
        ServoManager            = 1,    //
        DCMotorManager          = 1,    //

    };
}

typedef Communications_Message::Result_Message ECommunicationsResult_Message;
typedef Communications_Message::Rol_ID ECommunicationsRol_ID;


//! @brief
struct GenericMsgHeader {
    int msgId;
    int size;
};

//! @brief
struct GenericMsg {
    GenericMsgHeader header;
    char*            payload;

    GenericMsg() {
        payload = 0;
    }

    ~GenericMsg() {
        if(payload)
            delete[] payload;
    }

};




//!@brief LanMessage: Estructura definida para los mensajes de los socket.
struct LanMessage{

    QHostAddress            fromHost;           //Host Origen
    QHostAddress            toHost;             //Host Destino
    quint16                 fromPort;           //Puerto Origen
    quint16                 toPort;             //Puerto Destino
    ECommunicationsRol_ID   rol_origin;         //Rol que envia el mensaje de red
    ECommunicationsRol_ID   rol_destiny;        //Rol que recibe el mensaje de red
    quint32                 dataSize;           //Tamaño de los datos del mensaje
    char*                   data;               //Datos del mensaje

    LanMessage(){
        fromPort    = 0;
        toPort      = 0;
        dataSize    = 0;
        data        = nullptr;
        rol_origin  = Communications_Message::Rol_ID::None;
        rol_destiny  =Communications_Message::Rol_ID::None;

    }

    ~LanMessage(){
        if(data){
            delete[] data;
            data = nullptr;
        }
    }
};


        //---------- C L A S E   D E   C O M U N I C A C I O N E S -----------//

class GenericComms: public QThread
{
    Q_OBJECT

    public:

        bool isConnected();

        QUdpSocket* mSendingSocket_ = nullptr;
        QHash<int, GenericSocket*> comm_hash_;        //Has que contiene todos los sockets con su identificador

        GenericComms();
        ~GenericComms();

        //!@brief Metodo que establece una nueva comunicacion
        //!@param Metodo que lee del buffer y procesa los datos

    public slots:

        //!@brief Metodo que lee del buffer y procesa los datos
        void readPendingDatagrams(int socketID);

        //!@brief Metodo que escribe el datagrama, ya sea el cliente o el servidor
        //!@param datagram-> Datagrama de datos que se desea enviar
        //!@param length_-> Longitud del datagrama que se desea enviar
        //!@param sendIp-> Direccion IP a la que se desea enviar
        //!@param sendPort->Puerto al que se desea enviar
        int WriteDatagram(const char* datagram, qint64 length_,QHostAddress sendIp, int sendPort);

        //!@brief Create new communication with a rol given
        int createComs(QString address, unsigned int port);

        //!@brief Set a UDP server given a IP direction and port
        //!
        void setServerUDP(GenericSocket* socket, QString receiveIp, int ReceivePort);

    signals:

        void lanNotification(); //LanMessage* message

        void signalLanMessageReady(GenericMsg*, int socket);

    protected:

        int sendMsg(GenericMsg* msg, QString address, int port);

    protected slots:

        virtual void onLanNotification(GenericMsg* msg, int socketID) = 0;

    private:
        //Sockets fro reception and sending
        //Variables for storing the address of who is going to receive the data
        QHostAddress    mSendIp;               //Direccion IP de destino
        QHostAddress    mReceiveIp;            //Direccion IP local (de recepcion)
        int             mSendPort;             //Puerto al que se desea enviar
        int             mReceivePort;          //Puerto del que se envia
        bool            mVerbose;

        QMutex          getMessageMtx;         //Mutex para obtener y leer el mensaje
        int             comIdGenerator_;       //Generador de id de comunicación. Crea un id para cada comunicación creada.

        QThread comms_thread_;                 // Hilo para correr nuestra librería

        int sock_count = 0;

    };

}

