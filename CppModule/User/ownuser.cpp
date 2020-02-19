#include "ownuser.h"
#include <QQmlContext>
#include "../GameCore/flot.h"
#include "../Model/field.h"

OwnUser::OwnUser(QQmlContext *cotext, QObject *parent)
    : BaseUser(parent), m_context{cotext}
{
    m_ownField = new Field(this);
    m_enemyField = new Field(this);

    m_flot = new Flot(m_ownField, this);

    m_context->setContextProperty("OwnField", m_ownField);
    m_context->setContextProperty("EnemyField", m_enemyField);
    m_context->setContextProperty("Flot", m_flot);
}
