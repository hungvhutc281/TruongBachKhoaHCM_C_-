#ifndef _H_BATTLEFIELD_H_
#define _H_BATTLEFIELD_H_

#include "TerrainElement.h"
#include "Position.h"
#include <vector>
#include <string>
using namespace std;

//!-----------------------------------------------------
//! CLASS BattleField
//!-----------------------------------------------------
class BattleField {
private:
    int n_rows, n_cols;
    // 2D mảng chứa con trỏ đến các đối tượng TerrainElement
    TerrainElement ***terrain;
public:
    // Constructor nhận các vector vị trí của các yếu tố địa hình
    BattleField(int n_rows, int n_cols,
        vector<Position*> arrayForest,
        vector<Position*> arrayRiver,
        vector<Position*> arrayFortification,
        vector<Position*> arrayUrban,
        vector<Position*> arraySpecialZone);
    ~BattleField();
    
    // Trả về đối tượng TerrainElement tại vị trí (r,c)
    TerrainElement* getElement(int r, int c) const;
    
    // Hàm str để biểu diễn thông tin của BattleField
    string str() const;
};

#endif