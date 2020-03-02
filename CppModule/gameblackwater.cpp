#include "gameblackwater.h"
#include <QQmlApplicationEngine>
#include <QtGui/QGuiApplication>
#include "User/ownuser.h"
#include "User/enemyuser.h"
#include <QDebug>
#include <QQmlContext>
#include "NetModule/gameudpclient.h"
#include "NetModule/gametcpclient.h"
#include "Model/config.h"
#include <map>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

GameBlackWater::GameBlackWater( const QUrl &pathOfGUI, QObject *parent )
    : QObject(parent), m_pathOfGUI{pathOfGUI}, m_engine{new QQmlApplicationEngine(this)}, m_ownUser{}, m_tcpNetClient{}, gameId{-1}
{
    QObject::connect ( m_engine, &QQmlApplicationEngine::objectCreated,
        static_cast<QGuiApplication*>(parent), [pathOfGUI](QObject* obj, const QUrl& objUrl) { if (!obj && pathOfGUI == objUrl) QCoreApplication::exit(-1); }, Qt::QueuedConnection);
    //Добавляет путь в качестве каталога, в котором механизм ищет установленные модули в структуре каталогов на основе URL.
    m_engine->addImportPath(pathOfGUI.toString().remove("main.qml"));
    m_ownUser = new OwnUser(m_engine->rootContext(), this);
    m_engine->rootContext()->setContextProperty("ObjectUser", m_ownUser);
    m_engine->load(pathOfGUI);

    m_tcpNetClient = new GameTcpClient(Config::GAME_SERVER_HOST, Config::GAME_SERVER_PORT, this);

    connect(m_ownUser, &OwnUser::clickedToCell, this, &GameBlackWater::onClickedToCell);
    connect(m_ownUser, &OwnUser::sendMessage, this, &GameBlackWater::onSendMessage);
}

void GameBlackWater::onClickedToCell(int indexCell)
{
 //   mapData.insert( std::make_pair( Config::Fire_To_Cell, QVariant(indexCell) ) );
    QJsonDocument t = createJsonDocument();
    sendJsonDocument();
}

void GameBlackWater::onSendMessage(const QString &mes)
{
  //  mapData.insert( std::make_pair( Config::Message, QVariant(mes) ) );
}

void GameBlackWater::sendJsonDocument()
{
    QJsonDocument t = createJsonDocument();
    m_tcpNetClient->sendJsonDocument(t);
}

QJsonDocument GameBlackWater::createJsonDocument()
{
    QJsonObject obj;
    obj.insert(Config::Name_User, m_ownUser->name());
    obj.insert(Config::Id_Game, gameId);

    return QJsonDocument(obj);
}

