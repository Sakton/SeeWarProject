#ifndef ENEMYUSER_H
#define ENEMYUSER_H
#include "baseuser.h"

class EnemyUser : public BaseUser
{
    Q_OBJECT
public:
    explicit EnemyUser(QObject *parent = nullptr);
};

#endif // ENEMYUSER_H
