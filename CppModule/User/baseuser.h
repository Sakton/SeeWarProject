#ifndef BASEUSER_H
#define BASEUSER_H
#include <QObject>

class BaseUser : public QObject
{
    Q_OBJECT
public:
    explicit BaseUser(QObject *parent = nullptr);
};

#endif // BASEUSER_H
