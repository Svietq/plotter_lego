#ifndef BOARD_H
#define BOARD_H

#include "head.h"
#include "engine.h"


using namespace std;

class Board
{
    struct BoardDim{
        int x;
        int y;
    }dim={600,900}; // wymiary tablicy
    const double resolution{0.1}; // dokladnosc
    double dist{1000};//between pulleys' edges
    const double headWidth{50}; // szerokosc glowicy
    BoardDim boardOffset; // odsuniecie pola roboczego od bokow
    Head *_head;
    Engine _engine1;
    Engine _engine2;

    struct Line
    {
        double a;
        double b;
    }line{0,0};

    Line recalc_length(int ix, int iy);
    struct Pos
    {
        float x;
        float y;
    }pos{0,0};
public:
    Board();
    void setPos(float x2, float y2, float speed);
    void home();

};

#endif // BOARD_H
