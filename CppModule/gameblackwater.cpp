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
    //TODO установка всего юзера в КУМЛЬ ***
    m_engine->rootContext()->setContextProperty("ObjectUser", m_ownUser);
    m_engine->load(pathOfGUI);
    //****

    m_tcpNetClient = new GameTcpClient(Config::GAME_SERVER_HOST, Config::GAME_SERVER_PORT, this);
    connect(m_ownUser, &OwnUser::signalOwnUser_slotFromQml_clickedToCell, this, &GameBlackWater::slotFromOwnUser_onClickedToCell);
    connect(m_ownUser, &OwnUser::signalOwnUser_sendMessage, this, &GameBlackWater::slotFromOwnUser_onSendMessage);
    connect(m_ownUser, &OwnUser::signalOwnUser_answerToEnemyUserAboutFireCell, this, &GameBlackWater::slotFromOwnuser_onAnswerToEnemyUserAboutFireCell);
    connect(m_tcpNetClient, static_cast<void(GameTcpClient::*)(const QByteArray*)>(&GameTcpClient::readyJsonDocument) , this, static_cast<void(GameBlackWater::*)(const QByteArray*)>(&GameBlackWater::readJsonDocument) );

}

GameBlackWater::~GameBlackWater()
{
    delete m_doc;
    delete m_obj;
}

void GameBlackWater::slotFromOwnUser_onClickedToCell(int indexCell)
{
    qDebug() << "GameBlackWater::slotFromOwnUser_onClickedToCell отпришло от OwnUser";
    QJsonObject obj;
    obj.insert(Config::Name_User, m_ownUser->name());
    obj.insert(Config::Id_Game, gameId);
    obj.insert(Config::Fire_To_Cell, indexCell);

    m_doc->setObject(obj);
    sendJsonDocument();
}

void GameBlackWater::slotFromOwnUser_onSendMessage( const QString &mes )
{
    qDebug() << "GameBlackWater::onSendMessage(const QString &mes)";
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
    QJsonValue answerStateEnemy = doc[Config::State_Game];
    QJsonValue pravoHoda  = doc[Config::Hod];
    //право хода решил отменить пусть сами решают или кто первый

    if( !messsage.isUndefined() )
	m_ownUser->slotFromEnemyUser_onMessageToChatToQml(messsage.toString());
    if( !indexFire.isUndefined() )
	m_ownUser->slotFromEnemyUser_onFireToCellToQml(indexFire.toInt());
    if( !answerStateEnemy.isUndefined() )
	m_ownUser->setElementResultFireToEnemyField( OwnUser::StateMovesUser(answerStateEnemy.toInt()) );
}

void GameBlackWater::slotFromOwnuser_onAnswerToEnemyUserAboutFireCell(int state)
{
    QJsonObject obj;
    obj.insert(Config::State_Game, state);

    QJsonDocument doc;
    doc.setObject(obj);

    m_tcpNetClient->sendJsonDocument(&doc);
}

void GameBlackWater::createJsonDocument()
{
    QJsonObject obj;
    obj.insert(Config::Name_User, m_ownUser->name());
    obj.insert(Config::Id_Game, gameId);
    m_doc->setObject(obj);
}

void GameBlackWater::send(QByteArray *pByteArray)
{
    m_tcpNetClient->send(pByteArray);
}

