#ifndef TESTTIMER_H
#define TESTTIMER_H

#include <QObject>

class TestTimer : public QObject
{
    Q_OBJECT
public:
    explicit TestTimer(QObject *parent = nullptr);

private slots:
    void tmr();

signals:

};

#endif // TESTTIMER_H
