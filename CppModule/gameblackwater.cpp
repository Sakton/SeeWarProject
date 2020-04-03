#include "gameblackwater.h"
#include <QQmlApplicationEngine>
#include <QtGui/QGuiApplication>
#include "User/ownuser.h"
#include "User/enemyuser.h"
#include <QDebug>
#include <QQmlContext>
#include "NetModule/gametcpclient.h"
#include "Model/config.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QPointer>

GameBlackWater::GameBlackWater( const QUrl &pathOfGUI, QObject *parent )
    : QObject(parent), m_pathOfGUI{pathOfGUI}, m_engine{new QQmlApplicationEngine(this)}, m_ownUser{}, m_tcpNetClient{}, gameId{-1}, m_doc{new QJsonDocument}, m_obj{new QJsonObject}
{
    QObject::connect ( m_engine, &QQmlApplicationEngine::objectCreated,
        static_cast<QGuiApplication*>(parent), [pathOfGUI](QObject* obj, const QUrl& objUrl) { if (!obj && pathOfGUI == objUrl) QCoreApplication::exit(-1); }, Qt::QueuedConnection);
    //Добавляет путь в качестве каталога, в котором механизм ищет установленные модули в структуре каталогов на основе URL.
    m_engine->addImportPath(pathOfGUI.toString().remove("main.qml"));
    m_ownUser = new OwnUser(m_engine->rootContext(), this);
    //установка всего юзера в КУМЛЬ ***
    m_engine->rootContext()->setContextProperty("ObjectUser", m_ownUser);
    m_engine->load(pathOfGUI);
    //****

    m_tcpNetClient = new GameTcpClient(Config::GAME_SERVER_HOST, Config::GAME_SERVER_PORT, this);
    connect(m_ownUser, &OwnUser::signalOwnUser_slotFromQml_clickedToCell, this, &GameBlackWater::slotFromOwnUser_onClickedToCell);
    connect(m_ownUser, &OwnUser::signalOwnUser_sendMessage, this, &GameBlackWater::slotFromOwnUser_onSendMessage);

    connect(m_tcpNetClient, static_cast<void(GameTcpClient::*)(const QByteArray*)>(&GameTcpClient::readyJsonDocument) , this, static_cast<void(GameBlackWater::*)(const QByteArray*)>(&GameBlackWater::readJsonDocument) );
    //сигналы по кораблям от юзера
    connect(m_ownUser, &OwnUser::signalOwnUser_DamageShip, this, &GameBlackWater::slotFromOwnuser_DamageShip);
    connect(m_ownUser, &OwnUser::signalOwnUser_DeadShip, this, &GameBlackWater::slotFromOwnuser_DeadShip);
    connect(m_ownUser, &OwnUser::signalOwnUser_DeadFlot, this, &GameBlackWater::slotFromOwnuser_DeadFlot);
    connect(m_ownUser, &OwnUser::signalOwnUser_Miss, this, &GameBlackWater::slotFromOwnuser_Miss);
}

GameBlackWater::~GameBlackWater()
{
    delete m_doc;
    delete m_obj;
}

void GameBlackWater::slotFromOwnUser_onClickedToCell(int indexCell)
{
    sender(Config::Fire_To_Cell, indexCell);
}

void GameBlackWater::slotFromOwnUser_onSendMessage( const QString &mes )
{
    QJsonObject obj;
    obj.insert(Config::Message, mes);
    QJsonDocument doc;
    doc.setObject(obj);
    m_tcpNetClient->sendJsonDocument(&doc);
}

void GameBlackWater::sendJsonDocument()
{
    m_tcpNetClient->sendJsonDocument(m_doc);
}

//надо формировать единый обьект
void GameBlackWater::readJsonDocument(const QByteArray *answer)
{
    QJsonDocument doc = QJsonDocument::fromJson(*answer);
    QJsonObject obj = doc.object();
    QJsonValue name = doc[Config::Name_User];
    QJsonValue messsage = doc[Config::Message];
    QJsonValue indexFire = doc[Config::Fire_To_Cell];
    QJsonValue answerStateEnemy = doc[Config::State_Game];
    QJsonValue pravoHoda  = doc[Config::Hod];

    if( !messsage.isUndefined() )
	m_ownUser->slotFromEnemyUser_onMessageToChatToQml(messsage.toString());

    if( !indexFire.isUndefined() )
	m_ownUser->slotFromEnemyUser_onFireToCellToQml(indexFire.toInt());

    if( !answerStateEnemy.isUndefined() )
	m_ownUser->setElementResultFireToEnemyField( OwnUser::StateMovesUser(answerStateEnemy.toInt()) );
}

void GameBlackWater::slotFromOwnuser_DamageShip()
{
    sender(Config::State_Game, OwnUser::StateMovesUser::SHIP_DAMAGE);
}

void GameBlackWater::slotFromOwnuser_DeadShip()
{
    sender(Config::State_Game, OwnUser::StateMovesUser::SHIP_DEAD);
}

void GameBlackWater::slotFromOwnuser_DeadFlot()
{
    sender(Config::State_Game, OwnUser::StateMovesUser::FLOT_DEAD);
}

void GameBlackWater::slotFromOwnuser_Miss()
{
    sender(Config::State_Game, OwnUser::StateMovesUser::MISS);
}


void GameBlackWater::sender(const QString &key, int value)
{
    QJsonObject obj;
    obj.insert(key, value);
    QJsonDocument doc;
    doc.setObject(obj);
    m_tcpNetClient->sendJsonDocument(&doc);
}

