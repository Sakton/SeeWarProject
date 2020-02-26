#ifndef MYJSONOBJECTS_H
#define MYJSONOBJECTS_H
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

enum class TypeOfJsonMessage {
    QUERY_ID_GAME = 0,

};

const QByteArray ID_GAME = "idGame";
const QByteArray USER = "user";

class JsonGameObject {
public:
    JsonGameObject(const QJsonObject &jObj);
    virtual QJsonObject toJsonObject();
    virtual ~JsonGameObject();

protected:
    long long idGame;
};

class FireJson : public JsonGameObject {
    FireJson(const QJsonObject &jObj);
    ~FireJson()override;
    // JsonGameObject interface
    QJsonObject toJsonObject() override;

private:
    int move;
};

class MessageJson : public JsonGameObject {
    MessageJson(const QJsonObject &jObj);
    ~MessageJson()override;
    // JsonGameObject interface
    QJsonObject toJsonObject() override;

private:
    QString message;
};



#endif // MYJSONOBJECTS_H
