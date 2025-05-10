#include "ARVN.h"

// TODO: Implement
ARVN::ARVN(Unit** unitArray, int size, string name): Army(unitArray, size, name) {
        // TODO: Implement

}
void ARVN::fight(Army* enemy, bool defense) 
{
    // TODO: Implement
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

string ARVN::str() const 
{
    // TODO: Implement
    stringstream ketqua;
    ketqua<<"ARVN["<<"LF="<<LF<<",EXP="<<EXP<<",unitList="<<unitList->str()<<"]";
    return ketqua.str();
}

//void ARVN::updateScores() 
//{
    // TODO: Implement
//}