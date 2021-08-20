#ifndef UDP_H
#define UDP_H

#include <QObject>
#include <QUdpSocket>

class udp : public QObject
{
    Q_OBJECT
public:
    explicit udp(QObject *parent = nullptr);
    void veriAktarimi(QByteArray veri);
    QString ipAdresi;


signals:

public slots:
    void readyRead();


private:
    QUdpSocket *socket;

};

#endif // UDP_H
