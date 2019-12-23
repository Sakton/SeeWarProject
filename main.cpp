#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include "QmlModule/cpp/guiloader.h"
#include <QDir>
#include <QDebug>
#include "CppModule/Model/field.h"
#include "CppModule/Model/flot.h"

#else
#endif

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    BaseFlotInterface *flot = new Flot;
    Field *field = new Field(flot, &app);

//    GuiLoader::registerType<Field>("aaaaaa", 1,0, "Field");
//    qmlRegisterType<Field>("CppClassesToQmlModules", 1,0, "Field");
    QUrl testGui { QStringLiteral("file:/E:/CPP/MyProects/SeeWarProject/SeeWarProject/QmlModule/qml/TestOtherGui/main.qml") };
    QUrl defaultGui { QStringLiteral("qrc:/QmlModule/qml/DefaultGui/main.qml") };


    GuiLoader::init(defaultGui, &app, field);
    return app.exec();
}
