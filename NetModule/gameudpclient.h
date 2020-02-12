#ifndef GAMEUDPCLIENT_H
#define GAMEUDPCLIENT_H
#include <QObject>
#include <QUdpSocket>

class GameUdpClient : public QObject
{
    Q_OBJECT
public:
    explicit GameUdpClient(const QString &host, int port,  QObject *parent = nullptr);

public slots:
    void onReadyRead();
    void sendDatagramm();

private:
    QUdpSocket *m_udpSocket;
};

#endif // GAMEUDPCLIENT_H
