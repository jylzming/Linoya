#include "myclient.h"
#include <QDataStream>
#include <QString>
#include <QHostAddress>


MyClient::MyClient()
{
    tcpSocket = new QTcpSocket(this);
    //this->newConnect("192.168.1.108", 777);
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readMessage()));
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));

}
MyClient::~MyClient()
{
    //delete MyClient;
}

void MyClient::newConnect()
{
    tcpSocket->abort();
    tcpSocket->connectToHost(QHostAddress("192.168.1.108"), 333);
    tcpSocket->waitForConnected(3000);
    //while(tcpSocket->SocketState != QAbstractSocket::ConnectedState);
    //connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(disConnect()));
}

void MyClient::readMessage()
{
    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_5_8);
    if(blockSize == 0)
    {
        if(tcpSocket->bytesAvailable() < (int)sizeof(quint16)) return;
        in>>blockSize;
    }
    if(tcpSocket->bytesAvailable() < blockSize) return;

    in>>message;
    qDebug() << message;
}

void MyClient::displayError(QAbstractSocket::SocketError)
{
    qDebug() << tcpSocket->errorString();
}

void MyClient::on_connect()
{
    tcpSocket->abort();
    tcpSocket->connectToHost("192.168.1.108", 777, QIODevice::ReadWrite);
}

void MyClient::sendMessage(const QString str)
{
    tcpSocket->write(str.toStdString().c_str(), strlen(str.toStdString().c_str()));
    //tcpSocket->write(str.toStdString().c_str(), strlen(str.toStdString().c_str()));
    //tcpSocket->waitForBytesWritten(500);
}

//#include "myclient.moc"
