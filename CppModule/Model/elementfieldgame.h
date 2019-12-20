#ifndef ELEMENTFIELDGAME_H
#define ELEMENTFIELDGAME_H
#include <QObject>
//элемент игрового поля - интерфейс всех элемнтов расположенных на поле

class ElementFieldGame : public QObject
{
        Q_OBJECT
public:
        explicit ElementFieldGame(QObject *parent = nullptr);
        virtual ~ElementFieldGame();
        virtual void getDamage(int index) = 0;
};

#endif // ELEMENTFIELDGAME_H
