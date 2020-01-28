#ifndef GAMETCPCLIENT_H
#define GAMETCPCLIENT_H
#include <QTcpSocket>
#include <QObject>


class GameTcpClient : public QObject
{
public:
    explicit GameTcpClient(QObject *parent = nullptr);



private slots:
    void slotConnectedToServer();

private:
    qint16 m_sizeData;
    qint16 m_port;
    QTcpSocket *m_tcpSocket;
};

#endif // GAMETCPCLIENT_H
