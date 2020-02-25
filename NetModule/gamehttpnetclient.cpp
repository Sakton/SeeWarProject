#include "gamehttpnetclient.h"
#include <QTcpSocket>

GameHttpNetClient::GameHttpNetClient(const QUrl &adress, quint16 port, QObject *parent)
    : GameNetClient{parent}, m_socket{new QTcpSocket(this)}, m_adress{adress}, m_port{port}
{
    m_socket->connectToHost(m_adress.toString(), m_port);
    connect(m_socket, &QTcpSocket::connected, this, &GameHttpNetClient::onConnected);
    connect(m_socket, &QTcpSocket::readyRead, this, &GameHttpNetClient::onReadyRead);
    connect(m_socket, &QTcpSocket::disconnected, this, &GameHttpNetClient::onDisconnected);
}

void GameHttpNetClient::onConnected()
{
    qDebug() << "GameHttpNetClient::onConnected()";
}

void GameHttpNetClient::onReadyRead()
{
    qDebug() << "GameHttpNetClient::onReadyRead()";
}

void GameHttpNetClient::onDisconnected()
{
    qDebug() << "GameHttpNetClient::onDisconnected()";
}

void GameHttpNetClient::sendMessage(const QString &mes)
{

}
