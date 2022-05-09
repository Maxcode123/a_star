#include <iostream>
#include <cmath>
using namespace std;

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

Position Position::move(Position position, int dx, int dy) {
    int row = position.row + dx;
    int column = position.column + dy;
    Position pos = Position(row, column);
    return pos;
}

void Position::diff(Position position1, Position position2, int *dx, int *dy) {
    *dx = abs(position1.row - position2.row);
    *dy = abs(position1.column - position2.column);
}

bool Position::equals(Position position) {
    if (row == position.row && column == position.column) return true;
    return false;
}

std::ostream& operator<<(std::ostream &s, const Position &position) {
    return s << "(" << position.row << ", " << position.column << ")";
}