#include "gameudpclient.h"
#include <QDataStream>
#include <QByteArray>

GameUdpClient::GameUdpClient(const QString &host, int port, QObject *parent)
    :QObject{parent}, m_udpSocket{new QUdpSocket{this}}
{
    m_udpSocket->bind(QHostAddress{host}, port);
    connect(m_udpSocket, static_cast<void(QUdpSocket::*)()>(&QUdpSocket::readyRead),
        this, static_cast<void(GameUdpClient::*)()>(&GameUdpClient::onReadyRead));
    qDebug() << "GameUdpClient statrt";
    sendDatagramm();
}

void GameUdpClient::onReadyRead()
{
    qDebug() << "GameUdpClient::onReadyRead()";
    QByteArray buf;
    do {
        buf.resize(m_udpSocket->pendingDatagramSize());
        m_udpSocket->readDatagram(buf.data(), buf.size());
    } while(m_udpSocket->hasPendingDatagrams());
    QDataStream in(buf);
    QString str;
    in >> str;

    qDebug() << "Sever response = " << str;
}

void GameUdpClient::sendDatagramm()
{
    QByteArray buf;
    QDataStream out(&buf, QIODevice::WriteOnly);
    out << QString("I'm client Hello");
    m_udpSocket->writeDatagram(buf, QHostAddress::LocalHost, 2424);

}
