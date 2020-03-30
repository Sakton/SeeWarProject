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
    //сигналы от флота
    connect(m_flot, &Flot::signalFlot_FlotDead, this, &OwnUser::slotFromFlot_DeadFlot);
    //продвижение сигналов
    connect(m_flot, &Flot::signalFlot_DamageShip, this, &OwnUser::signalOwnUser_DamageShip);
    connect(m_flot, &Flot::signalFlot_DeadShip, this, &OwnUser::signalOwnUser_DeadShip);
    connect(m_flot, &Flot::signalFlot_FlotDead, this, &OwnUser::signalOwnUser_DeadFlot);
}

// отправка
void OwnUser::slotFromQml_ClickToCell(int indexCell)
{
    //Пришло с кумль
    //текущий
    m_currentFireIndex = indexCell;
    //уменьшаем количество доступных ходов
    --m_countMoves;
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

void OwnUser::slotFromFlot_DeadFlot()
{
    qDebug() << "SLOT OWNUSER FLOT DEAD";
}

void OwnUser::resultFireToThis(int index)
{
    auto *fieldElement = qobject_cast<FieldElement*>(m_ownField->getFieldElementCell(index));
    auto *gameFigure = fieldElement->figure();
    auto paluba = qobject_cast<Paluba*>(gameFigure);
    if( paluba != nullptr ) {
	auto ship = paluba->getShip();
	ship->damage(paluba);
	setDamageState();
    } else {
	auto miss = new DamageEmptyCell;
	fieldElement->setFigure(miss);
	setMissState();
    }
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
	setHitState();
	break;
    }
    case StateMovesUser::HIT:
	break;
    }
}

