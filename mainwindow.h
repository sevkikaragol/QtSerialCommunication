#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include <QDir>//klasor olusturmak icin eklendi.
#include <QDateTime> //klasor olustururken sistem zamanına gore olusturmak icin eklendi.
#include <QFile> // dosya olusturma islemleri icin.



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

   void openSerialPort(QString portSecimi);
   void newLog();

   void serialReceived();
   void closeSerialPort();

   void on_baslat_clicked();
    void on_durdur_clicked();

    void on_newLog_clicked();

private:
    QString senderIp;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
