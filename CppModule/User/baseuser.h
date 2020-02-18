#ifndef BASEUSER_H
#define BASEUSER_H
#include <QObject>

class Flot;
class Field;
class QQmlContext;

class BaseUser : public QObject
{
    Q_OBJECT
public:
    explicit BaseUser(QQmlContext *context, QObject *parent = nullptr);

private:
    QQmlContext *m_context;
    Flot *m_flot;
    Field *m_ownField;
    Field *m_enemyField;
};

#endif // BASEUSER_H
