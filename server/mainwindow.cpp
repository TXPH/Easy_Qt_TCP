#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHostAddress>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    server = new QTcpServer(this);
    QObject::connect(server,SIGNAL(newConnection()),
                     this,SLOT(onNewConnection()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_listen_clicked()
{
    if(server->isListening())
    {
        ui->te_show->append("已经开始监听......");
        return ;
    }
    if(server->listen(QHostAddress::Any,1111))
    {
        ui->te_show->append("成功监听端口号：1111");
    }
    else ui->te_show->append("监听失败");
}
void MainWindow::onNewConnection()
{
    ui->te_show->append("有用户连接至服务器");
}
