#include "baseuser.h"
#include <QQmlContext>
#include "../Model/flot.h"
#include "../Model/field.h"

//TODO Число ходов тут
BaseUser::BaseUser(QObject *parent) : QObject(parent),
    m_stateMovesUser{StateMovesUser::MISS}, m_countMoves{int(StateMovesUser::MISS)}, m_name{}
{
}

BaseUser::StateMovesUser BaseUser::stateMovesUser() const
{
    return m_stateMovesUser;
}

int BaseUser::countMoves() const
{
    return m_countMoves;
}

QString BaseUser::name() const
{
    return m_name;
}

void BaseUser::setName(const QString &name)
{
    m_name = name;
}

void BaseUser::setDamageState()
{
    m_stateMovesUser = StateMovesUser::DAMAGE;
    m_countMoves = 0;
    qDebug() << "BaseUser::setDamageState()";
}

void BaseUser::setMissState()
{
    m_stateMovesUser = StateMovesUser::MISS;
    m_countMoves = 1;
    qDebug() << "BaseUser::setMissState()";
}

void BaseUser::setHitState()
{
    m_stateMovesUser = StateMovesUser::HIT;
    m_countMoves = 1;
    qDebug() << "BaseUser::setHitState()";
}

void BaseUser::setOwnStateFromEnemyState(BaseUser::StateMovesUser enemyState)
{
    switch (enemyState) {
    case BaseUser::StateMovesUser::DAMAGE: {
        setHitState();
        break;
    }
    case BaseUser::StateMovesUser::MISS: {
        setMissState();
        break;
    }
    case BaseUser::StateMovesUser::HIT: {
        //setDamageState();
        break;
    }

    }
}

void BaseUser::setCountMoves(int countMoves)
{
    m_countMoves = countMoves;
}
