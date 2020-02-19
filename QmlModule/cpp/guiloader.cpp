#include "guiloader.h"
#include <QDebug>
#include <QQmlContext>
#include "CppModule/GameCore/flot.h"
#include "CppModule/Model/field.h"
#include "../../CppModule/User/baseuser.h"

GuiLoader* GuiLoader::m_self { nullptr };

GuiLoader::GuiLoader(QUrl &url, QGuiApplication* app, QObject *parent) : QObject(parent),
    m_app { app },
    m_url { url }
{
    m_engine = new QQmlApplicationEngine(this);
    auto context = m_engine->rootContext();

//     BaseUser *user = new BaseUser(context, this);

//    Field *field = new Field(app);
//    Flot *flot = new Flot(field, field);

//    context->setContextProperty("Field", field);
//    context->setContextProperty("Flot", flot);

    QObject::connect (
        m_engine, &QQmlApplicationEngine::objectCreated,
        app, [url](QObject* obj, const QUrl& objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    //добавлять путь для модулей настроек перед загрузкой qml
    addImportStyleModuleGui(m_url);
    m_engine->load(m_url);
}

void GuiLoader::addImportStyleModuleGui(QUrl& url)
{
    m_engine->addImportPath(url.toString().remove("main.qml"));
}

GuiLoader &GuiLoader::init(QUrl& url, QGuiApplication* app, QObject *parent)
{
    if (nullptr == m_self)
        m_self = new GuiLoader(url, app, app);
    return *m_self;
}
