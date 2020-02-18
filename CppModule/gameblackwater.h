#ifndef GAMEBLAKWATER_H
#define GAMEBLAKWATER_H
#include <QObject>


class QQmlApplicationEngine;
class OwnUser;
class EnemyUser;

class GameBlackWater : public QObject
{
    Q_OBJECT
public:
    explicit GameBlackWater(const QUrl &pathOfGUI, QObject *parent = nullptr);

private:
    QString m_pathOfGUI;
    QQmlApplicationEngine *m_engine;
    OwnUser *ownUser;
    EnemyUser *enemyUser;
};

#endif // GAMEBLAKWATER_H
