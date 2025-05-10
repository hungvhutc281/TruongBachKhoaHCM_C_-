#include "Position.h"

//!----------------------------------------------
//! Lớp Position
//!----------------------------------------------
Position::Position(int r, int c) : r(r), c(c) {}
Position::Position(const string &str_pos) {
    // TODO: Implement
    char ch;
    stringstream ss(str_pos);
    ss >> ch >> r >> ch >> c >> ch; 
}
int Position::getRow() const { return r; }
int Position::getCol() const { return c; }
void Position::setRow(int r) { this->r = r; }
void Position::setCol(int c) { this->c = c; }
string Position::str() const {
    // TODO: Implement
    string chuoicantrave;
    chuoicantrave='('+to_string(r)+','+to_string(c)+')';
    return chuoicantrave;
}