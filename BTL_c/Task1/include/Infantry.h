#ifndef INFANTRY_H
#define INFANTRY_H

#include "Unit.h"

enum InfantryType
{
    SNIPER,
    ANTIAIRCRAFTSQUAD,
    MORTARSQUAD,
    ENGINEER,
    SPECIALFORCES,
    REGULARINFANTRY
};

inline bool isperfectNumber(int n);
inline int socanhan(int score);

class Infantry : public Unit
{
    // TODO: implement
    private:
    InfantryType infantryType;
    public:
    float score;
    Infantry ( int quantity , int weight , const Position pos , InfantryType infantryType );
    
    
    int getAttackScore() override;
    string str() const override;

};

#endif // INFANTRY_H