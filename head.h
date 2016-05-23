#ifndef HEAD_H
#define HEAD_H

#include "engine.h"

#include <math.h>
#include <algorithm>
using namespace std;

class Head
{
    private:
        struct Pos
        {
            int x;
            int y;
        }pos{5,19};

        enum class pen_status{Red, Blue, None};
        const float max_speed = 4;
        Engine *_engine;

    public:
        Head();
        Pos get_pos();
        void set_pos(int ix, int iy);
        void pen_off();
        void pen_red();
        void pen_blue();
};

#endif // HEAD_H
