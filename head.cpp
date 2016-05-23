#include "head.h"

Head::Head()
{

}

Head::Pos Head::get_pos()
{
    return pos;
}

void Head::set_pos(int ix, int iy)
{
    pos.x = ix;
    pos.y = iy;
}
