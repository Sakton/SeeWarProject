#include "ownuser.h"
#include <QQmlContext>
#include "../GameCore/flot.h"
#include "../Model/field.h"
#include <QDebug>
#include <QString>

OwnUser::OwnUser(QQmlContext *cotext, QObject *parent)
    : BaseUser(parent), m_context{cotext}, m_ownField{}, m_enemyField{}, m_flot{}
{
    m_ownField = new Field(this);
    m_enemyField = new Field(this);
    m_flot = new Flot(m_ownField, this);

    m_context->setContextProperty("OwnField", m_ownField);
    m_context->setContextProperty("EnemyField", m_enemyField);
    m_context->setContextProperty("Flot", m_flot);
}

void OwnUser::onClickToCell(int indexCell)
{
    emit clickedToCell(indexCell);
}

void OwnUser::onMessageChat(const QString &mes)
{
    emit sendMessage(mes);
}

void OwnUser::onAnswerMessageToEnemyUser(const QString &mes)
{
    emit answerMessageToEnemyUserToQml(mes);
}
