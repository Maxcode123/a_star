#pragma once
#include "heuristics.h"
#include "board.h"
#include "position.h"
#include <map>
#include <list>
#include <set>

class AStar
{
public:
    AStar(Board *b, Chebysev *h)
    {
        board = b;
        heuristic = h;
    }
    std::list<Position> find_path(Position start, Position goal);
private:
    Board* board;
    Chebysev* heuristic;
    std::set<Position> open_set;
    std::set<Position> closed_set;
    std::map<Position, Position> came_from;
    std::map<Position, int> g_score;
    std::map<Position, int> f_score;
    void init_attrs(Position start, Position goal);
    void find_min_f_pos(Position* ptr);
    void appoint_f_score(Position current, Position neighbour, Position goal);
    std::list<Position> reconstruct_path(Position position);
    bool has_key(std::map<Position, Position> m, Position position);
};

