#include "BattleField.h"

//!-----------------------------------------------------
// CLASS BattleField
//!-----------------------------------------------------
BattleField::BattleField(int n_rows, int n_cols,
    vector<Position*> arrayForest,
    vector<Position*> arrayRiver,
    vector<Position*> arrayFortification,
    vector<Position*> arrayUrban,
    vector<Position*> arraySpecialZone)
    : n_rows(n_rows), n_cols(n_cols)
{
    // Cấp phát mảng 2 chiều
    terrain = new TerrainElement**[n_rows];
    for (int i = 0; i < n_rows; ++i) {
        terrain[i] = new TerrainElement*[n_cols];
        for (int j = 0; j < n_cols; ++j) {
            terrain[i][j] = nullptr;
        }
    }

    // Mountain
    for (auto posPtr : arrayForest) {
        int x = posPtr->getRow();
        int y = posPtr->getCol();
        if (x >= 0 && x < n_rows && y >= 0 && y < n_cols) {
            delete terrain[x][y];
            terrain[x][y] = new Mountain(*posPtr);
        }
    }

    // River
    for (auto posPtr : arrayRiver) {
        int x = posPtr->getRow();
        int y = posPtr->getCol();
        if (x >= 0 && x < n_rows && y >= 0 && y < n_cols) {
            delete terrain[x][y];
            terrain[x][y] = new River(*posPtr);
        }
    }
    // Fortification
    for (auto posPtr : arrayFortification) {
        int x = posPtr->getRow();
        int y = posPtr->getCol();
        if (x >= 0 && x < n_rows && y >= 0 && y < n_cols) {
            delete terrain[x][y];
            terrain[x][y] = new Fortification(*posPtr);
        }
    }
    // Urban
    for (auto posPtr : arrayUrban) {
        int x = posPtr->getRow();
        int y = posPtr->getCol();
        if (x >= 0 && x < n_rows && y >= 0 && y < n_cols) {
            delete terrain[x][y];
            terrain[x][y] = new Urban(*posPtr);
        }
    }
    // SpecialZone
    for (auto posPtr : arraySpecialZone) {
        int x = posPtr->getRow();
        int y = posPtr->getCol();
        if (x >= 0 && x < n_rows && y >= 0 && y < n_cols) {
            delete terrain[x][y];
            terrain[x][y] = new SpecialZone(*posPtr);
        }
    }
    // Các vị trí còn lại là Road
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            if (terrain[i][j] == nullptr) {
                terrain[i][j] = new Road(Position(i, j));
            }
        }
    }
}

BattleField::~BattleField() {
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            delete terrain[i][j];
        }
        delete[] terrain[i];
    }
    delete[] terrain;
}

TerrainElement* BattleField::getElement(int r, int c) const {
    if (r >= 0 && r < n_rows && c >= 0 && c < n_cols) {
        return terrain[r][c];
    }
    return nullptr;
}

string BattleField::str() const {
    return "BattleField[n_rows=" + to_string(n_rows) + ",n_cols=" + to_string(n_cols) + "]";
}