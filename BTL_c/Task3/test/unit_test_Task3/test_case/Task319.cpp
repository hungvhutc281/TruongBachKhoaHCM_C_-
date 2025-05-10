#include "../unit_test_Task3.hpp"

bool UNIT_TEST_Task3::Task319() {
    string name = "Task319";
    stringstream output;

    // Tạo một đơn vị bộ binh nằm trong bán kính 2 của River
    Infantry* infantry = new Infantry(100, 5, Position(1, 1), SNIPER);
    Unit* unitArray[1] = { infantry };
    Army* army = new ARVN(unitArray, 1, "ARVN_Test", nullptr);
    int originalAttack = infantry->getAttackScore();

    River river(Position(1, 0));
    river.getEffect(army);

    int newAttack = infantry->getAttackScore();
    double diff = (newAttack - originalAttack) / (double)originalAttack * 100;
    
    output << "ARVN Fort: " << army->str() << "\n";
    
    string result = output.str();
    string expect = "ARVN Fort: ARVN[LF=0,EXP=500,unitList=UnitList[count_vehicle=0;count_infantry=1;Infantry[infantryType=SNIPER,quantity=108,weight=5,position=(1,1)]],battleField=]\n";

    delete infantry;
    delete army;
    
    return printResult(result, expect, name);
}
