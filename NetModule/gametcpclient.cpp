#include "gametcpclient.h"

GameTcpClient::GameTcpClient(QObject *parent) : QObject(parent), m_sizeData{}, m_port{}, m_tcpSocket{new QTcpSocket(this)}
{

}
