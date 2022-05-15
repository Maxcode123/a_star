#include "obj_iostream.h"
#include <iostream>

std::ostream& operator<<(std::ostream &s, const Position &position) {
    return s << "(" << position.row << ", " << position.column << ")";
}