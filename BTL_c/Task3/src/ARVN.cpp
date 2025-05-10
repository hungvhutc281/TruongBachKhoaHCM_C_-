#include "ARVN.h"

// TODO: Implement
ARVN::ARVN(Unit** unitArray, int size, string name, BattleField* battleField)
        : Army(unitArray, size, name, battleField) {
}

void ARVN::fight(Army* enemy, bool defense) 
{
        if (!defense)
        {
            vector<Unit*> danhsachXoa;
            node cur = unitList->getHead();
            while (cur != nullptr)
            {
                node nodenext = cur->next;
                int soluongGoc = cur->unit->getQuantity();
                int capnhatquantity = static_cast<int>(safeCeil(soluongGoc * 0.8));
                cur->unit->setQuantity(capnhatquantity);
        
                if (capnhatquantity <= 1)
                {
                    danhsachXoa.push_back(cur->unit);
                }
                cur = nodenext;
            }
            if (!danhsachXoa.empty())
            {
                unitList->remove(danhsachXoa);
            }
            updateScore();
        } else
        {
                node cur = unitList->getHead();  
                while (cur != nullptr) 
                {
                    int baseWeight = cur->unit->getWeight();
                    int newWeight = static_cast<int>(safeCeil(baseWeight * 0.8)); 
                    cur->unit->setWeight(newWeight);
                    cur = cur->next;  
                }
                updateScore();
        }
}

string ARVN::str() const {
   stringstream ketqua;
    ketqua << "ARVN[LF=" << LF << ",EXP=" << EXP << ",unitList=" << unitList->str() << ",battleField=]";
    return ketqua.str();
}
