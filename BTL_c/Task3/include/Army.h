#ifndef _H_ARMY_H_
#define _H_ARMY_H_

#include "UnitList.h"
using namespace std;

class BattleField; // forward declaration

class Army 
{
protected:
    int LF;        // * Tổng điểm từ các phương tiện (Vehicle)
    int EXP;       // * Tổng điểm từ các lực lượng bộ binh (Infantry)
    string name;
    UnitList *unitList;
    BattleField* battleField;
public:
    Army(Unit **unitArray, int size, string name, BattleField* battleField);
    virtual ~Army();
    virtual void fight(Army *enemy, bool defense = false) = 0;
    virtual string str() const = 0;
    int safeCeil(double value);
    void updateScore();
    Node* getHead();
    int getLF() const;
    int getEXP() const;
    UnitList* getUnitList() const;
    
    // * Additional functions if possible
};

#endif
