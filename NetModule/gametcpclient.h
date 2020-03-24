#ifndef GAMETCPCLIENT_H
#define GAMETCPCLIENT_H
#include <QTcpSocket>
#include <QObject>
#include <QJsonDocument>
#include <QPointer>


class GameTcpClient : public QObject
{
    Q_OBJECT
public:
    explicit GameTcpClient(const QString &host, quint16 port, QObject *parent = nullptr);

    void sendJsonDocument(QJsonDocument *doc);
    QJsonDocument readJsonDocument();
    void send(const QByteArray* pByteArray);
public slots:


private slots:
    void slotConnectedToServer();
    void onReadyRead();
    void onError();

signals:
    void readyJsonDocument(const QByteArray*);

private:
    quint16 m_sizeData;
    quint16 m_port;
    QTcpSocket *m_tcpSocket;
};

#endif // GAMETCPCLIENT_H
