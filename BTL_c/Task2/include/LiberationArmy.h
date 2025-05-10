#ifndef _H_LIBERATIONARMY_H_
#define _H_LIBERATIONARMY_H_

#include "Army.h"
class LiberationArmy : public Army
{
private:
    Unit **unitArray;       // For temporary
    int size_V = 0;         // For temporary: vehicle count
    int size_I = 0;         // For temporary: infantry count
    int nearestFibonacci(int value);
    Unit* cloneUnit(Unit* unit);
    vector<Unit*> tohopA_list;
    vector<Unit*> tohopB_list;
    bool tohopA=false;
    bool tohopB=false;
public:
    LiberationArmy(Unit **unitArray, int size, string name);
    void fight(Army *enemy, bool defense) override;
    vector<Unit*> knapsack(Node* head, int minScore);
    string str() const override; 
    // bool kiemtratype(Unit* a, Unit* b);
    // void tontaitohop(int muc_tieu);
};

#endif