#include "gameudpclient.h"
#include <QDataStream>
#include <QByteArray>
#include <QNetworkDatagram>
#include <QtWidgets/QMessageBox>

GameUdpClient::GameUdpClient(const QString &host, int port, QObject *parent)
    :QObject{parent}/*, m_udpSocket{new QUdpSocket{this}}, m_readySocket{new QUdpSocket{this}}*/
{

    qDebug() << "GameUdpClient start";
//    m_udpSocket->bind(QHostAddress::Any, 50081);
//    m_readySocket->bind(QHostAddress::Any, 50083);
//    connect(m_readySocket, static_cast<void(QUdpSocket::*)()>(&QUdpSocket::readyRead),
//        this, static_cast<void(GameUdpClient::*)()>(&GameUdpClient::onReadyRead));

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &GameUdpClient::timerCh);
    timer->start(2000);

    if(timer->isActive()) qDebug() << "Active";

//    sendDatagramm();
}

void GameUdpClient::onReadyRead()
{
    qDebug() << "GameUdpClient::onReadyRead()";
    QByteArray buf;
    QNetworkDatagram gr;

//    do {
//        buf.resize(m_udpSocket->pendingDatagramSize());
//        m_readySocket->readDatagram(buf.data(), buf.size());
//        //gr = m_udpSocket->receiveDatagram();
//    } while(m_readySocket->hasPendingDatagrams());

    QDataStream in(buf);
    QString str;
    in >> str;

    qDebug() << "Sever response = " << str;
}

void GameUdpClient::sendDatagramm()
{

    qDebug() << "client Send Datagramm";
    QByteArray buf;
    QDataStream out(&buf, QIODevice::WriteOnly);
    out << QString("I'm client Hello\n");


    m_udpSocket->writeDatagram(buf, QHostAddress::LocalHost, 50080);
}

void GameUdpClient::timerCh()
{
    qDebug() << "GameUdpClient::timerCh()";
}
