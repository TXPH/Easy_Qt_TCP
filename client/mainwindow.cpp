#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHostAddress>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    QObject::connect(socket,SIGNAL(error(QAbstractSocket::SocketError)),
                     this,SLOT(onError(QAbstractSocket::SocketError)));
    socket->connectToHost("192.168.3.41",1111);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onError(QAbstractSocket::SocketError socketError)
{
    QMessageBox::critical(this,"警告！","套接字错误！");
}
