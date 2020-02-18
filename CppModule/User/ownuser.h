#ifndef OWNUSER_H
#define OWNUSER_H
#include "baseuser.h"

class QQmlContext;

class OwnUser : public BaseUser
{
    Q_OBJECT
public:
    explicit OwnUser(QQmlContext *cotext, QObject *parent = nullptr);

signals:

};

#endif // OWNUSER_H
