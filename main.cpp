#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtGui/QGuiApplication>
#include "cpp/GuiModule/guiloader.h"
#else
#endif

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QUrl baseUrl = QUrl(QStringLiteral("file:/E:/CPP/MyProects/SeeWarProject/SeeWarProject/qml/TestOtherGui/main.qml"));
    QUrl defaultUrl = QUrl(QStringLiteral("qrc:/qml/DefaultGui/main.qml"));
    GuiLoader::init(defaultUrl, &app);

    return app.exec();
}
