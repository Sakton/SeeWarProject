#include "myjsonobjects.h"



JsonGameObject::JsonGameObject(const QJsonObject &jObj):idGame{-1}
{
    idGame = jObj.value(ID_GAME).toInt();
}

QJsonObject JsonGameObject::toJsonObject()
{
    QJsonObject obj;
    obj.insert(ID_GAME, idGame);
    return obj;
}

JsonGameObject::~JsonGameObject()
{

}

//*****
FireJson::FireJson(const QJsonObject &jObj) : JsonGameObject(jObj)
{

}

FireJson::~FireJson()
{

}

QJsonObject FireJson::toJsonObject()
{

    return {};
}

MessageJson::MessageJson(const QJsonObject &jObj) : JsonGameObject(jObj)
{

}

MessageJson::~MessageJson()
{

}

QJsonObject MessageJson::toJsonObject()
{

    return {};
}
