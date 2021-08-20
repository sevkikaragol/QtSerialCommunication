#ifndef LOGGERTHREAD_H
#define LOGGERTHREAD_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QSerialPort>
#include "workerthread.h"
#include <QFile>


class LoggerThread : public QThread
{
    Q_OBJECT
public:
    explicit LoggerThread(bool flag,workerThread *workerClone);
    void run();
    workerThread *workerClone;
    QString data;
    bool flag;
    uint8_t gpsId,sicaklikId,imuId;
    int64_t latitude,altitude,longtitude;
    uint16_t sicaklikKelvin;
    int64_t accelerationX,accelerationY,accelerationZ;


signals:

};

#endif // LOGGERTHREAD_H
