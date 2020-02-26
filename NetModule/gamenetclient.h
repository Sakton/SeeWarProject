#ifndef GAMENETCLIENT_H
#define GAMENETCLIENT_H

#include <QObject>
//этот класс нужен для того что не понятно какое будет соединение
//но какоеб оно ни было, путь класс просто реализует интерфейс
class GameNetClient : public QObject
{
public:
    explicit GameNetClient(QObject *parent = nullptr);
    virtual ~GameNetClient(){}
    virtual void sendMessage(const QString &mes) = 0;
    virtual void sendFireIndex(int index) = 0;
   // virtual


//public slots:
//    virtual void onReadyRead() = 0;
//    virtual void onError() = 0;
};

#endif // GAMENETCLIENT_H
