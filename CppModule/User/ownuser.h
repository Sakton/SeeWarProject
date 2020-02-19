#ifndef OWNUSER_H
#define OWNUSER_H
#include "baseuser.h"

class Flot;
class AbstractField;
class QQmlContext;

class OwnUser : public BaseUser
{
    Q_OBJECT
public:
    explicit OwnUser(QQmlContext *cotext, QObject *parent = nullptr);

private:
    QQmlContext *m_context;
    Flot *m_flot;
    AbstractField *m_ownField;
    AbstractField *m_enemyField;
};

#endif // OWNUSER_H
