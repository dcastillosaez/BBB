#ifndef GENERICSOCKET_H
#define GENERICSOCKET_H

#include <QUdpSocket>

class GenericSocket : public QUdpSocket
{
    Q_OBJECT

    public:

        explicit GenericSocket(QObject *parent = Q_NULLPTR);

        int getSocketID();

    signals:

        void signalReadyMessage(int sockedID);

    private:

        int socketID_;

    private slots:

        void onMessageReadyRead();

};

#endif // GENERICSOCKET_H
