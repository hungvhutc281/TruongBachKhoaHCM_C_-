#include "Army.h"
#include "BattleField.h"

Army::Army(Unit **unitArray, int size, string name, BattleField* battleField) : name(name),LF(0),EXP(0),battleField(battleField)
{
    // Count unique vehicle types in order of appearance
    std::vector<VehicleType> vehicleTypes;
    for (int i = 0; i < size; i++) {
        Vehicle* v = dynamic_cast<Vehicle*>(unitArray[i]);
        if (v) {
            if (std::find(vehicleTypes.begin(), vehicleTypes.end(), v->getType()) == vehicleTypes.end()) {
                vehicleTypes.push_back(v->getType());
            }
        }
    }
    // Only take the first 2 vehicle types
    int maxVehicleTypes = std::min(2, (int)vehicleTypes.size());

    for (int i=0;i<size;i++)
    {
        Unit* unit=unitArray[i];
        if (dynamic_cast<Vehicle*>(unit)) 
        {
            LF+=unit->getAttackScore();
        }
        if (dynamic_cast<Infantry*>(unit)) 
        {
            EXP+=unit->getAttackScore();
        }
    }
    if (LF>=1000) LF=1000;
    if (EXP>=500) EXP=500;
    if (LF<=0)  LF=0;
    if (EXP<=0)  EXP=0;
    unitList = new UnitList(LF+EXP);
    unitList->setMaxVehicleTypes(maxVehicleTypes);
    for (int i=0;i<size;i++)
    {
        unitList->insert(unitArray[i]);
    }
}
UnitList* Army::getUnitList() const{
    return unitList;
}
Army::~Army() 
{
    // TODO: Implement
delete unitList;
}
int Army::getLF() const
{
    return LF;
}
int Army::getEXP() const
{
    return EXP;
}
void Army::fight(Army* enemy, bool defense) 
{
    // TODO: Implement
}

int Army::safeCeil(double value)
{
    // TODO: Implement
    const double EPS = 1e-9; 
    if (abs(value-round(value)) < EPS) 
    {
    return static_cast<int>(round(value));
    }
    return static_cast<int>(ceil(value));
}

void Army::updateScore()
{
    // TODO: Implement
    LF = 0;
    EXP = 0;
    node cur = unitList->getHead(); 
    while (cur != nullptr) 
    {
        Unit* unit = cur->unit;

        if (Vehicle* veh = dynamic_cast<Vehicle*>(unit)) 
        {
            LF += veh->getAttackScore(); 
        } 
        else if (Infantry* inf = dynamic_cast<Infantry*>(unit)) 
        {
            EXP += inf->getAttackScore();
        }
        cur = cur->next;
    }
    if (LF >= 1000) LF = 1000;
    if (LF <= 0) LF = 0;
    if (EXP >= 500) EXP = 500;
    if (EXP <= 0) EXP = 0;
}