#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include "loggerthread.h"
#include "workerthread.h"
#include "udp.h"



QString receiverIp;
QString portSecimi;
QSerialPort *serial;
LoggerThread *loggerThread ;
workerThread *worker;
static bool flag;
udp *server;




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    worker = new workerThread(false);
   // worker->start();

    server = new udp();

    loggerThread = new LoggerThread(flag,worker);
    //loggerThread->start();


    ui->setupUi(this);
    ui->durdur->setVisible(false);

}

void MainWindow::openSerialPort(QString portSecimi){


    serial = new QSerialPort(this);
    if(portSecimi=="1"){
         serial->setPortName("COM2");
    }else{
        serial->setPortName("COM1");
    }

    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);


    connect(serial,SIGNAL(readyRead()),this,SLOT(serialReceived()));

}


void MainWindow::newLog()
{

    QString filePath = QDir::homePath()+"\\Desktop";
    QDir dir(filePath);
    dir.mkdir("SerialPort");
    QString currentTime = QDateTime::currentDateTime().toString("ddMMyyyy_hhmmss");
    dir = filePath +"\\SerialPort";
    dir.mkdir(currentTime);
    filePath = filePath +"\\SerialPort\\"+currentTime;
    dir = filePath;
    if (!dir.exists(filePath))
        qDebug() << "path bulunamadi.";
        dir.mkpath(filePath); // path bulunamadıysa olusturur.

    worker->filePath = filePath;

    /*
    QFile gpsFile(filePath+"\\gps.csv");
    gpsFile.open(QIODevice::WriteOnly);

    QFile imuFile(filePath+"\\imu.csv");
    imuFile.open(QIODevice::WriteOnly);

    QFile sicaklikFile(filePath+"\\sicaklik.csv");
    sicaklikFile.open(QIODevice::WriteOnly);*/






}

void MainWindow::closeSerialPort(){

    if (serial->isOpen())
        qDebug() << " **Com portu kapatildi";
            serial->close();




}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::serialReceived(){

  QByteArray message;
  message = serial->readAll();
  loggerThread->data = message ;
  server->ipAdresi=senderIp;
  server->veriAktarimi(message);


  loggerThread->flag = true;
  loggerThread->run();




  worker->imuId = loggerThread->imuId;
  worker->accelerationX = loggerThread->accelerationX;
  worker->accelerationY = loggerThread->accelerationY;
  worker->accelerationZ = loggerThread->accelerationZ;


  worker->gpsId = loggerThread->gpsId;
  worker->latitude = loggerThread->latitude;
  worker->longtitude = loggerThread->longtitude;
  worker->altitude = loggerThread->altitude;

  worker->sicaklikId = loggerThread->sicaklikId;
  worker->sicaklikKelvin = loggerThread->sicaklikKelvin;


  worker->run();


}



void MainWindow::on_baslat_clicked()
{

    newLog();
   // worker->newLog();
    senderIp = ui->senderIp->text();
    QString receiverIp = ui->receiverIp->text();
    QString portSecimi = ui->portSecimi->currentText();

    if (portSecimi == "--"){
        QMessageBox::information(this,"Uyarı","Port seçimi yapınız!");

    }
    else if(senderIp==""||receiverIp==""){
     QMessageBox::information(this,"Uyarı","Ip girişleri boş bırakılamaz!");
    }

    else{

        qDebug() << "->İletisim baslatildi.";
        ui->newLog->setEnabled(false);
        ui->baslat->setVisible(false);
        ui->durdur->setVisible(true);
        ui->receiverIp->setEnabled(false);
        ui->senderIp->setEnabled(false);
        ui->portSecimi->setEnabled(false);
        //durdurma islemine kadar bilesenler disable durumuna alındı


        openSerialPort(portSecimi);


    }




}


void MainWindow::on_durdur_clicked()
{
    closeSerialPort();
    qDebug() << "\n->İletisim durduruldu.";
    ui->newLog->setEnabled(true);
    ui->durdur->setVisible(false);
    ui->receiverIp->setEnabled(true);
    ui->senderIp->setEnabled(true);
    ui->portSecimi->setEnabled(true);
    ui->baslat->setVisible(true);
    loggerThread->exit();
    worker->exit();
    if(!loggerThread->isRunning()&& !worker->isRunning()){
        qDebug() << "threadler sonlandirildi";
    }

    //durdurma islemi ardından bilesenler aktif hale getirildi.


}


void MainWindow::on_newLog_clicked()
{
    qDebug() << "Log dosyasi olusturuldu";
    newLog();
    //worker->newLog();

}



