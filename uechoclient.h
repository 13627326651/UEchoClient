#ifndef UECHOCLIENT_H
#define UECHOCLIENT_H

#include <QUdpSocket>
#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>

class UEchoClient : public QWidget
{
    Q_OBJECT

public:
    UEchoClient(QWidget *parent = 0);
    ~UEchoClient();
private slots:
    void sendMessage();
    void readMessage();

private:
    void createSocket();
    QTextEdit *textEdit;
    QLineEdit *lineEdit;
    QPushButton *sendBtn;    
    
    quint16 port;
    QString text;
    QUdpSocket *socket;
};

#endif // UECHOCLIENT_H
