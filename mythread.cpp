#include "mythread.h"
#include <QThread>
#include <QDebug>

Mythread::Mythread(QObject *parent) : QObject(parent)
{
    isStop = false;
}



void Mythread::closeThread()
{
    isStop = false;
}

void Mythread::startThreadSlot()
{
    qDebug() << "world   A";
    while (1)
    {
        if(isStop)
            return;
        qDebug() << "world  B";
        qDebug()<<"MyThread::startThreadSlot QThread::currentThreadId()=="<<QThread::currentThreadId();
        QThread::sleep(1);
    }
}
