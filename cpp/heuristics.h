#include "board.h"

class Chebysev 
{
public:
    static int get_distance(Position start, Position goal);
};

int Chebysev::get_distance(Position start, Position goal) {
    int D = 1;
    int D2 = 1;
    int dx, dy;
    Position::diff(start, goal, &dx, &dy);
    int distance = D * (dx + dy) + (D2 - 2 * D) * std::min(dx, dy);
    return distance;
}