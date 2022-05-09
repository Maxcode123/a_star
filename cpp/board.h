#include "position.h"
#include <set>
#include <list>

class Board 
{
public:
    Board() // Constructor
    {
        int r[] = {0, 7};
        row_boundaries = r;
        int c[] = {0, 7};
        column_boundaries = c;
        create_barriers(barriers);
        set_start();
        set_end();
    }
    Position get_start();
    Position get_end();
    void set_row_boundaries(int *boundaries);
    void set_column_boundaries(int *boundaries);
    void set_barriers(Position *b);
    Position* get_neighbours(Position position);
    int get_cost(Position position);
private:
    int* row_boundaries;
    int* column_boundaries;
    Position* barriers;
    int barriers_len;
    Position start;
    Position end;
    void create_barriers(Position* b);
    void set_start();
    void set_end();
    Position* available_moves(Position position, int distance);
    bool valid_position(Position position);
    bool valid_row(int row);
    bool valid_column(int column);
};

void Board::set_row_boundaries(int *boundaries) {
    row_boundaries = boundaries;
}

void Board::set_column_boundaries(int *boundaries) {
    column_boundaries = boundaries;
}

void Board::set_barriers(Position *b) {
    barriers_len = sizeof(b) / sizeof(Position);
    barriers = b;
}

void Board::create_barriers(Position* b) {
    int rows[] = {2, 2, 2, 3, 4, 5, 5, 5, 5, 5, 4, 3};
    int columns[] = {4, 5, 6, 6, 6, 6, 5, 4, 3, 2, 2, 2};
    barriers_len = 12;
    for (int i = 0; i < 12; i++) {
        b[i] = Position(rows[i], columns[i]);
    }
}

void Board::set_start() {
    Position start = Position(0, 0);
}

void Board::set_end() {
    Position end = Position(row_boundaries[1], column_boundaries[1]);
}

Position Board::get_start() {
    return start;
}

Position Board::get_end() {
    return end;
}

Position* Board::get_neighbours(Position position) {
    Position* neighbours;
    neighbours = available_moves(position, 1);
    return neighbours;
}

int Board::get_cost(Position position) {
    for (int i = 0; i < barriers_len; i ++) {
        if (position.equals(barriers[i])) return 100;
    }
    return 1;
}

Position* Board::available_moves(Position position, int distance) {
    int steps[] = {-distance, 0, distance};
    set<int*> s;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (steps[i] == 0 && steps[j] == 0) continue;
            int d[] = {steps[i], steps[j]};
            s.insert(d);
        }
    }
    list<Position> available;
    for (int* d: s) {
        Position pos = Position::move(position, d[0], d[1]);
        if (valid_position(pos)) available.push_back(pos);
    }
    Position* array = (Position*)malloc(sizeof(Position) * available.size());
    int i = 0;
    list<Position>::iterator it;
    for (it = available.begin(); it != available.end(); i++) {
        array[i] = *it;
        it++;
    }
    return array;
}

bool Board::valid_position(Position position) {
    if (valid_row(position.row) && valid_column(position.column)) return true;
    return false;
}

bool Board::valid_row(int r) {
    if (r >= row_boundaries[0] && r <= row_boundaries[1]) return true;
    return false;
}

bool Board::valid_column(int c) {
    if (c >= column_boundaries[0] && c <= column_boundaries[1]) return true;
    return false;
}