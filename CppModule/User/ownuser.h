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
    void setElementResultFireToEnemyField( StateMovesUser state );
    //право хода
    int pravoHoda() const;

public slots:
    //из QML
    void slotFromQml_ClickToCell(int indexCell);
    void slotFromQml_MessageChat(const QString &mes);
    //для QML
    //от другого игрока
    void slotFromEnemyUser_onFireToCellToQml(int index);
    void slotFromEnemyUser_onMessageToChatToQml(const QString &mes);
    void slotFromFlot_DeadFlot();
    //слоты от флот
//    void slotFromShip_onDamageShip();
//    void slotFromShip_onDeadShip();
//    void slotFromShip_onDeadFlot();

signals:
    //отправка
    void signalOwnUser_slotFromQml_clickedToCell( int indexCell );
    void signalOwnUser_sendMessage( const QString &mes );
    //прием и отправка в qml
    void signalToQml_answerMessageEnemyUser( const QString &mes );
    void signalToQml_answerFireToCell( int index );
    //ответ результата хода для отправки в сеть
    void signalOwnUser_answerToEnemyUserAboutFireCell( int );
    //продвижение сигналов
    void signalOwnUser_DamageShip();
    void signalOwnUser_DeadShip();
    void signalOwnUser_DeadFlot();


private:
    //метод проверки выстрела и установки состояния
    void resultFireToThis(int);

private:
    QQmlContext *m_context;
    Field *m_ownField;
    Field *m_enemyField;
    Flot *m_flot;
    int m_currentFireIndex;
};

#endif // OWNUSER_H
