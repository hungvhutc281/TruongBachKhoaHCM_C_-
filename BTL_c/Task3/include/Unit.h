#ifndef UNIT_H
#define UNIT_H

#include "Position.h"

class Unit
{
protected:
    int quantity, weight;
    Position pos;
    int attackScore;
public:
    Unit(int quantity, int weight, Position pos);
    virtual ~Unit();
    virtual int getAttackScore() = 0;
    Position getCurrentPosition() const;
    virtual string str() const = 0;
    void setWeight(int weight);
    int getWeight() const;
    void setQuantity(int quantity);
    int getQuantity();
    int safeCeil(double value);
    int setAttackScore(int attackScore);
    };

#endif // UNIT_H