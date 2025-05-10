#ifndef _H_LIBERATIONARMY_H_
#define _H_LIBERATIONARMY_H_

#include "Army.h"
class BattleField; // forward declare

class LiberationArmy : public Army
{
private:
    Unit **unitArray;       // For temporary
    // * Hint: Bạn có thể thêm hoặc thay thế các phương thức khác để truy cập các thành viên riêng tư nếu cần thiết.
    int size_V = 0;         // For temporary: vehicle count
    int size_I = 0;         // For temporary: infantry count
    int nearestFibonacci(int value);
    Unit* cloneUnit(Unit* unit);
    vector<Unit*> tohopA_list;
    vector<Unit*> tohopB_list;
    bool tohopA=false;
    bool tohopB=false;

public:
    LiberationArmy(Unit **unitArray, int size, string name, BattleField* battleField);
    void fight(Army *enemy, bool defense) override;
    string str() const override;

    // * Hint: Bạn có thể thêm hoặc thay thế các phương thức khác để truy cập các thành viên riêng tư nếu cần thiết.
    int getLF() {
        return this->LF;
    }
    int getEXP() {
        return this->EXP;
    }

    void checkRange(int& num, int MAX){
        num = std::max(0, std::min(num, MAX));
    }
};

#endif