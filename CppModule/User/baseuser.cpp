#include "baseuser.h"
#include <QQmlContext>
#include "../GameCore/flot.h"
#include "../Model/field.h"

BaseUser::BaseUser(QObject *parent) : QObject(parent), m_damag{ResultMakeMove::MISS}, m_countMoves{3}
{
}
