#include "workerthread.h"
#include "loggerthread.h"



workerThread::workerThread(bool flag)
{
this->flag = flag;
}

void workerThread::run()
{

    if(flag==true){
    qDebug() << "dosyaya yazma islemi basladi." ;
    writeFile();



    }else{
        qDebug() << "else - worker thread run calisti";
    }


}

void workerThread::writeFile()
{

    QString currentTime = QDateTime::currentDateTime().toString("dd.MM.yyyy_hh:mm:ss");

    QFile gpsFile(filePath+"\\gps.csv");

    if(false != gpsFile.open(QIODevice::WriteOnly|QIODevice::Append))
    {
        QTextStream stream( &gpsFile );
        if(gpsFile.size()==0){

            stream << "time" << "," << "latitude" << "," << "longtitude" << "," << "altitude" << endl;
            stream << currentTime << "," << latitude << "," << longtitude << "," << altitude << endl;

        }else{
            stream << currentTime << "," << latitude << "," << longtitude << "," << altitude << endl;
        }

        gpsFile.close();

    }else

    {
    qDebug() << "gps file acilamadi.";

    }


    QFile imuFile(filePath+"\\imu.csv");

    if(false != imuFile.open(QIODevice::WriteOnly|QIODevice::Append))
    {
        QTextStream stream( &imuFile );
        if(imuFile.size()==0){
            stream << "time" << "," << "accelerationX" << "," << "accelerationY" << "," << "accelerationZ" << endl;
            stream << currentTime << "," << accelerationX << "," << accelerationY << "," << accelerationZ << endl;

        }else{
            stream << currentTime << "," << accelerationX << "," << accelerationY << "," << accelerationZ << endl;
        }

        imuFile.close();
    }else
    {
    qDebug() << "imu file acilamadi.";

    }

    QFile sicaklikFile(filePath+"\\sicaklik.csv");

    if(false != sicaklikFile.open(QIODevice::WriteOnly|QIODevice::Append))
    {
        QTextStream stream( &sicaklikFile );
        if(sicaklikFile.size()==0){
            stream << "time" << "," << "sicaklik" << endl;
            stream << currentTime << "," << sicaklikKelvin <<endl;


        }else{
            stream << currentTime << "," << sicaklikKelvin <<endl;
        }
        sicaklikFile.close();
    }else
    {
    qDebug() << "sicaklik file acilamadi.";

    }


}


