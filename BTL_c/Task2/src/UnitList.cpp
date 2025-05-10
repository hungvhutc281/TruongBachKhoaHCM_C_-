#include "UnitList.h"
    node makeNode(Unit* unit)
    {
    node tmp = new Node;
    tmp->unit = unit;
    tmp->next = nullptr;
    return tmp;
    }
    node UnitList::getHead() const
    {
        return head;
    }
    
    void insertLast(node &a,Unit* unit)
    {
        node tmp=makeNode(unit);
        if (a==nullptr)
        {
            a=tmp;
        } else {
            node p=a;
            while (p->next != nullptr)
            {
                p=p->next;
            }
            p->next=tmp;
        }
    }
void insertFirst(node &a,Unit*unit )
{
    node tmp=makeNode(unit);
    if (a==nullptr)
    {
        a=tmp;
    } else 
    {
    tmp->next=a;
    a=tmp;
    }
}
bool sodacbiet(int n,int k)
{
    if (n<=0) return false;
    vector<int> v;
    int power=1;
        while (power<=n)
        { 
           v.push_back(power);
            power=power*k;
        }
vector<bool> dp(n+1,false);
dp[0]=true;
for (int i=0;i<v.size();i++)
{
    for (int j=n;j>=v[i];j--)
    {
        if (dp[j-v[i]]==true)
        {
            dp[j]=true;
        }
    }
}
return dp[n];
}


UnitList::UnitList(int S) : countInfantry(0), countVehicle(0),head(nullptr)
{
    // TODO: Implement
    vector<int> base;

    for (int k = 2; k <= S; k++) {
        if (sodacbiet(S, k)) {
            base.push_back(k);
        }
    }

    bool coSoLeNhoHon10 = false;
    for (int k : base) {
        if ((k % 2 != 0) && k < 10) {
            coSoLeNhoHon10 = true;
            break;
        }
    }

    capacity = coSoLeNhoHon10 ? 12 : 8;
}
 

bool UnitList::insert(Unit *unit)
{
    // TODO: Implement
    int tong=countInfantry+countVehicle;
    if (tong>capacity) return false;
    else if (tong <= capacity)
    {
        if (unit != nullptr)
        {
            if (dynamic_cast<Vehicle*>(unit) != nullptr)
            {
                Vehicle* unitvehicle = dynamic_cast<Vehicle*>(unit);
                node cur = head;
                while (cur != nullptr)
                {
                    if (Vehicle* UnitListVehicle = dynamic_cast<Vehicle*>(cur->unit))
                    {
                        if (unitvehicle->getType() == UnitListVehicle->getType())
                        {
                            UnitListVehicle->setQuantity(unitvehicle->getQuantity() + UnitListVehicle->getQuantity());
                            if (unitvehicle->getWeight() > UnitListVehicle->getWeight())
                            {
                                UnitListVehicle->setWeight(unitvehicle->getWeight());
                            }
                            return false;
                        }
                    }
                    cur = cur->next;
                }
                insertLast(head, unit);
                countVehicle++;
                return true;
            }
            else if (dynamic_cast<Infantry*>(unit) != nullptr)
            {
                Infantry* unitinfantry = dynamic_cast<Infantry*>(unit);
                node cur = head;
                while (cur != nullptr)
                {
                    if (Infantry* UnitListinfantry = dynamic_cast<Infantry*>(cur->unit))
                    {
                        if (unitinfantry->getType() == UnitListinfantry->getType())
                        {
                            UnitListinfantry->setQuantity(UnitListinfantry->getQuantity() + unitinfantry->getQuantity());
                            if (unitinfantry->getWeight() > UnitListinfantry->getWeight())
                            {
                                UnitListinfantry->setWeight(unitinfantry->getWeight());
                            }
                            return false;
                        }
                    }
                    cur = cur->next;
                }
                insertFirst(head, unit);
                countInfantry++;
                return true;
            }
        }
    }
    return false;
}

bool UnitList::isContain(VehicleType vehicleType)
{
    // TODO: Implement 
    node cur=head;
    while (cur != nullptr) 
    {
        Vehicle* vehicle=dynamic_cast<Vehicle*>(cur->unit);
        if ( vehicle != nullptr && vehicle->getType()==vehicleType)
        {
            return true;  
        }  
        cur=cur->next;
    }
    return false;  
}

bool UnitList::isContain(InfantryType infantryType)
{
    // TODO: Implement
    node cur=head;
    while (cur != nullptr) 
    {
       Infantry* infantry=dynamic_cast<Infantry*>(cur->unit);
       if (infantry != nullptr && infantry->getType()==infantryType)
       {
        return true;
       }
        cur= cur->next;
    }
    return false;   
}

string UnitList::str() const
    {
        ostringstream ketqua;
        ketqua << "UnitList[count_vehicle=" << countVehicle
               << ";count_infantry=" << countInfantry;
    
        if (head != nullptr) {
            ketqua << ";"; // Chỉ in dấu ; nếu có unit
            node cur = head;
            bool danhdau = true;
            while (cur != nullptr) {
                if (!danhdau) {
                    ketqua << ",";
                }
                ketqua << cur->unit->str();
                danhdau = false;
                cur = cur->next;
            }
        }
    
        ketqua << "]";
        return ketqua.str();
    }
 
void UnitList::remove(const vector<Unit*>& units) 
{
    for (Unit* unit : units) 
    {
        node current = head;
        node previous = nullptr;
        while (current != nullptr) 
        {
            if (current->unit == unit) 
            {
                // Giảm biến đếm đúng loại
                if (dynamic_cast<Infantry*>(unit))
                    countInfantry--;
                else if (dynamic_cast<Vehicle*>(unit))
                    countVehicle--;
                // Xóa node
                if (previous == nullptr) 
                    head = current->next;
                else 
                previous->next = current->next;
                 delete current;
                 break;
            }
            previous = current;
            current = current->next;
        }
    }
}
vector<Unit*> UnitList::layvector()
{
node cur=head;
vector<Unit*> xamxi ;
while (cur!=nullptr) 
{
    xamxi.push_back(cur->unit);
    cur=cur->next;
}
return xamxi;
}
void UnitList::remove1() 
{
    {
        node cur = head;
        node prev = nullptr;
        while (cur != nullptr && dynamic_cast<Infantry*>(cur->unit))
         {
            prev = cur;
            cur = cur->next;
        }
        if (cur == nullptr) return;
        while (cur != nullptr)
         {
            node temp = cur;
            cur = cur->next;
            countVehicle--;
            delete temp;
        }

        if (prev != nullptr) {
            prev->next = nullptr;  
        } else {
            head = nullptr; 
        }
    }
    }

    void UnitList::remove2() 
    {
        node cur = head;
        while (cur != nullptr && dynamic_cast<Infantry*>(cur->unit)) 
        {
            node temp = cur;
            cur = cur->next;
            countInfantry--;
            delete temp;
        }
        head = cur;
    }