#include "gameudpclient.h"
#include <QDataStream>
#include <QByteArray>
#include <QNetworkDatagram>

GameUdpClient::GameUdpClient(const QString &host, int port, QObject *parent)
    :QObject{parent}, m_udpSocket{new QUdpSocket{this}}
{
    m_udpSocket->bind(QHostAddress::LocalHost, 50081);
    connect(m_udpSocket, static_cast<void(QUdpSocket::*)()>(&QUdpSocket::readyRead),
        this, static_cast<void(GameUdpClient::*)()>(&GameUdpClient::onReadyRead));
   sendDatagramm();
   qDebug() << "GameUdpClient statrt";
}

void GameUdpClient::onReadyRead()
{
    qDebug() << "GameUdpClient::onReadyRead()";
    QByteArray buf;
    QNetworkDatagram gr;

    do {
        buf.resize(m_udpSocket->pendingDatagramSize());
        m_udpSocket->readDatagram(buf.data(), buf.size());
        //gr = m_udpSocket->receiveDatagram();
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
    m_udpSocket->writeDatagram(buf, QHostAddress::LocalHost, 50080);

    qDebug() << "client Send Datagramm";
}
