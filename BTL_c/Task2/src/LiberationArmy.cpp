#include "LiberationArmy.h"

// TODO: Implement
// class LiberationArmy

LiberationArmy::LiberationArmy(Unit **unitArray, int size, string name): Army(unitArray,size,name) 
{                                                       
    // TODO: Implement
}
vector<Unit*> cur;
vector<Unit*> tohop;
bool tohopA=false;
bool tohopB=false;
int nho_nhat=INT_MAX;
vector<Unit*> tohopA_list;
vector<Unit*> tohopB_list;
void backtrack(vector<Unit*>m,int chi_so,int muc_tieu) 
{
    int tong = 0;
    for (int i = 0; i < cur.size(); ++i)
     {
        if (Infantry* d=dynamic_cast<Infantry*>(cur[i]))
        tong +=d->getAttackScoreInFight();
        else tong+=cur[i]->getAttackScore();
    }
    if (tong>muc_tieu && tong<nho_nhat)
     {
        nho_nhat=tong;
        tohop=cur;
    }
    for (int i = chi_so; i < m.size(); i++) 
    {
        cur.push_back(m[i]);
        backtrack(m,i + 1,muc_tieu);
        cur.pop_back();
    }
}
void LiberationArmy::fight(Army *enemy, bool defense)
{ 
    // TODO: Implement

    vector<Unit*> x = unitList->layvector();
    vector<Unit*> tohopI,tohopV;
    for(Unit* s: x)
    {
        if(dynamic_cast<Vehicle*>(s)) tohopV.push_back(s);
        else tohopI.push_back(s); 
    }   
    //Infantry
    backtrack(tohopI,0,enemy->getEXP());
    if(!tohop.empty()) 
    {
        tohopA_list = tohop; 
        tohopA = true;
    }
    //Vehicle
    nho_nhat = INT_MAX;
    cur.clear();
    tohop.clear();
    backtrack(tohopV,0,enemy->getLF());
    if(!tohop.empty()) 
    {
        tohopB_list = tohop;
        tohopB=true;
    }
    nho_nhat = INT_MAX;
    cur.clear();
    tohop.clear();

if (!defense)
{
    LF=safeCeil(LF*1.5);
    EXP=safeCeil(EXP*1.5);
if (tohopA && tohopB)
{
unitList->remove(tohopA_list);
unitList->remove(tohopB_list);
vector<Unit*> y;
    vector<Unit*> x = enemy->getUnitList()->layvector();
    for(int i = x.size()-1;i>=0;i--)
    {
        unitList->insert(x[i]);
        y.push_back(x[i]);
    }
    enemy->getUnitList()->remove(y);
    enemy->updateScore();
    updateScore();
}
//Tim duoc mot trong hai to hop thoa man: 
else if (tohopA && !tohopB)
{
    if (LF>enemy->getLF())
    {
    unitList->remove(tohopA_list); 
    unitList->remove1();
    //Trung dung 
    vector<Unit*> y;
    vector<Unit*> x = enemy->getUnitList()->layvector();
    for(int i = x.size()-1;i>=0;i--)
    {
        unitList->insert(x[i]);
        y.push_back(x[i]);
    }
    enemy->getUnitList()->remove(y);
    enemy->updateScore();
    updateScore();
    }
}  else if (!tohopA && tohopB)
{
    if (EXP>enemy->getEXP())
    {
        unitList->remove(tohopB_list);
        unitList->remove2();
        vector<Unit*> y;
    vector<Unit*> x = enemy->getUnitList()->layvector();
    for(int i = x.size()-1;i>=0;i--)
    {
        unitList->insert(x[i]);
        y.push_back(x[i]);
    }
    enemy->getUnitList()->remove(y);
    enemy->updateScore();
    updateScore();
    }
}
else 
{
node cur=unitList->getHead();
while (cur != nullptr)
{
    Unit* unit=cur->unit;
    int curweight=unit->getWeight();
    unit->setWeight(safeCeil( curweight* 0.9));
    cur=cur->next;
}
updateScore();
}
}
else
{
 LF=max(0,min(safeCeil(LF*1.3),1000));
 EXP=max(0,min(safeCeil(EXP*1.3),500));
 bool kiemtraLF=(LF>=enemy->getLF());
 bool kiemtraEXP=(EXP>=enemy->getEXP());
 while (!kiemtraLF && !kiemtraEXP)
 {
  node cur=unitList->getHead();
  while (cur != nullptr)
  {
    cur->unit->setQuantity(nearestFibonacci(cur->unit->getQuantity()));
    cur=cur->next;
  }
  updateScore();
  kiemtraLF=(LF>=enemy->getLF());
  kiemtraEXP=(EXP>=enemy->getEXP());
 }
if (kiemtraEXP==true && kiemtraLF==true) return;
   else
  {
    node cur=unitList->getHead();
   while (cur !=nullptr)
   {
       cur->unit->setQuantity(safeCeil(cur->unit->getQuantity()*0.9));
       cur=cur->next;
   }
   updateScore();
   }
}
}

string LiberationArmy::str() const 
{
    // TODO: Implementt
    ostringstream ketqua;
    ketqua<<"LiberationArmy["<<"LF="<<LF<<",EXP="<<EXP<<",unitList="<<unitList->str()<<"]";
    return ketqua.str();
}


// Sup function
int LiberationArmy::nearestFibonacci(int value) 
{
    // TODO: Implement
    if (value<=0) return 0;
    int a=0;
    int b=1;
   while (b<value)
   {
    int tmp=b;
    b=a+b;
    a=tmp;
   }
   if (abs(b-value)<abs(a-value))
   return b;
   return a;
}
