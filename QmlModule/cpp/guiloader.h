#ifndef GUILOADER_H
#define GUILOADER_H

#include <QtCore/qglobal.h>
#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
//Singleton

class GuiLoader : public QObject
{
    Q_OBJECT
public:
    static GuiLoader& init(QUrl& url ,QGuiApplication* app, QObject* parent = nullptr);

private:
    explicit GuiLoader(QUrl& url, QGuiApplication* app = nullptr, QObject* parent = nullptr);

private:
    void addImportStyleModuleGui(QUrl &url);

private:
    QGuiApplication* m_app;
    QQmlApplicationEngine* m_engine;
    QUrl m_url;
    static GuiLoader *m_self;
};

#endif // GUILOADER_H
