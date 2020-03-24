#include "ownuser.h"
#include <QQmlContext>
#include <QDebug>
#include <QString>
#include <QJsonDocument>
#include "../Model/flot.h"
#include "../Model/field.h"
#include "../Elements/damageshipcell.h"
#include "../Elements/DamageEnemyShipCell.h"
#include "../Elements/damageemptycell.h"

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
//FIXME РАЗДЕЛИТЬ ПРИЕМ ПЕРЕДАЧУ ДАННЫХ ПУТАННИЦА
// отправка
void OwnUser::slotFromQml_ClickToCell(int indexCell)
{
    //Пришло с кумль
    //текущий
    m_currentFireIndex = indexCell;
    emit signalOwnUser_slotFromQml_clickedToCell(indexCell);
}

void OwnUser::slotFromQml_MessageChat(const QString &mes)
{
    emit signalOwnUser_sendMessage(mes);
}

void OwnUser::slotFromEnemyUser_onFireToCellToQml(int index)
{
    //пришло из сети
    //огбработка индекса выстрела и изменение в модели
    resultFireToThis(index);
    //отослать ответ
    emit signalOwnUser_answerToEnemyUserAboutFireCell( stateMovesUser() );
    //в кумль в чат
    emit signalToQml_answerFireToCell(index);
}

void OwnUser::slotFromEnemyUser_onMessageToChatToQml(const QString &mes)
{
    emit signalToQml_answerMessageEnemyUser(mes);
}

void OwnUser::resultFireToThis(int index)
{
    auto *fieldElement = qobject_cast<FieldElement*>(m_ownField->getFieldElementCell(index));
    auto *gameFigure = fieldElement->figure();
    if( ( qobject_cast<Paluba*>(gameFigure) ) != nullptr ) {
	auto dpl = new DamageShipCell(*qobject_cast<Paluba*>(gameFigure));
	fieldElement->setFigure(dpl);
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

void OwnUser::setElementResultFireToEnemyField(StateMovesUser state)
{
    switch(state) {
    case StateMovesUser::MISS: {
	auto fieldElement = m_enemyField->getFieldElementCell(m_currentFireIndex);
	DamageEmptyCell *damEmptyCell = new DamageEmptyCell();
	fieldElement->setFigure(damEmptyCell);
	break;
    }
    case StateMovesUser::DAMAGE: {
	auto fieldElement = m_enemyField->getFieldElementCell(m_currentFireIndex);
	DamageEnemyShipCell *damShipCell = new DamageEnemyShipCell();
	fieldElement->setFigure(damShipCell);
	break;
    }
    case StateMovesUser::HIT:
    case StateMovesUser::TEST:
	break;
    }
}
