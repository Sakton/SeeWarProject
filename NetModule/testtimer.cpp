#include "testtimer.h"
#include <QTimer>
#include <QDebug>

TestTimer::TestTimer(QObject *parent) : QObject(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &TestTimer::tmr);
    timer->start(500);
}

void TestTimer::tmr()
{
    qDebug() << "timer";
}

