#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QDir>//klasor olusturmak icin eklendi.
#include <QDateTime> //klasor olustururken sistem zamanına gore olusturmak icin eklendi.
#include <QFile> // dosya olusturma islemleri icin.


class workerThread : public QThread
{
    Q_OBJECT
public:
    explicit workerThread(bool flag);
    void run();
    void writeFile();

    uint8_t gpsId,sicaklikId,imuId;
    int64_t latitude,altitude,longtitude;
    uint16_t sicaklikKelvin;
    int64_t accelerationX,accelerationY,accelerationZ;
    QString filePath;
    bool flag;
signals:

};

#endif // WORKERTHREAD_H
