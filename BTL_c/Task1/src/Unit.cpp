#include "Unit.h"

Unit::Unit(int quantity, int weight, Position pos)
{
    // TODO: implement
    this->quantity=quantity;
    this->weight=weight;
    this->pos=pos;
}
Unit::~Unit()
{
// TODO: implement

}
// int getAttackScore()=0;
Position Unit::getCurrentPosition() const
{
    return pos;
}
 //string str () const = 0;
