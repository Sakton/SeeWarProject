#ifndef MYJSONCLIENTANDSERVER_H
#define MYJSONCLIENTANDSERVER_H
#include <QByteArray>
#include <QString>
#include <QJsonObject>
#include <QMap>
#include <QPointer>
class QByteArray;

//FIXME делать тут реализовать JSON

enum TypeJsomMessage {
    FIRE_MESSAGE = 0,
    RESULT_FIRE,
    CHAT_MESSAGE,
    BASE_MESSAGE
};

const char* TYPE_JSON = "typeJsonObject";
const char* ID_GAME = "idGame";
const char* INDEX_FIRE_TO_CELL = "indexFireCell";
const char* STATE_ENEMY_USER = "stateEnemyUser";
const char* STATE_OWN_USER = "stateOwnUser";
const char* STATE_USER = "stateUser";
const char* RESULT_FIRE_USER = "stateOwnUser";
const char* MESSAGE = "message";
const char* OBJECT_JSON = "objectJson";

class CreaterJson {
    explicit CreaterJson(TypeJsomMessage type, const QMap<QString, QString> *keyVal);

private:
};

class BaseJsonObject {
public:
    BaseJsonObject(int typeJson, int id, int state);
    explicit BaseJsonObject(const QJsonObject &mes);
    virtual QPointer<QByteArray> toByteArray();
    virtual ~BaseJsonObject();


    int idGame() const;
    int stateGame() const;

    protected:
    virtual QJsonObject object();

protected:
    QPointer<QByteArray> m_pBytearray;
    QJsonObject *jObj;
    int m_idGame;
    int m_stateGame;
    TypeJsomMessage m_type;
};

class ChatMessageJson : public BaseJsonObject {
public:
    ChatMessageJson(int typeJson, int id, int state, const QString &mes);
    ChatMessageJson(const QJsonObject &mes);
    ~ChatMessageJson() override;
    QPointer<QByteArray> toByteArray() override;

    // BaseJsonObject interface
    QString message() const;

    protected:
    QJsonObject object() override;

private:
    QString m_message;
};

//FIXME ДЕЛАТЬ ТУТ

class FireCellJson : public BaseJsonObject {
public:
    FireCellJson(int typeJson, int id, int state, int index);
    FireCellJson(const QJsonObject &mes);
    ~FireCellJson() override;
    QPointer<QByteArray> toByteArray() override;

    // BaseJsonObject interface
    int indexFire() const;

    protected:
    QJsonObject object() override;

private:
    int m_indexFire;
};

class ResultFireJson : public BaseJsonObject {
public:
    ResultFireJson(int typeJson, int id, int state);
    ResultFireJson(const QJsonObject &mes);
    ~ResultFireJson() override;
    QPointer<QByteArray> toByteArray() override;

protected:
    QJsonObject object() override;
};



#endif // MYJSONCLIENTANDSERVER_H
