#include "gametcpclient.h"
#include <QNetworkReply>
#include <QNetworkRequest>
#include "myjsonobjects.h"

GameTcpClient::GameTcpClient(const QString &host, quint16 port, QObject *parent)
    : GameNetClient(parent), m_sizeData{}, m_port{port}, m_tcpSocket{new QTcpSocket(this)}//, m_manager{new QNetworkAccessManager(this)}
{
    m_tcpSocket->connectToHost(host, port);
    connect(m_tcpSocket, static_cast<void(QTcpSocket::*)()>(&QTcpSocket::connected),
        this, static_cast<void(GameTcpClient::*)()>(&GameTcpClient::slotConnectedToServer));
    connect(m_tcpSocket, static_cast<void(QTcpSocket::*)()>(&QTcpSocket::readyRead),
        this, static_cast<void(GameTcpClient::*)()>(&GameTcpClient::onReadyRead));
    connect(m_tcpSocket, static_cast<void(QTcpSocket::*)()>(&QTcpSocket::disconnected),
        m_tcpSocket, static_cast<void(QTcpSocket::*)()>(&QTcpSocket::deleteLater));
}


void GameTcpClient::sendToServsrTest(const QString &s)
{
    m_tcpSocket->write(s.toLatin1());
}

void GameTcpClient::sendMessage(const QString &mes)
{
    sendToServsrTest(mes);
}

void GameTcpClient::slotConnectedToServer()
{
    qDebug() << "GAME CLIENT CONNECT TO SERVER";
    sendToServsrTest("I am' tytti");
}

void GameTcpClient::onReadyRead()
{
    qDebug() << "GAME CLIENT ONREADYREAD";
    QString answer(m_tcpSocket->readAll());
    qDebug() << "answer << ==== " << answer;
}

void GameTcpClient::onError()
{
    qDebug() << "GAME CLIENT ONERROR";
    m_tcpSocket->close();
}
