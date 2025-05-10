#include "../unit_test_Task3.hpp"

bool UNIT_TEST_Task3::Task322() {
    string name = "Task322";
    stringstream output;

    // Tạo 2 bộ đơn vị: một đơn vị gần (distance <= 1) và một đơn vị cách xa
    Infantry* inf_close = new Infantry(100, 5, Position(1, 1), SNIPER);
    Infantry* inf_far   = new Infantry(100, 5, Position(3, 3), SNIPER);
    Unit* units[2] = { inf_close, inf_far };
    Army* army = new ARVN(units, 2, "ARVN", nullptr);
    
    SpecialZone sz(Position(1, 1)); // Nằm trùng với đơn vị inf_close (distance = 0)
    sz.getEffect(army);
    
    output << "After SpecialZone field: Close unit: " << inf_close->str()
           << ", Far unit: " << inf_far->str();
    
    string result = output.str();
    string expect = "After SpecialZone field: Close unit: Infantry[infantryType=SNIPER,quantity=240,weight=5,position=(1,1)], Far unit: Infantry[infantryType=SNIPER,quantity=120,weight=5,position=(3,3)]";
    
    delete inf_close;
    delete inf_far;
    delete army;
    
    return printResult(result, expect, name);
}