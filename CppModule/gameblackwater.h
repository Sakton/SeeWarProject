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
    void onClickedToCell(int indexCell);
    void onSendMessage(const QString &mes);
    void sendJsonDocument();
    void readJsonDocument(const QByteArray *answer);
//    void readJsonDocument(QPointer<QByteArray> answer);

private:
    void createJsonDocument();
    void send(QByteArray* pByteArray);

private:
    QUrl m_pathOfGUI;
    QQmlApplicationEngine *m_engine;
    OwnUser *m_ownUser;
    AbstractField *m_field;
    GameTcpClient *m_tcpNetClient;
    int gameId;
    QJsonDocument *m_doc;
    QJsonObject *m_obj;
};

#endif // GAMEBLAKWATER_H
