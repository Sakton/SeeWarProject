#ifndef GAMEBLAKWATER_H
#define GAMEBLAKWATER_H
#include <QObject>
#include <QUrl>


class QQmlApplicationEngine;
class OwnUser;
class EnemyUser;
class AbstractField;
class QGuiApplication;
//class GameUdpClient;
class GameTcpClient;


class GameBlackWater : public QObject
{
    Q_OBJECT
public:
    explicit GameBlackWater(const QUrl &pathOfGUI, QObject *parent = nullptr);

public slots:

private slots:
//    void onClickedToCell(int indexCell);
//    void onSendMessage(const QString &mes);

signals:
    void sendJsonDocument(const QByteArray &object);

private:
    QUrl m_pathOfGUI;
    QQmlApplicationEngine *m_engine;
    OwnUser *m_ownUser;
    AbstractField *m_field;
    GameTcpClient *m_tcpNetClient;
    int gameId;
};

#endif // GAMEBLAKWATER_H
