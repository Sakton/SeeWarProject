#include "myjsonclientandserver.h"
#include <QJsonDocument>
#include <QJsonValue>

BaseJsonObject::BaseJsonObject(int typeJson, int id, int state)
    : m_pBytearray{new QByteArray}, jObj{new QJsonObject}, m_idGame{id}, m_stateGame{state}, m_type{TypeJsomMessage(typeJson)}
{
    jObj->insert(TYPE_JSON, typeJson);
    jObj->insert(ID_GAME, id);
    jObj->insert(STATE_USER, state);
}

BaseJsonObject::BaseJsonObject(const QJsonObject &mes)
{
    m_idGame = mes[ID_GAME].toInt();
    m_stateGame = mes[STATE_USER].toInt();
}

QPointer<QByteArray> BaseJsonObject::toByteArray()
{
    QJsonDocument doc(*jObj);
    *m_pBytearray = doc.toJson();
    return m_pBytearray;
}

BaseJsonObject::~BaseJsonObject()
{
    delete jObj;
}

QJsonObject BaseJsonObject::object()
{
    return *jObj;
}

int BaseJsonObject::stateGame() const
{
    return m_stateGame;
}

int BaseJsonObject::idGame() const
{
    return m_idGame;
}

ChatMessageJson::ChatMessageJson(int typeJson, int id, int state, const QString &mes)
: BaseJsonObject(typeJson, id, state), m_message(mes)
{
    jObj->insert(MESSAGE, mes);
}

QPointer<QByteArray> ChatMessageJson::toByteArray()
{
    QJsonDocument doc(*jObj);
    *m_pBytearray = doc.toJson();
    return m_pBytearray;
}

QString ChatMessageJson::message() const
{
    return m_message;
}

int FireCellJson::indexFire() const
{
    return m_indexFire;
}
