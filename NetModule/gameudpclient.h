#ifndef GAMEUDPCLIENT_H
#define GAMEUDPCLIENT_H
#include <QObject>
#include <QUdpSocket>
#include <QTimer>

class GameUdpClient : public QObject
{
    Q_OBJECT
public:
    explicit GameUdpClient(const QString &host, int port,  QObject *parent = nullptr);

public slots:
    void onReadyRead();
    void sendDatagramm();
    void timerCh();

private:
    QUdpSocket *m_udpSocket;
    QUdpSocket *m_readySocket;
};

#endif // GAMEUDPCLIENT_H
