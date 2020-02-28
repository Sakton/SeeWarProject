#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include "QmlModule/cpp/guiloader.h"
#include <QDir>
#include <QDebug>
#include "CppModule/Model/field.h"
#include "NetModule/gametcpclient.h"
#include "NetModule/gameudpclient.h"
#include "NetModule/testtimer.h"
//***
#include "CppModule/Model/config.h"
#include "CppModule/gameblackwater.h"
#else
#endif

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    GameBlackWater game (Config::PATH_OF_GUI_QML, &app);

    return app.exec();
}
