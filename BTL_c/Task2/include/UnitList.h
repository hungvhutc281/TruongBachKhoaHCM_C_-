#ifndef _H_UNITLIST_H_
#define _H_UNITLIST_H_

#include "Infantry.h"
#include "Vehicle.h"
struct Node
{
    Unit* unit;
    Node *next;
};
typedef struct Node *node;
class UnitList
{
private:
    int LF,EXP,S;
    int capacity;
    node head;
    vector<Unit *> units;
    int countVehicle, countInfantry;

public:
    vector<Unit*> layvector();
    UnitList(int capacity);
    bool insert(Unit *unit);
    bool isContain(VehicleType vehicleType);
    bool isContain(InfantryType infantryType);
    //vector<Unit *> getUnits() const;
    string str() const;
    node getHead() const;
    void succhuatoida(int LF,int EXP);
    void remove(const vector<Unit*> &units); 
    void remove1();
    void remove2();
    // * Additional functions if possible
};

#endif
