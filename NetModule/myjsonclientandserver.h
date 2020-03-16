#ifndef MYJSONCLIENTANDSERVER_H
#define MYJSONCLIENTANDSERVER_H
#include <QByteArray>
#include <QString>

class QByteArray;

class MyJsonClientAndServer
{
    const char* ID_GAME = "idGame";
    const char* INDEX_FIRE_TO_CELL = "indexFireCell";
    const char* STATE_ENEMY_USER = "stateEnemyUser";
    const char* RESULT_FIRE_USER = "stateOwnUser";
    const char* MESSAGE = "message";

public:
    MyJsonClientAndServer();
    explicit MyJsonClientAndServer(const QByteArray &arr);
    explicit MyJsonClientAndServer(int id, int idxFireToCell = -1, int stateEnemyUser = -1, int resultEnemyFire = -1, const QString &mes = "");
    ~MyJsonClientAndServer();


    QByteArray &toByteArray();

    int idGame() const;
    void setIdGame(int idGame);

    int indexFireToCell() const;
    void setIndexFireToCell(int indexFireToCell);

    int stateEnemyUser() const;
    void setStateEnemyUser(int stateEnemyUser);

    int resultEnemyFire() const;
    void setResultEnemyFire(int resultEnemyFire);

    QString message() const;
    void setMessage(const QString &message);

private:
    void createQByteArray();

private:
    QByteArray *m_pByteArray;
    int m_idGame;
    int m_indexFireToCell;
    int m_stateEnemyUser;
    int m_resultEnemyFire;
    QString m_message;
    //    QString m_nameUser;
};

#endif // MYJSONCLIENTANDSERVER_H
