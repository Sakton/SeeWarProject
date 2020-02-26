#ifndef GAMETCPCLIENT_H
#define GAMETCPCLIENT_H
#include <QTcpSocket>
#include <QObject>
//#include <QNetworkAccessManager>

#include "gamenetclient.h"


class GameTcpClient : public GameNetClient
{
    Q_OBJECT
public:
    explicit GameTcpClient(const QString &host, quint16 port, QObject *parent = nullptr);

    void sendToServsrTest(const QString &s);
    // GameNetClient interface
public slots:
    void sendMessage(const QString &mes) override;
    void sendFireIndex(int index) override;

private slots:
    void slotConnectedToServer();
    void onReadyRead();
    void onError();

signals:
    void answerMessageFromServer(const QString &mes);
    void answerFireIndex(int index);

private:
    quint16 m_sizeData;
    quint16 m_port;
    QTcpSocket *m_tcpSocket;
};

#endif // GAMETCPCLIENT_H
