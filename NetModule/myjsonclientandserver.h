#ifndef MYJSONCLIENTANDSERVER_H
#define MYJSONCLIENTANDSERVER_H
#include <QByteArray>
#include <QString>
#include <QJsonObject>
#include <QMap>
class QByteArray;

//FIXME делать тут реализовать JSON

enum TypeJsomMessage {
    FIRE_MESSAGE = 0,
    RESULT_FIRE,
    CHAT_MESSAGE
};

const char* TYPE_JSON = "typeJsonObject";
const char* ID_GAME = "idGame";
const char* INDEX_FIRE_TO_CELL = "indexFireCell";
const char* STATE_ENEMY_USER = "stateEnemyUser";
const char* RESULT_FIRE_USER = "stateOwnUser";
const char* MESSAGE = "message";

class CreaterJson {
    explicit CreaterJson(TypeJsomMessage type, const QMap<QString, QString> *keyVal);

private:
};

class BaseJsonObject {
public:
    BaseJsonObject(int id, int state, int typeJson);
    explicit BaseJsonObject(const QJsonObject &mes);

protected:
    virtual QJsonObject & object();

private:
    int m_idGame;
    int m_stateGame;
//    TypeJsomMessage m_type;
};

class ChatMessageJson : public BaseJsonObject {
public:
    ChatMessageJson(int id, int state, int typeJson, const QString &mes);
    ChatMessageJson(const QJsonObject &mes);

    // BaseJsonObject interface
protected:
    QJsonObject &object() override;

private:
    QString m_message;

};

class FireCellJson : public BaseJsonObject {
public:
    FireCellJson(int id, int state, int typeJson, int index);
    FireCellJson(const QJsonObject &mes);

    // BaseJsonObject interface
protected:
    QJsonObject &object() override;

private:
    int m_indexFire;
};

class ResultFireJson : public BaseJsonObject {
public:
    ResultFireJson(int id, int state, int typeJson);
    ResultFireJson(const QJsonObject &mes);

protected:
    QJsonObject &object() override;
};

//class MyJsonClientAndServer
//{

//public:
//    MyJsonClientAndServer();
//    explicit MyJsonClientAndServer(const QByteArray &arr);
//    explicit MyJsonClientAndServer(int id, int idxFireToCell = -1, int stateEnemyUser = -1, int resultEnemyFire = -1, const QString &mes = "");
//    ~MyJsonClientAndServer();


//    QByteArray &toByteArray();

//    int idGame() const;
//    void setIdGame(int idGame);

//    int indexFireToCell() const;
//    void setIndexFireToCell(int indexFireToCell);

//    int stateEnemyUser() const;
//    void setStateEnemyUser(int stateEnemyUser);

//    int resultEnemyFire() const;
//    void setResultEnemyFire(int resultEnemyFire);

//    QString message() const;
//    void setMessage(const QString &message);

//private:
//    void createQByteArray();

//private:
//    QByteArray *m_pByteArray;
//    int m_idGame;
//    int m_indexFireToCell;
//    int m_stateEnemyUser;
//    int m_resultEnemyFire;
//    QString m_message;
//    //    QString m_nameUser;
//};

#endif // MYJSONCLIENTANDSERVER_H
