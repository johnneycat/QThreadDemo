#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


class Worker : public QObject
{
    Q_OBJECT

public slots:
    void doWork(const QString &parameter) {

        //emit resultReady(result);
        qDebug() << "hEllo world";
    }

signals:
    void resultReady(const QString &result);
};




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    subthread =  new QThread;;
    work = new Mythread;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_released()
{
    qDebug()<<"mainWidget QThread::currentThreadId()=="<<QThread::currentThreadId();


    work->moveToThread(subthread);

    connect(subthread,SIGNAL(finished()),subthread,SLOT(deleteLater()));        //终止线程时要调用deleteLater槽函数
    connect(subthread,SIGNAL(started()),work,SLOT(startThreadSlot()));  //开启线程槽函数
    //connect(subthread,SIGNAL(finished()),this,SLOT(finishedThreadSlot()));

    subthread->start();

 //   work->startThreadSlot();

    qDebug() << "subthread started!";




}
