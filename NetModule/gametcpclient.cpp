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

//FIXME тут передачи указателей смотрим на очищение памяти

void GameTcpClient::sendJsonDocument(QJsonDocument *doc)
{
    m_tcpSocket->write(doc->toJson());
}

void GameTcpClient::send(const QByteArray *pByteArray)
{
    m_tcpSocket->write(*pByteArray);
}

void GameTcpClient::slotConnectedToServer()
{
    qDebug() << "connected";
}

void GameTcpClient::onReadyRead()
{
//    QByteArray *read = new QByteArray(m_tcpSocket->readAll());
    QByteArray* read = new QByteArray(m_tcpSocket->readAll());
    //отправляю указатель на прочитанное сообщение
    qDebug() << "mes = " << *read;
    //FIXME передача владения в другой объект
    emit readyJsonDocument(read);
}

void GameTcpClient::onError()
{

}
