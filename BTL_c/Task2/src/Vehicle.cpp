#include "Vehicle.h"

//!----------------------------------------------
//! Lớp Vehicle
//!----------------------------------------------
Vehicle::Vehicle(int quantity, int weight, Position pos, VehicleType vehicleType)
    : Unit(quantity, weight, pos), vehicleType(vehicleType)
{
}
VehicleType Vehicle:: getType() const
{
    return vehicleType;
}
int Vehicle::getAttackScore()
{
    // TODO: Implement
    return safeCeil((vehicleType*304+(quantity*weight))/30.0);
}

/* 
@Fix
 */
string Vehicle::str() const
{
    // TODO: Implement
    ostringstream ss;
    string trave;
    switch(vehicleType)
    {
        case TRUCK:
        trave="TRUCK";
        break;
        case MORTAR:
        trave="MORTAR";
        break;
        case ANTIAIRCRAFT:
        trave="ANTIAIRCRAFT";
        break;
        case ARMOREDCAR: 
        trave="ARMOREDCAR";
        break;
        case APC: 
        trave="APC";
        break;
        case ARTILLERY: 
        trave="ARTILLERY";
        break;
        case TANK:
        trave="TANK";
        break;
        default:
        break;
    }
 ss<<"Vehicle[vehicleType="<< trave<< ",quantity="<<quantity<<",weight="<<weight<<",position="<<pos.str()<< "]";
        return ss.str();
}