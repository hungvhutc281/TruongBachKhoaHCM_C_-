#include "Position.h"
Position::Position(int r, int c) :r(r),c(c)
{
    // TODO: implement
   
}

Position::Position(const string &str_pos)
{
    // TODO: implement
    char ch;
    stringstream ss(str_pos);
    ss >> ch >> r >> ch >> c >> ch; 
}
int Position::getRow() const { return r; }
int Position::getCol() const { return c; }

void Position::setRow(int r)
{ // TODO: implement
    this->r=r;
}

void Position::setCol(int c)
{
    // TODO: implement
    this->c=c;
}
string Position::str() const
{
    // TODO: implement
    string chuoicantrave;
    chuoicantrave='('+to_string(r)+','+to_string(c)+')';
    return chuoicantrave;
}
