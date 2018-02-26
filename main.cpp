#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQmlEngine>
#include <QQmlComponent>
#include "myclient.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    qmlRegisterType<MyClient>("an.qt.MyClient", 1,0, "MyClient");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    MyClient *myClient = new MyClient();
    myClient->newConnect();
    //myClient->on_connect();
    qDebug() << "Socket open state: " << myClient->tcpSocket->isOpen();
    qDebug() << "TCP State now is:" << myClient->tcpSocket->state();
//    while(myClient->tcpSocket->isOpen() == false){
//        myClient->newConnect();

//    }
//    qDebug() << "TCP final state is:" << myClient->tcpSocket->state();
    myClient->sendMessage("Hello ming1");
    return app.exec();
}
