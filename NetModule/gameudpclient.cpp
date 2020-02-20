#include "gameudpclient.h"
#include <QDataStream>
#include <QByteArray>
#include <QNetworkDatagram>
#include <QTimer>

GameUdpClient::GameUdpClient(const QString &host, int port, QObject *parent)
    :GameNetClient(parent), m_udpSocket{new QUdpSocket{this}}
{
    connect(m_udpSocket, static_cast<void(QUdpSocket::*)()>(&QUdpSocket::readyRead),
        this, static_cast<void(GameUdpClient::*)()>(&GameUdpClient::onReadyRead));

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout,
        this, static_cast<void(GameUdpClient::*)()>(&GameUdpClient::sendDatagramm));
    timer->start(1000);
//    sendDatagramm();
}

void GameUdpClient::onReadyRead()
{
    QNetworkDatagram datagramm{m_udpSocket->receiveDatagram()};
    QDataStream in(datagramm.data());
    QString mes;
    in >> mes;
    qDebug() << "echo mes = " << mes;
}

void GameUdpClient::onError()
{

}

void GameUdpClient::onSendDatagramMessage(const QString &mes)
{
    qDebug() << "GameUdpClient::onSendDatagramMessage = " << mes;
}

void GameUdpClient::onSentDatagrammClickedIndex(int indexClickedCell)
{
    qDebug() << "GameUdpClient::onSentDatagrammClickedIndex = " << indexClickedCell;
}

void GameUdpClient::sendDatagramm()
{
    QByteArray buf;
    QDataStream stream(&buf, QIODevice::WriteOnly);
    stream << QString("I'm client ");
    m_udpSocket->writeDatagram(buf, QHostAddress::LocalHost, 50080);
}

void GameUdpClient::sendMessage(const QString &s)
{
    QByteArray buf;
    QDataStream out(&buf, QIODevice::WriteOnly);
    out << s;

}
