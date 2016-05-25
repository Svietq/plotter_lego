#ifndef BOARD_H
#define BOARD_H

#include "head.h"
#include "engine.h"


using namespace std;

class Board
{
    const struct BoardDim{
        int x;
        int y;
    }dim={20,20};

    const double dist{1000};//between pulleys' edges
    Head *_head;
    Engine _engine1;
    Engine _engine2;

    struct Line
    {
        double a;
        double b;
    }line{0,0};

    Line recalc_length(int ix, int iy);

public:
    Board();
    void setPos(float x2, float y2, float speed);
    void home();

};

#endif // BOARD_H
