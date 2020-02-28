#ifndef GAMETCPCLIENT_H
#define GAMETCPCLIENT_H
#include <QTcpSocket>
#include <QObject>
#include <QJsonDocument>

#include "gamenetclient.h"


class GameTcpClient : public QObject
{
    Q_OBJECT
public:
    explicit GameTcpClient(const QString &host, quint16 port, QObject *parent = nullptr);


public slots:


private slots:
    void slotConnectedToServer();
    void onReadyRead();
    void onError();

signals:
    void readyJsonDocument(QJsonDocument doc);

private:
    quint16 m_sizeData;
    quint16 m_port;
    QTcpSocket *m_tcpSocket;
};

#endif // GAMETCPCLIENT_H
