#include "heuristics.h"
#include <map>

class AStar
{
public:
    AStar(Board b, Chebysev h)
    {
        board = b;
        heuristic = h;
    }
    AStar()
    {
        board = Board();
        heuristic = Chebysev();
    }
    list<Position> find_path(Position start, Position goal);
private:
    Board board;
    Chebysev heuristic;
    set<Position> open_set;
    set<Position> closed_set;
    map<Position, Position> came_from;
    map<Position, int> g_score;
    map<Position, int> f_score;
    void init_attrs(Position start, Position goal);
    void find_min_f_pos(Position* ptr);
    void appoint_f_score(Position current, Position neighbour, Position goal);
    list<Position> reconstruct_path(Position position);
    bool has_key(map<Position, Position> m, Position position);
};

void AStar::init_attrs(Position start, Position goal) {
    open_set.insert(start);
    g_score.insert(std::make_pair(start, 0));
    f_score.insert(std::make_pair(start, heuristic.get_distance(start, goal)));
}

list<Position> find_path(Position start, Position goal){}

void AStar::find_min_f_pos(Position* ptr) {
    Position min_f_pos = *(open_set.begin());
    int min_f_score = f_score.at(min_f_pos);
    for (Position pos : open_set) {
        if (f_score.at(pos) < min_f_score) {
            min_f_score = f_score.at(pos);
            min_f_pos = pos;
        }
    }
    ptr = &min_f_pos;
}

void AStar::appoint_f_score(Position current, Position neighbour, Position goal) {
    int tentative_g_score = g_score.at(current) + board.get_cost(neighbour);
    came_from.insert(std::make_pair(neighbour, current));
    g_score.insert(std::make_pair(neighbour, tentative_g_score));
    f_score.insert(std::make_pair(neighbour, tentative_g_score + heuristic.get_distance(neighbour, goal)));
}

list<Position> AStar::reconstruct_path(Position position) {
    list<Position> positions;
    positions.push_back(position);
    while (has_key(came_from, position)) {
        position = came_from.at(position);
        positions.push_back(position);
    }
    return positions;
}

bool AStar::has_key(map<Position, Position> m, Position position) {
    for (std::map<Position,Position>::iterator it = m.begin(); it != m.end(); it++) {
        if (position.equals(it->first)) return true;
    }
    return false;
}
