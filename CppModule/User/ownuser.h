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

    bool getHod() const;
    void setHod(bool value);

public slots:
    //из QML
    void onClickToCell(int indexCell);
    void onMessageChat(const QString &mes);
    //для QML
    void onAnswerMessageToEnemyUser(const QString &mes);
    //от другого игрока
    void onFireToCellToQml(int index);


signals:
    //отправка
    void clickedToCell(int indexCell);
    void sendMessage(const QString &mes);
    //прием и отправка в qml
    void answerMessageToEnemyUserToQml(const QString &mes);
    void answerFireToCell(int index);
    //ответ результата хода для отправки в сеть
    void answerFireEnemyUserToNet(int);

private:
    void resultFireToThis(int);

private:
    QQmlContext *m_context;
    Field *m_ownField;
    Field *m_enemyField;
    Flot *m_flot;
    bool hod;
    int m_currentFireIndex;
};

#endif // OWNUSER_H
