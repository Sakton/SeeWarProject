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
#include "NetModule/myjsonclientandserver.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

GameBlackWater::GameBlackWater( const QUrl &pathOfGUI, QObject *parent )
    : QObject(parent), m_pathOfGUI{pathOfGUI}, m_engine{new QQmlApplicationEngine(this)}, m_ownUser{}, m_tcpNetClient{}, gameId{-1}, m_doc{new QJsonDocument}, m_obj{new QJsonObject}
{
    QObject::connect ( m_engine, &QQmlApplicationEngine::objectCreated,
        static_cast<QGuiApplication*>(parent), [pathOfGUI](QObject* obj, const QUrl& objUrl) { if (!obj && pathOfGUI == objUrl) QCoreApplication::exit(-1); }, Qt::QueuedConnection);
    //Добавляет путь в качестве каталога, в котором механизм ищет установленные модули в структуре каталогов на основе URL.
    m_engine->addImportPath(pathOfGUI.toString().remove("main.qml"));
    m_ownUser = new OwnUser(m_engine->rootContext(), this);
    //TODO установка всего юзера в КУМЛЬ ***
    m_engine->rootContext()->setContextProperty("ObjectUser", m_ownUser);
    m_engine->load(pathOfGUI);
    //****

    m_tcpNetClient = new GameTcpClient(Config::GAME_SERVER_HOST, Config::GAME_SERVER_PORT, this);

    connect(m_ownUser, &OwnUser::clickedToCell, this, &GameBlackWater::onClickedToCell);
    connect(m_ownUser, &OwnUser::sendMessage, this, &GameBlackWater::onSendMessage);
    connect(m_tcpNetClient, &GameTcpClient::readyJsonDocument, this, &GameBlackWater::readJsonDocument);
}

GameBlackWater::~GameBlackWater()
{
    delete m_doc;
    delete m_obj;
}

void GameBlackWater::onClickedToCell(int indexCell)
{
    QJsonObject obj;
    obj.insert(Config::Name_User, m_ownUser->name());
    obj.insert(Config::Id_Game, gameId);
    obj.insert(Config::Fire_To_Cell, indexCell);

    //MyJsonClientAndServer obj(gameId, indexCell, );

    m_doc->setObject(obj);
    sendJsonDocument();
}

void GameBlackWater::onSendMessage(const QString &mes)
{
    QJsonObject obj;
    obj.insert(Config::Name_User, m_ownUser->name());
    obj.insert(Config::Id_Game, gameId);
    obj.insert(Config::Message, mes);
    m_doc->setObject(obj);
    sendJsonDocument();
}

void GameBlackWater::sendJsonDocument()
{
    m_tcpNetClient->sendJsonDocument(m_doc);
}

void GameBlackWater::readJsonDocument(const QByteArray *answer)
{
    QJsonDocument doc = QJsonDocument::fromJson(*answer);
    QJsonValue name = doc[Config::Name_User];
    QJsonValue messsage = doc[Config::Message];
    QJsonValue indexFire = doc[Config::Fire_To_Cell];
    if(!messsage.isUndefined())
        m_ownUser->onAnswerMessageToEnemyUser(messsage.toString());
    if(!indexFire.isUndefined())
        m_ownUser->onFireToCellToQml(indexFire.toInt());
}

void GameBlackWater::createJsonDocument()
{
    QJsonObject obj;
    obj.insert(Config::Name_User, m_ownUser->name());
    obj.insert(Config::Id_Game, gameId);
    m_doc->setObject(obj);
}

