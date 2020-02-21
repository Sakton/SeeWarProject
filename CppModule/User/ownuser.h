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

public slots:
    void onClickToCell(int indexCell);
    void onMessageChat(const QString &mes);

signals:
    void clickedToCell(int indexCell);
    void sendMessage(const QString &mes);


private:
    QQmlContext *m_context;
    AbstractField *m_ownField;
    AbstractField *m_enemyField;
    Flot *m_flot;
};

#endif // OWNUSER_H
