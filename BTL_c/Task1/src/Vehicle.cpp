#include "Vehicle.h"

// TODO: implement

Vehicle::Vehicle ( int quantity , int weight , const Position pos , VehicleType vehicleType ):Unit(quantity,weight,pos),vehicleType(vehicleType)
{
}
int Vehicle::getAttackScore()
    {
        score=(vehicleType*304+(quantity*weight))/30.0;
        return ceil(score);
    }
string Vehicle::str() const
{
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
