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
    void setElementResultFireToEnemyField( StateMovesUser state );

public slots:
    //из QML
    void slotFromQml_ClickToCell(int indexCell);
    void slotFromQml_MessageChat(const QString &mes);
    //для QML
    //от другого игрока
    void slotFromEnemyUser_onFireToCellToQml(int index);
    void slotFromEnemyUser_onMessageToChatToQml(const QString &mes);

signals:
    //отправка
    void signalOwnUser_slotFromQml_clickedToCell( int indexCell );
    void signalOwnUser_sendMessage( const QString &mes );
    //прием и отправка в qml
    void signalToQml_answerMessageEnemyUser( const QString &mes );
    void signalToQml_answerFireToCell( int index );
    //ответ результата хода для отправки в сеть
    void signalOwnUser_answerToEnemyUserAboutFireCell( int );

private:
    //метод проверки выстрела и установки состояния
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
