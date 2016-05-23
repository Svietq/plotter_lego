#ifndef BOARD_H
#define BOARD_H

#include "head.h"
#include "engine.h"

#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

class Board
{
    const struct BoardDim{
        int x;
        int y;
    }dim={20,20};

    const double dist{10};//between pulleys' edges
    Head *_head;
    Engine *_engine1;
    Engine *_engine2;

    struct Line
    {
        double a;
        double b;
    }line{0,0};

    Line recalc_length(int ix, int iy);

public:
    Board();   
    void setPos(int x2, int y2);

};

#endif // BOARD_H
