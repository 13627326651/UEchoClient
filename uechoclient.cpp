#include "uechoclient.h"
#include <QVBoxLayout>

UEchoClient::UEchoClient(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("回声客户端"));
    textEdit = new QTextEdit;
    lineEdit = new QLineEdit;
    sendBtn = new QPushButton(tr("发送"));
    
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(textEdit);
    mainLayout->addWidget(lineEdit);
    mainLayout->addWidget(sendBtn);

    port = 9999;
    socket = new QUdpSocket;

    connect(lineEdit,SIGNAL(returnPressed()),sendBtn,SLOT(click()));
    connect(sendBtn,SIGNAL(clicked(bool)),this,SLOT(sendMessage()));
    connect(socket,SIGNAL(readyRead()),this,SLOT(readMessage()));


}

UEchoClient::~UEchoClient()
{

}

    void UEchoClient::sendMessage()
    {
       text = lineEdit->text();
       lineEdit->clear();
       if(text.trimmed().isEmpty())
           return;

       socket->writeDatagram(text.toLocal8Bit(),QHostAddress(tr("192.168.1.102")),port);
    }

void UEchoClient::readMessage()
{
    QByteArray dataGram;
    if(socket->hasPendingDatagrams())
    {
        dataGram.resize(socket->pendingDatagramSize());
        socket->readDatagram(dataGram.data(),dataGram.size());
        QString msg = dataGram;
        textEdit->append(msg);
    }
}

