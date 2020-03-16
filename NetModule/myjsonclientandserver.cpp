#include "myjsonclientandserver.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

MyJsonClientAndServer::MyJsonClientAndServer(const QByteArray &arr)
{
    createQByteArray();
    *m_pByteArray = arr;
    QJsonDocument doc = QJsonDocument::fromBinaryData(arr);
    QJsonObject obj = doc.object();
    m_idGame = obj[ID_GAME].toInt();
    m_indexFireToCell = obj[INDEX_FIRE_TO_CELL].toInt();
    m_stateEnemyUser = obj[STATE_ENEMY_USER].toInt();
    m_resultEnemyFire = obj[RESULT_FIRE_USER].toInt();
    m_message = obj[MESSAGE].toString();
}

MyJsonClientAndServer::MyJsonClientAndServer(int id, int idxFireToCell, int stateEnemyUser, int resultEnemyFire, const QString &mes)
    : m_idGame{id},
    m_indexFireToCell{idxFireToCell},
    m_stateEnemyUser{stateEnemyUser},
    m_resultEnemyFire{resultEnemyFire},
    m_message{mes}
{

}

MyJsonClientAndServer::~MyJsonClientAndServer()
{
    delete m_pByteArray;
}

MyJsonClientAndServer::MyJsonClientAndServer()
    : m_idGame{-1},
    m_indexFireToCell{-1},
    m_stateEnemyUser{-1},
    m_resultEnemyFire{-1},
    m_message{""}
{

}

QByteArray &MyJsonClientAndServer::toByteArray()
{
    QJsonDocument doc;
    QJsonObject obj;
    obj.insert(ID_GAME, m_idGame);
    obj.insert(INDEX_FIRE_TO_CELL, m_indexFireToCell);
    obj.insert(STATE_ENEMY_USER, m_stateEnemyUser);
    obj.insert(RESULT_FIRE_USER, m_resultEnemyFire);
    obj.insert(MESSAGE, m_message);
    doc.setObject(obj);
    *m_pByteArray = doc.toJson();
    return *m_pByteArray;
}

int MyJsonClientAndServer::idGame() const
{
    return m_idGame;
}

void MyJsonClientAndServer::setIdGame(int idGame)
{
    m_idGame = idGame;
}

int MyJsonClientAndServer::indexFireToCell() const
{
    return m_indexFireToCell;
}

void MyJsonClientAndServer::setIndexFireToCell(int indexFireToCell)
{
    m_indexFireToCell = indexFireToCell;
}

int MyJsonClientAndServer::stateEnemyUser() const
{
    return m_stateEnemyUser;
}

void MyJsonClientAndServer::setStateEnemyUser(int stateEnemyUser)
{
    m_stateEnemyUser = stateEnemyUser;
}

int MyJsonClientAndServer::resultEnemyFire() const
{
    return m_resultEnemyFire;
}

void MyJsonClientAndServer::setResultEnemyFire(int resultEnemyFire)
{
    m_resultEnemyFire = resultEnemyFire;
}

QString MyJsonClientAndServer::message() const
{
    return m_message;
}

void MyJsonClientAndServer::setMessage(const QString &message)
{
    m_message = message;
}

void MyJsonClientAndServer::createQByteArray()
{
    m_pByteArray = new QByteArray;
}

