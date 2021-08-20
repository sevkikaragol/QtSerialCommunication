#include "loggerthread.h"
#include "workerthread.h"

LoggerThread::LoggerThread(bool flag,workerThread *workerClone)
{

 this->flag = flag;
 this->workerClone = workerClone;


}

void LoggerThread::run(){


    QStringList veriler;

//veri parcalama islemleri baslangic
   if(flag==true){
        qDebug() << "logger veriler :" << data;
        veriler = data.split(',');


        gpsId = veriler.at(0).toUInt();
        latitude = veriler.at(1).toInt();
        longtitude = veriler.at(2).toInt();
        altitude = veriler.at(3).toInt();
        sicaklikId = veriler.at(4).toUInt();
        sicaklikKelvin = veriler.at(5).toUInt();
        imuId = veriler.at(6).toUInt();
        accelerationX = veriler.at(7).toInt();
        accelerationY = veriler.at(8).toInt();
        accelerationZ = veriler.at(9).toInt();

        workerClone->flag = true;
        flag=false;
        }

}

