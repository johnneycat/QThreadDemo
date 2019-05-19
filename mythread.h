#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>

class Mythread : public QObject
{
    Q_OBJECT
public:
    explicit Mythread(QObject *parent = nullptr);
    void closeThread();
public slots:
    void startThreadSlot();

private:
    volatile bool isStop;


};

#endif // MYTHREAD_H
