#include "Infantry.h"

// TODO: implement
//enum InfantryType { SNIPER , ANTIAIRCRAFTSQUAD , MORTARSQUAD , ENGINEER , SPECIALFORCES , REGULARINFANTRY };

Infantry::Infantry ( int quantity , int weight , const Position pos , InfantryType infantryType ) : Unit(quantity, weight, pos), infantryType(infantryType) {}
bool isperfectNumber(int n)
{
  int c=sqrt(n);
  int d=c*c;
if (d==n) return true;
else return false;
}
int socanhan(int score)
{
    int tong=score+1975;
    while (tong>=10)
    {
        int tam=0;
        while (tong!=0)
        {
            tam+=tong%10;
            tong=tong/10;
        }
        tong=tam;
    }
return tong;
}
int Infantry::getAttackScore()
{
    score=infantryType * 56 + quantity * weight;
    if (infantryType==SPECIALFORCES && isperfectNumber(weight)) score+=75;
    int tam1=socanhan(score);
    if (tam1>7)
    {
        quantity=ceil((quantity*120)/100.0);
        score=infantryType*56+quantity*weight;
    } else if (tam1<3)
    {
        quantity=ceil(quantity-quantity*0.1);
        score=infantryType*56+quantity*weight;
    }
    return ceil(score);
}
string Infantry::str() const
{
    ostringstream info;
    string trave1;
    switch (infantryType)
    {
        case SNIPER: 
        trave1="SNIPER"; 
        break;
        case ANTIAIRCRAFTSQUAD: 
        trave1="ANTIAIRCRAFTSQUAD";
        break;
        case MORTARSQUAD: 
        trave1="MORTARSQUAD"; 
        break;
        case ENGINEER: 
        trave1="ENGINEER"; 
        break;
        case SPECIALFORCES: 
        trave1="SPECIALFORCES";
        break;
        case REGULARINFANTRY: 
        trave1="REGULARINFANTRY"; 
        break;
        default:
        break;
    }
    info<< "Infantry[infantryType="<<trave1<<",quantity="<<quantity<< ",weight=" << weight<< ",position=" << pos.str() << "]";
    return info.str();
}