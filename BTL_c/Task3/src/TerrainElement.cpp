#include "TerrainElement.h"
#include "LiberationArmy.h"


double calculateDistance(const Position& pos1, const Position& pos2) {
    int rowDiff = pos1.getRow() - pos2.getRow();
    int colDiff = pos1.getCol() - pos2.getCol();
    return (sqrt(double(rowDiff * rowDiff + colDiff * colDiff)));
}
//!-----------------------------------------------------
//! Lớp TerrainElement và các lớp dẫn xuất
//!-----------------------------------------------------

// Constructor và Destructor của TerrainElement
TerrainElement::TerrainElement(Position pos) : pos(pos)
{}

TerrainElement::~TerrainElement() {
    // Giải phóng tài nguyên nếu có
}

// Road: không có hiệu ứng
void Road::getEffect(Army *army) 
{
    // Không gây ảnh hưởng cho quân đội.
    if (!army) return;
}

// Mountain: stub – áp dụng hiệu ứng cho các đơn vị trong bán kính ảnh hưởng (theo đề bài, hiệu ứng có thể là:
// tăng EXP của bộ binh và giảm LF của phương tiện, tùy thuộc vào khoảng cách)
void Mountain::getEffect(Army *army) 
{
    if (!army) return;
    node cur = army->getUnitList()->getHead();
    bool isLiberation = dynamic_cast<LiberationArmy*>(army) != nullptr;
    while (cur) 
    {
        Unit* unit = cur->unit;
        double dist = calculateDistance(this->pos, unit->getCurrentPosition());
        // Liberation Army
        if (isLiberation) {
            // Bộ binh: EXP +30% mỗi attackScore nếu trong bán kính 2
            Infantry* inf = dynamic_cast<Infantry*>(unit);
            if (inf && dist <= 2.0) {
                int add = safeCeil(0.3 * inf->getAttackScoreInFight());
                // Tăng số lượng bộ binh tương ứng với attackScore tăng
                int newScore = inf->getAttackScoreInFight() + add;
                inf->setQuantity(inf->getQuantity()); // giữ nguyên quantity, chỉ để trigger updateScore
            }
            // Phương tiện: LF -10% mỗi attackScore nếu trong bán kính 2
            Vehicle* veh = dynamic_cast<Vehicle*>(unit);
            if (veh && dist <= 2.0) {
                int sub = safeCeil(0.1 * veh->getAttackScore());
                int newScore = veh->getAttackScore() - sub;
                veh->setQuantity(veh->getQuantity()); // giữ nguyên quantity, chỉ để trigger updateScore
            }
        } else { // ARVN
            // Bộ binh: EXP +20% mỗi attackScore nếu trong bán kính 1
            Infantry* inf = dynamic_cast<Infantry*>(unit);
            if (inf && dist <= 1.0) 
            {
                int add = safeCeil(0.2 * inf->getAttackScoreInFight());
                int newScore = inf->getAttackScoreInFight() + add;
                inf->setQuantity(inf->getQuantity());
            }
            // Phương tiện: LF -5% mỗi attackScore nếu trong bán kính 1
            Vehicle* veh = dynamic_cast<Vehicle*>(unit);
            if (veh && dist <= 1.0) {
                int sub = safeCeil(0.05 * veh->getAttackScore());
                int newScore = veh->getAttackScore() - sub;
                veh->setQuantity(veh->getQuantity());
            }
        }
        cur = cur->next;
    }
}

// River: stub – giảm EXP của lực lượng bộ binh 10% nếu nằm trong bán kính 2 đơn vị
void River::getEffect(Army *army) 
{
    if (!army) return;
    node cur = army->getUnitList()->getHead();
    while (cur) {
        Infantry* inf = dynamic_cast<Infantry*>(cur->unit);
        if (inf) {
            double dist = calculateDistance(this->pos, inf->getCurrentPosition());
            if (dist <= 2.0) 
            {
                // Giảm attackScore bộ binh 10%
                int sub = safeCeil(0.1 * inf->getAttackScoreInFight());
                // Không thay đổi quantity, chỉ trigger updateScore
                inf->setQuantity(inf->getQuantity());
            }
        }
        cur = cur->next;
    }
}

// Urban: stub – hiệu ứng khu dân cư có thể thay đổi attackScore của bộ binh hoặc phương tiện tùy vào loại
void Urban::getEffect(Army *army) {
    if (!army) return;
    node cur = army->getUnitList()->getHead();
    bool isLiberation = dynamic_cast<LiberationArmy*>(army) != nullptr;
    while (cur) {
        Unit* unit = cur->unit;
        double dist = calculateDistance(this->pos, unit->getCurrentPosition());
        Infantry* inf = dynamic_cast<Infantry*>(unit);
        Vehicle* veh = dynamic_cast<Vehicle*>(unit);
        if (isLiberation) {
            // Bộ binh đặc biệt hoặc chủ lực trong bán kính 5: tăng attackScore
            if (inf && dist <= 5.0 && (inf->getType() == SPECIALFORCES || inf->getType() == REGULARINFANTRY)) {
                // Tăng attackScore: +2*attackScore/D (D = dist, làm tròn lên)
                int D = (dist);
                int add = safeCeil(2.0 * inf->getAttackScoreInFight() / D);
                inf->setQuantity(inf->getQuantity());
            }
            // Pháo binh trong bán kính 2: giảm 50% attackScore
            if (veh && dist <= 2 && veh->getType() == ARTILLERY) {
                int newScore = safeCeil(0.5 * veh->getAttackScore());
                veh->setQuantity(veh->getQuantity());
            }
        } else { // ARVN
            // Bộ binh chủ lực trong bán kính 3: tăng attackScore
            if (inf && dist <= 3 && inf->getType() == REGULARINFANTRY) 
            {
                // Không thay đổi quantity, chỉ trigger updateScore
                inf->setQuantity(inf->getQuantity());
            }
            // Phương tiện chiến đấu không bị ảnh hưởng
        }
        cur = cur->next;
    }
}

// Fortification: stub – hiệu ứng chiến hào, áp dụng cho cả hai quân đội với các thay đổi nhất định
void Fortification::getEffect(Army *army)
{
    if (!army) return;
    node cur = army->getUnitList()->getHead();
    bool isLiberation = dynamic_cast<LiberationArmy*>(army) != nullptr;
    while (cur) {
        Unit* unit = cur->unit;
        double dist = calculateDistance(this->pos, unit->getCurrentPosition());
        if (dist <= 2.0) {
            int sub = safeCeil(0.2 * unit->getAttackScore());
            // Không thay đổi quantity, chỉ trigger updateScore
            unit->setQuantity(unit->getQuantity());
        }
        cur = cur->next;
    }
}

// SpecialZone: stub – các đơn vị trong bán kính 1 đơn vị có attackScore = 0
void SpecialZone::getEffect(Army *army) 
{
    if (!army) return;
    node cur = army->getUnitList()->getHead();
    while (cur) {
        Unit* unit = cur->unit;
        double dist = calculateDistance(this->pos, unit->getCurrentPosition());
        if (dist <= 1.0)
        {
            // Không thay đổi quantity, chỉ trigger updateScore
           // unit->setQuantity(unit->getQuantity());
           unit->setAttackScore(0);
        }
        cur = cur->next;
    }
}
