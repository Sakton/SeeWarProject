#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include "QmlModule/cpp/guiloader.h"
#include <QDir>
#include <QDebug>
#include "CppModule/Model/field.h"
#include "CppModule/Model/arragementmodel.h"


//****test****
#include "CppModule/GameCore/flot.h"
//****test****

#else
#endif

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    //****test****

//    Flot *flot = new Flot(nullptr);
    qmlRegisterType<Flot>("CppClassesToQmlModules", 1,0, "Flot");

    //****test****

    //    GuiLoader::registerType<Field>("aaaaaa", 1,0, "Field");

    qmlRegisterType<Field>("CppClassesToQmlModules", 1,0, "Field");
    qmlRegisterType<ArragementModel>("CppClassesToQmlModules", 1,0, "ArragementModel");
    QUrl testGui { QStringLiteral("file:/E:/CPP/MyProects/SeeWarProject/SeeWarProject/QmlModule/qml/TestOtherGui/main.qml") };
    QUrl defaultGui { QStringLiteral("qrc:/QmlModule/qml/DefaultGui/main.qml") };

    GuiLoader::init(defaultGui, &app, &app);
    return app.exec();
}
