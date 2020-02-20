#ifndef GAMEUDPCLIENT_H
#define GAMEUDPCLIENT_H
#include <QObject>
#include <QUdpSocket>
#include "gamenetclient.h"
#include "CppModule/Model/config.h"

class GameUdpClient : public GameNetClient
{
    Q_OBJECT
public:
    explicit GameUdpClient(const QString &host, int port,  QObject *parent = nullptr);
    //GameNetClient interface
    void sendMessage(const QString &s);

public slots:
    void onReadyRead();
    void onError();
    void onSendDatagramMessage(const QString &mes);
    void onSentDatagrammClickedIndex(int indexClickedCell);

private:
    void sendDatagramm();

private:
    QUdpSocket *m_udpSocket;
};

#endif // GAMEUDPCLIENT_H
