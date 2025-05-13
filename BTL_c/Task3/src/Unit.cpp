#include "Unit.h"

//!----------------------------------------------
//! Lớp Unit
//!----------------------------------------------
Unit::Unit(int quantity, int weight, Position pos)
    : quantity(quantity), weight(weight), pos(pos)
{
}
Unit::~Unit()
{
    // Virtual destructor – nếu có bộ nhớ động thì giải phóng ở đây.
}
Position Unit::getCurrentPosition() const
{
    // TODO: Implement
    return pos;
}

void Unit::setWeight(int weight) 
{
    // TODO: Implement
    this->weight=weight;
}

void Unit::setQuantity(int quantity) {
    // TODO: Implement
    this->quantity=quantity;
}
int Unit::getQuantity()
{
    return quantity;
}
int  Unit::getWeight() const
{
  return weight;  
}
int Unit::safeCeil(double value)
{
    // TODO: Implement
    const double EPS = 1e-9; 
    if (abs(value-round(value)) < EPS) 
    {
    return static_cast<int>(round(value));
    }
    return static_cast<int>(ceil(value));
}
int Unit::setAttackScore(int attackScore)
{
return attackScore;
}