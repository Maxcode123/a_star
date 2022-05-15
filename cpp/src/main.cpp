#include "a_star.h"
#include "heuristics.h"
#include "board.h"
#include "position.h"
#include "obj_iostream.h"

int main() {
    Board board = Board();
    Chebysev heuristic = Chebysev();
    Position pos = Position(1, 1);
    std::cout << pos;
    return 1;
}
