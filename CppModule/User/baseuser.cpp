#include "baseuser.h"
#include <QQmlContext>
#include "../GameCore/flot.h"
#include "../Model/field.h"

BaseUser::BaseUser(QObject *parent) : QObject(parent), m_stateMovesUser{StateMovesUser::MISS}, m_countMoves{StateMovesUser::MISS}, m_name{}
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

//void BaseUser::setDamag(StateMovesUser damag)
//{
//    // m_damag = (damag == 0) ? ResultMakeMove::YES : ResultMakeMove::NO;
//}

void BaseUser::setCountMoves(int countMoves)
{
    qDebug() << "countMoves = " << countMoves;
    m_countMoves = countMoves;
}
