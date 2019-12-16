#ifndef PALUBA_H
#define PALUBA_H


class Paluba
{
    int index;
    bool isDead;
public:
    Paluba(int ind = 0, bool dd = false);
    int getIndex() const;
    void setIndex(int value);
    bool getIsDead() const;
    void setIsDead(bool value);
};

#endif // PALUBA_H
