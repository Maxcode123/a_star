#pragma once
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

