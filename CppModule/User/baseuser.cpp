#include "baseuser.h"
#include <QQmlContext>
#include "../GameCore/flot.h"
#include "../Model/field.h"

//TODO Число ходов тут
BaseUser::BaseUser(QObject *parent) : QObject(parent),
    m_stateMovesUser{StateMovesUser::MISS}, m_countMoves{StateMovesUser::TEST}, m_name{}
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
    //TODO плохо тут подумать
    m_countMoves = 0;
}

void BaseUser::setMissState()
{
    m_stateMovesUser = StateMovesUser::MISS;
    m_countMoves = 1;
}

void BaseUser::setHitState()
{
    m_stateMovesUser = StateMovesUser::HIT;
    m_countMoves = 2;
}

void BaseUser::setOwnStateFromEnemyState(BaseUser::StateMovesUser enemyState)
{
    switch (enemyState) {
    case BaseUser::StateMovesUser::DAMAGE:
        setHitState();
    case BaseUser::StateMovesUser::MISS:
        setMissState();
    case BaseUser::StateMovesUser::HIT:
        setDamageState();
    }
}

void BaseUser::setCountMoves(int countMoves)
{
    qDebug() << "countMoves = " << countMoves;
    m_countMoves = countMoves;
}
