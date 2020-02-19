#ifndef GAMEBLAKWATER_H
#define GAMEBLAKWATER_H
#include <QObject>
#include <QUrl>


class QQmlApplicationEngine;
class OwnUser;
class EnemyUser;
class AbstractField;
class QGuiApplication;
class

class GameBlackWater : public QObject
{
    Q_OBJECT
public:
    explicit GameBlackWater(const QUrl &pathOfGUI, QObject *parent = nullptr);

private:
    QUrl m_pathOfGUI;
    QQmlApplicationEngine *m_engine;
    OwnUser *m_ownUser;
    AbstractField *m_field;

};

#endif // GAMEBLAKWATER_H
