#ifndef GAMEBLAKWATER_H
#define GAMEBLAKWATER_H
#include <QObject>
#include <QUrl>
#include <map>
#include <memory>


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
    ~GameBlackWater();

private slots:
    void slotFromOwnUser_onClickedToCell(int indexCell);
    void slotFromOwnUser_onSendMessage(const QString &mes);
    void slotFromOwnuser_DamageShip();
    void slotFromOwnuser_DeadShip();
    void slotFromOwnuser_DeadFlot();
    void slotFromOwnuser_Miss();

signals:
    void signalMoyHod();

private:
    void sendJsonDocument();
    void readJsonDocument(const QByteArray *answer);
    void sender(const QString &key, int value);

private:
    QUrl m_pathOfGUI;
    QQmlApplicationEngine *m_engine;
    OwnUser *m_ownUser;
    AbstractField *m_field;
    GameTcpClient *m_tcpNetClient;
    int gameId;
    QJsonDocument *m_doc;
    QJsonObject *m_obj;
    void sender();
};

#endif // GAMEBLAKWATER_H
