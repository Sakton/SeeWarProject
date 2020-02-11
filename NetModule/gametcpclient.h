#ifndef GAMETCPCLIENT_H
#define GAMETCPCLIENT_H
#include <QTcpSocket>
#include <QObject>
#include "myabstractquery.h"


class GameTcpClient : public QObject
{
public:
    explicit GameTcpClient(const QString &host, quint16 port, QObject *parent = nullptr);

    void sendQuery(const MyAbstractQuery &query);
    void sendToServsrTest(const QString &s);


private slots:
    void slotConnectedToServer();
    void onReadyRead();
    void onError();

private:
    quint16 m_sizeData;
    quint16 m_port;
    QTcpSocket *m_tcpSocket;
};

#endif // GAMETCPCLIENT_H
