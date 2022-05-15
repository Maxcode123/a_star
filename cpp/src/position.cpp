#include <iostream>
#include <cmath>
#include "position.h"

Position Position::move(Position position, int dx, int dy) {
    int row = position.row + dx;
    int column = position.column + dy;
    Position pos = Position(row, column);
    return pos;
}

void Position::diff(Position position1, Position position2, int *dx, int *dy) {
    *dx = std::abs(position1.row - position2.row);
    *dy = std::abs(position1.column - position2.column);
}

bool Position::equals(Position position) {
    if (row == position.row && column == position.column) return true;
    return false;
}
