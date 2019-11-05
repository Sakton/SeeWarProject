#include "guiloader.h"
#include <QDebug>

GuiLoader* GuiLoader::m_self { nullptr };

GuiLoader::GuiLoader(QUrl &url,QGuiApplication* app, QObject *parent) : QObject(parent),
    m_app { app }
    , m_url { url }
{
    m_engine = new QQmlApplicationEngine;
    QObject::connect(
        m_engine, &QQmlApplicationEngine::objectCreated,
        app, [url](QObject* obj, const QUrl& objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);

    qmlRegisterType<GuiLoader>();

    m_engine->load(m_url);

}

GuiLoader &GuiLoader::init(QUrl& url, QGuiApplication* app, QObject* parent)
{
    if (nullptr == m_self)
        m_self = new GuiLoader(url,app, parent);
    return *m_self;
}

QUrl GuiLoader::getUrl() const
{
    return m_url;
}

void GuiLoader::setUrl(const QUrl &url)
{

    qDebug() << "Do = " << m_url;
    if (url != m_url) {

        delete m_engine;
        m_engine = new QQmlApplicationEngine;
        m_engine->load(url);
    }
    m_url = url;

    qDebug() << "Posle = " << m_url;
}

void GuiLoader::registerSelf()
{
   // qmlRegisterType<GuiLoader>("seewar", 1, 0, "GuiLoader");
}
