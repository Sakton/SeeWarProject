#ifndef MYJSONCLIENTANDSERVER_H
#define MYJSONCLIENTANDSERVER_H
#include <QByteArray>
#include <QString>

class QByteArray;

class MyJsonClientAndServer
{
    enum TypeGameJsonObject {

    };

public:
    MyJsonClientAndServer(const QByteArray &arr);

private:
    quint64 m_idGame;
    int m_indexFireToCell;
    QString message;
    int stateMoveUser;
    QString nameUser;

};

#endif // MYJSONCLIENTANDSERVER_H
