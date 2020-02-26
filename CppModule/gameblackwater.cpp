#include "gameblackwater.h"
#include <QQmlApplicationEngine>
#include <QtGui/QGuiApplication>
#include "User/ownuser.h"
#include "User/enemyuser.h"
#include <QDebug>
#include <QQmlContext>
#include "NetModule/gameudpclient.h"
#include "NetModule/gametcpclient.h"

GameBlackWater::GameBlackWater( const QUrl &pathOfGUI, QObject *parent )
    : QObject(parent), m_pathOfGUI{pathOfGUI}, m_engine{new QQmlApplicationEngine(this)}, m_ownUser{}, m_tcpNetClient{}, gameId{}
{
    QObject::connect ( m_engine, &QQmlApplicationEngine::objectCreated,
        static_cast<QGuiApplication*>(parent), [pathOfGUI](QObject* obj, const QUrl& objUrl) { if (!obj && pathOfGUI == objUrl) QCoreApplication::exit(-1); }, Qt::QueuedConnection);
    //Добавляет путь в качестве каталога, в котором механизм ищет установленные модули в структуре каталогов на основе URL.
    m_engine->addImportPath(pathOfGUI.toString().remove("main.qml"));
    m_ownUser = new OwnUser(m_engine->rootContext(), this);
    m_engine->rootContext()->setContextProperty("ObjectUser", m_ownUser);
    m_engine->load(pathOfGUI);

    m_tcpNetClient = new GameTcpClient(Config::GAME_SERVER_HOST, Config::GAME_SERVER_PORT, this);

    connect(m_ownUser, &OwnUser::sendMessage, m_tcpNetClient, &GameTcpClient::sendMessage);
    connect(m_ownUser, &OwnUser::clickedToCell, m_tcpNetClient, &GameTcpClient::sendFireIndex);
    connect(m_tcpNetClient, &GameTcpClient::answerMessageFromServer, m_ownUser, &OwnUser::onAnswerMessageToEnemyUser);

}
