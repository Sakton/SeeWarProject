#ifndef GAMEBLAKWATER_H
#define GAMEBLAKWATER_H
#include <QObject>
#include <QUrl>
#include <map>


class QQmlApplicationEngine;
class OwnUser;
class EnemyUser;
class AbstractField;
class QGuiApplication;
class GameTcpClient;
class QJsonDocument;
class QJsonObject;


class GameBlackWater : public QObject
{
    Q_OBJECT
public:
    explicit GameBlackWater(const QUrl &pathOfGUI, QObject *parent = nullptr);

private slots:
    void onClickedToCell(int indexCell);
    void onSendMessage(const QString &mes);
    void sendJsonDocument();

private:
    QJsonDocument createJsonDocument();

private:
    QUrl m_pathOfGUI;
    QQmlApplicationEngine *m_engine;
    OwnUser *m_ownUser;
    AbstractField *m_field;
    GameTcpClient *m_tcpNetClient;
    int gameId;
    QJsonObject *m_jobj;
};

#endif // GAMEBLAKWATER_H
