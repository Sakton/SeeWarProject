#include "ownuser.h"
#include <QQmlContext>
#include <QDebug>
#include <QString>
#include <QJsonDocument>
#include "../Model/flot.h"
#include "../Model/field.h"
#include "../Elements/damageshipcell.h"

OwnUser::OwnUser(QQmlContext *cotext, QObject *parent)
    : BaseUser(parent), m_context{cotext}, m_ownField{}, m_enemyField{}, m_flot{}
{
    m_ownField = new Field(this);
    m_enemyField = new Field(this);
    m_flot = new Flot(m_ownField, this);
    //TODO создание классов в QML
    m_context->setContextProperty("OwnField", m_ownField);
    m_context->setContextProperty("EnemyField", m_enemyField);
    m_context->setContextProperty("Flot", m_flot);
}

// отправка
void OwnUser::onClickToCell(int indexCell)
{
    emit clickedToCell(indexCell);
}

void OwnUser::onMessageChat(const QString &mes)
{
    emit sendMessage(mes);
}

//прием
void OwnUser::onAnswerMessageToEnemyUser(const QString &mes)
{
    emit answerMessageToEnemyUserToQml(mes);
}

void OwnUser::onFireToCellToQml(int index)
{
    //огбработка индекса выстрела
    resultFireToThis(index);
    //в кумль в чат
    emit answerFireToCell(index);
}

void OwnUser::resultFireToThis(int index)
{
    auto *fieldElement = qobject_cast<FieldElement*>(m_ownField->getFieldElementCell(index));
    auto *gameFigure = fieldElement->figure();
    Paluba *ptr = nullptr;
    if( ( ptr = qobject_cast<Paluba*>(gameFigure) ) != nullptr ) {
        //FIXME ТАК!?
        ptr->setResourceImg("qrc:/QmlModule/qml/DefaultGui/img/cherep-v-krasnom-svete.gif");
        fieldElement->sendSignalToChange(index);
        ptr->getShip()->damage();
        setDamageState();
    } else {
        setMissState();
    }
}

bool OwnUser::getHod() const
{
    return hod;
}

void OwnUser::setHod(bool value)
{
    hod = value;
}
