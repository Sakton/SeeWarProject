#include "baseuser.h"
#include <QQmlContext>
#include "../GameCore/flot.h"
#include "../Model/field.h"

BaseUser::BaseUser(QQmlContext *context, QObject *parent) : QObject(parent), m_context{context}
{
    m_ownField = new Field(this);
    m_enemyField = new Field(this);

    m_flot = new Flot(m_ownField, this);

    m_context->setContextProperty("OwnField", m_ownField);
    m_context->setContextProperty("EnemyField", m_enemyField);
    m_context->setContextProperty("Flot", m_flot);
}
