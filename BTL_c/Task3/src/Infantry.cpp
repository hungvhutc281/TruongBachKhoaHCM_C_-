#include "Infantry.h"

// TODO: implement

// ? Kiểm tra n có phải là số chính phương không
bool isPerfectSquare(int n) {
    // TODO: implement
int c=sqrt(n);
int d=c*c;
if (d==n) return true;
else return false;
}
// ? Tính tổng các chữ số của n
int sumDigits(int n) {
    // TODO: implement
    int sum = 0;
    while (n > 0) 
    {
        sum+=n % 10;  
        n/=10;         
    }
    return sum;
}
// ? Tính “số cá nhân”: tổng các chữ số của score và năm (1975), sau đó tiếp tục tính đến khi ra 1 chữ số.
int computeSingleDigit(int score) 
{
    // TODO: implement
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
int Infantry::getAttackScoreInFight()  
{
    return infantryType*56+quantity*weight;
}


//!----------------------------------------------
//! Lớp Infantry
//!----------------------------------------------
Infantry::Infantry(int quantity, int weight, Position pos, InfantryType infantryType)
    : Unit(quantity, weight, pos), infantryType(infantryType)
{
}
InfantryType Infantry::getType() const
{
    return infantryType;
}
int Infantry::getAttackScore() {
    // TODO: implement
    float score=infantryType * 56 + quantity * weight;
    if (infantryType==SPECIALFORCES && isPerfectSquare(weight)) score+=75;
    int tam1=computeSingleDigit(score);
    if (tam1>7)
    {
        quantity=ceil((quantity*120)/100.0);
        score=infantryType*56+quantity*weight;
    } else if (tam1<3)
    {
        quantity=ceil(quantity*0.9);
        score=infantryType*56+quantity*weight;
    } else score=infantryType*56+quantity*weight;
    return ceil(score);
}

string Infantry::str() const {
    // TODO: implement
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