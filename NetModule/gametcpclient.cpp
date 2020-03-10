#include "gametcpclient.h"
#include <QNetworkReply>
#include <QNetworkRequest>
#include "myjsonobjects.h"
#include <QString>

GameTcpClient::GameTcpClient(const QString &host, quint16 port, QObject *parent)
    : QObject(parent), m_sizeData{}, m_port{port}, m_tcpSocket{new QTcpSocket(this)}
{
    m_tcpSocket->connectToHost(host, port);
    connect(m_tcpSocket, static_cast<void(QTcpSocket::*)()>(&QTcpSocket::connected),
        this, static_cast<void(GameTcpClient::*)()>(&GameTcpClient::slotConnectedToServer));
    connect(m_tcpSocket, static_cast<void(QTcpSocket::*)()>(&QTcpSocket::readyRead),
        this, static_cast<void(GameTcpClient::*)()>(&GameTcpClient::onReadyRead));
    connect(m_tcpSocket, static_cast<void(QTcpSocket::*)()>(&QTcpSocket::disconnected),
    m_tcpSocket, static_cast<void(QTcpSocket::*)()>(&QTcpSocket::deleteLater));
}

void GameTcpClient::sendJsonDocument(QJsonDocument *doc)
{
    qDebug() << "send doc = " << *doc;
    m_tcpSocket->write(doc->toJson());
}

void GameTcpClient::slotConnectedToServer()
{
    qDebug() << "connected";
}

void GameTcpClient::onReadyRead()
{
    QByteArray *read = new QByteArray(m_tcpSocket->readAll());
    emit readyJsonDocument(read);
    qDebug() << *read;
}

void GameTcpClient::onError()
{

}
