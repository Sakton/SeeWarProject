#include "gameudpclient.h"
#include <QDataStream>
#include <QByteArray>
#include <QNetworkDatagram>
#include <QTimer>

GameUdpClient::GameUdpClient(const QString &host, int port, QObject *parent)
    :QObject(parent), m_udpSocket{new QUdpSocket{this}}
{
    connect(m_udpSocket, static_cast<void(QUdpSocket::*)()>(&QUdpSocket::readyRead),
        this, static_cast<void(GameUdpClient::*)()>(&GameUdpClient::onReadyRead));
    sendDatagramm();
}

void GameUdpClient::onReadyRead()
{
    qDebug() << "GameUdpClient::onReadyRead()";
    QNetworkDatagram datagramm{m_udpSocket->receiveDatagram()};
    QDataStream in(datagramm.data());
    QString mes;
    in >> mes;
    qDebug() << "echo mes = " << mes;
}

void GameUdpClient::sendDatagramm()
{
    QByteArray buf;
    QDataStream stream(&buf, QIODevice::WriteOnly);
    stream << QString("I'm client ");
    m_udpSocket->writeDatagram(buf, QHostAddress::LocalHost, 50080);
}
