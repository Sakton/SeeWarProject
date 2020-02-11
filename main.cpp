#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include "QmlModule/cpp/guiloader.h"
#include <QDir>
#include <QDebug>
#include "CppModule/Model/field.h"
#include "NetModule/gametcpclient.h"
#include "CppModule/Model/config.h"

#else
#endif

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    //TODO GameLogik();
    GameTcpClient client(Config::GAME_SERVER_HOST, Config::GAME_SERVER_PORT, &app);

    QUrl testGui { QStringLiteral("file:/E:/CPP/MyProects/SeeWarProject/SeeWarProject/QmlModule/qml/TestOtherGui/main.qml") };
    QUrl defaultGui { QStringLiteral("qrc:/QmlModule/qml/DefaultGui/main.qml") };

    GuiLoader::init(defaultGui, &app, &app);
    return app.exec();
}
