#ifndef OWNUSER_H
#define OWNUSER_H
#include "baseuser.h"

class Flot;
class Field;
class AbstractField;
class QQmlContext;

class OwnUser : public BaseUser
{
    Q_OBJECT
public:
    explicit OwnUser(QQmlContext *cotext, QObject *parent = nullptr);

    //???
    void isDamage();

public slots:
    //из QML
    void onClickToCell(int indexCell);
    void onMessageChat(const QString &mes);
    //для QML
    void onAnswerMessageToEnemyUser(const QString &mes);
    void onFireToCellToQml(int index);


signals:
    void clickedToCell(int indexCell);
    void sendMessage(const QString &mes);
    void answerMessageToEnemyUserToQml(const QString &mes);
    void answerFireToCell(int index);

private:
    QQmlContext *m_context;
    AbstractField *m_ownField;
    AbstractField *m_enemyField;
    Flot *m_flot;
};

#endif // OWNUSER_H
