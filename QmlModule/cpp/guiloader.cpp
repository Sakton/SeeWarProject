#include "guiloader.h"
#include <QDebug>
#include <algorithm>
#include <QQmlContext>

GuiLoader* GuiLoader::m_self { nullptr };

GuiLoader::GuiLoader(QUrl &url, QGuiApplication* app, QAbstractListModel *model, QObject *parent) : QObject(parent),
    m_app { app },
    m_model{model},
    m_url { url }
{
    m_engine = new QQmlApplicationEngine;

    QObject::connect(
        m_engine, &QQmlApplicationEngine::objectCreated,
        app, [url](QObject* obj, const QUrl& objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
//    qmlRegisterType<GuiLoader>();
    //Дюбавляем обьект доска как контекст
    m_engine->rootContext()->setContextProperty("Field", model);
    //добавлять путь для модулей настроек перед загрузкой qml
    addImportStyleModuleGui(m_url);
    m_engine->load(m_url);

}

void GuiLoader::addImportStyleModuleGui(QUrl& url)
{
    m_engine->addImportPath(url.toString().remove("main.qml"));
}

GuiLoader &GuiLoader::init(QUrl& url, QGuiApplication* app, QAbstractListModel *model, QObject* parent)
{
    if (nullptr == m_self)
        m_self = new GuiLoader(url,app, model, parent);
    return *m_self;
}
