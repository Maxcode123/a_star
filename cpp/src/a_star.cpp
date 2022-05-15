#include "a_star.h"
#include "heuristics.h"
#include "board.h"
#include "position.h"
#include <map>
#include <list>
#include <set>


void AStar::init_attrs(Position start, Position goal) {
    open_set.insert(start);
    g_score.insert(std::make_pair(start, 0));
    f_score.insert(std::make_pair(start, heuristic->get_distance(start, goal)));
}

std::list<Position> AStar::find_path(Position start, Position goal){
    init_attrs(start, goal);
    while (open_set.size() > 0) {
        Position current;
        find_min_f_pos(&current);

        if (current.equals(goal)) return reconstruct_path(goal);
        open_set.erase(current);
        closed_set.insert(current);

        Position* neighbours;
        neighbours = board->get_neighbours(current);
        int len = sizeof(neighbours) / sizeof(Position);
        for (int i = 0; i < len; i++) {
            if (closed_set.find(neighbours[i]) != closed_set.end()) continue;
            if (open_set.find(neighbours[i]) == closed_set.end()) open_set.insert(neighbours[i]);
            appoint_f_score(current, neighbours[i], goal);
        }
    }
    std::list<Position> empty_list;
    return empty_list;
}

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
    int tentative_g_score = g_score.at(current) + board->get_cost(neighbour);
    came_from.insert(std::make_pair(neighbour, current));
    g_score.insert(std::make_pair(neighbour, tentative_g_score));
    f_score.insert(std::make_pair(neighbour, tentative_g_score + heuristic->get_distance(neighbour, goal)));
}

std::list<Position> AStar::reconstruct_path(Position position) {
    std::list<Position> positions;
    positions.push_back(position);
    while (has_key(came_from, position)) {
        position = came_from.at(position);
        positions.push_back(position);
    }
    return positions;
}

bool AStar::has_key(std::map<Position, Position> m, Position position) {
    for (std::map<Position,Position>::iterator it = m.begin(); it != m.end(); it++) {
        if (position.equals(it->first)) return true;
    }
    return false;
}