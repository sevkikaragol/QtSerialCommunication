#include "udp.h"

udp::udp(QObject *parent) : QObject(parent)
{


    socket = new QUdpSocket();
    socket->bind(QHostAddress(ipAdresi),1234);


    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
}

void udp::veriAktarimi(QByteArray veri)
{


   qDebug() << "veri aktarimi fonksiyonu calisti";
    QByteArray data;
    data.append(veri);

    //data.append("Hello from UDP ");
    socket->writeDatagram(data,QHostAddress(ipAdresi),1234);


}

void udp::readyRead()
{
    QByteArray buffer;
    buffer.resize(socket->pendingDatagramSize());

    QHostAddress sender;
    uint16_t senderPort;

    socket->readDatagram(buffer.data(),buffer.size(),&sender,&senderPort);
    qDebug() << "Message from: " << sender.toString();
    qDebug() << "Message port: " << senderPort;
    qDebug() << "Message: " << buffer;
}


