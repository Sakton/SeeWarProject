#include "gameblackwater.h"
#include <QQmlApplicationEngine>
#include <QtGui/QGuiApplication>
#include "User/ownuser.h"
#include "User/enemyuser.h"
#include <QDebug>
#include <QQmlContext>
#include "NetModule/gametcpclient.h"
#include "Model/config.h"
#include <map>
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

    connect(m_ownUser, &OwnUser::clickedToCell, this, &GameBlackWater::onClickedToCell);
    connect(m_ownUser, &OwnUser::sendMessage, this, &GameBlackWater::onSendMessage);
    connect(m_tcpNetClient, static_cast<void(GameTcpClient::*)(const QByteArray*)>(&GameTcpClient::readyJsonDocument) , this, static_cast<void(GameBlackWater::*)(const QByteArray*)>(&GameBlackWater::readJsonDocument) );

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

//    FireCellJson fireJson( TypeJsomMessage::RESULT_FIRE, gameId, static_cast<int>(m_ownUser->stateMovesUser()), indexCell );

    //MyJsonClientAndServer obj(gameId, indexCell, );

    m_doc->setObject(obj);


    //send(fireJson.toByteArray());
    sendJsonDocument();
}

void GameBlackWater::onSendMessage(const QString &mes)
{
    QJsonObject obj;
    obj.insert(Config::Name_User, m_ownUser->name());
    obj.insert(Config::Id_Game, gameId);
    obj.insert(Config::Message, mes);

   // ChatMessageJson mesJson();

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

    //FIXME делать тут, надо оправить ответ
}

//void GameBlackWater::readJsonDocument(QPointer<QByteArray> answer)
//{
//    qDebug() << "NEW METHOD";
//    QJsonDocument doc = QJsonDocument::fromJson(*answer);
//    QJsonObject obj1 = doc.object();
//    TypeJsomMessage tmes = TypeJsomMessage (obj1[TYPE_JSON].toInt());
//    switch (tmes) {
//    case TypeJsomMessage::BASE_MESSAGE: {
//        break;
//    }
//    case TypeJsomMessage::FIRE_MESSAGE: {
//        FireCellJson fcObj (obj1[OBJECT_JSON].toObject());
//        m_ownUser->onFireToCellToQml(fcObj.indexFire());
//        break;
//    }
//    case TypeJsomMessage::RESULT_FIRE: {
//        ResultFireJson rfObj (obj1[OBJECT_JSON].toObject());
//        m_ownUser->setOwnStateFromEnemyState( OwnUser::StateMovesUser( rfObj.stateGame() ) );
//        break;
//    }
//    case TypeJsomMessage::CHAT_MESSAGE: {
//        ChatMessageJson cmObj(obj1[OBJECT_JSON].toObject());
//        m_ownUser->onAnswerMessageToEnemyUser(cmObj.message());
//        break;
//    }

//    }
//}

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

