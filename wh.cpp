#include "wh.h"
#include "ui_wh.h"
#include "windows.h"
#include <stdlib.h>
#include <QStyle>
#include <QDesktopWidget>
#include <QTimer>
#include <QTime>
#include <QDir>
#include <QFile>
#include <QStringList>



wh::wh(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::wh)
{
    ui->setupUi(this);

    // минус окно и элементы упраления
    this->setWindowFlags(Qt::CustomizeWindowHint);
    this->setWindowFlags(Qt::FramelessWindowHint);

    // таймер записи и коннект со слотом updateTime
    timer.start(50000);
    connect(&timer, SIGNAL(timeout()), SLOT(updateTime()));

    // таймер отображения и коннект со слотом отображения
    timertxt.start(55000);
    connect(&timertxt, SIGNAL(timeout()), SLOT(updateTimeTXT()));

    // изменение координат
    wh::move(800,5);

}

wh::~wh()
{
    delete ui;
}

void wh::updateTime()
{

    // запуск cmd и запись netstat в файл, скрыто
   WinExec("cmd.exe /c netstat  -n > C:\\RDPREG\\netstat.txt",SW_HIDE);

}

void wh::updateTimeTXT()
{
    // открываем файл
    QFile file("C:\\RDPREG\\netstat.txt");
    file.open(QIODevice::ReadOnly);

    QStringList strList;

    while(!file.atEnd())
    {
        strList << file.readLine();
    }

    QStringList poisk = strList.filter("3389");

    bool pusto = poisk.isEmpty();




    QFile log(QDir::currentPath().append("\\LOG\\").append(QDate::currentDate().toString("yyyy_MM_dd").append(".log")));




    if (!pusto) {

    QString strtr = poisk.at(0);  
    ui->label_2->setText(strtr);
    log.open(QIODevice::Append);
    log.write(QTime::currentTime().toString("hh:mm:ss").toUtf8().append(strtr));
    log.close();
}

    else {

        ui->label_2->setText("PC is not used");
        log.open(QIODevice::Append);
        log.write(QTime::currentTime().toString("hh:mm:ss").toUtf8().append("PC is not used \r\n"));
        log.close();

    }

}


