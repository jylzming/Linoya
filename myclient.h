#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QLocalSocket>
#include <QtNetwork>
#include <QDebug>
#include <QString>

class MyClient: public QObject
{
    Q_OBJECT
public:
    MyClient();
    ~MyClient();

public:
    QTcpSocket *tcpSocket;

private:
    QString message;
    quint16 blockSize;

public slots:
    void newConnect();
    void readMessage();
    void displayError(QAbstractSocket::SocketError);
    void on_connect();
    void sendMessage(const QString str);
};

#endif // MYCLIENT_H
