#pragma once
#include <cmath>

class Position {
public:
    int row;
    int column;
    static Position move(Position position, int dx, int dy);
    static void diff(Position position1, Position position2, int *dx, int *dy);
    bool equals(Position position);
    Position(int r, int c) // Constructor
    {
        row = r;
        column = c;
    }
    Position() :row{0}, column{0} {}
    bool operator>(const Position& obj) const
    {
        double d1 = sqrt(row^2 + column^2);
        double d2 = sqrt(obj.row^2 + obj.column^2);
        bool res = d1 > d2;
        return res;
    }
    bool operator<(const Position& obj) const
    {
        double d1 = sqrt(row^2 + column^2);
        double d2 = sqrt(obj.row^2 + obj.column^2);
        bool res = d1 < d2;
        return res;
    }
};