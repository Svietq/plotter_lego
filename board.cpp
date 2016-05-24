#include "board.h"

Board::Line Board::recalc_length(int ix, int iy)
{
    line.a = sqrt(pow(ix,2) + pow(iy,2));
    line.b = sqrt(dist*(dist-2*ix)+iy*iy+ix*ix);
    return line;
}

Board::Board()
{

}

void Board::setPos(int x2, int y2)
{
    Line line1 = recalc_length(_head->get_pos().x, _head->get_pos().y);/////////////

    int x1 = _head->get_pos().x;
    int y1 = _head->get_pos().y;
    _head->set_pos(x2,y2);

    const bool steep = (fabs(y2 - y1) > fabs(x2 - x1));
    if(steep)
    {
        std::swap(x1, y1);
        std::swap(x2, y2);
    }

    if(x1 > x2)
    {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }

    const float dx = x2 - x1;
    const float dy = fabs(y2 - y1);

    float error = dx / 2.0f;
    const int ystep = (y1 < y2) ? 1 : -1;
    int y = (int)y1;

    const int maxX = (int)x2;

    for(int x=(int)x1; x<maxX; x++)
    {
        Line line2 = recalc_length(x, y);                       ///////
        int n1 = (line2.a-line1.a)/_engine1->m_engine_const;    //////
        int n2 = (line2.b-line1.b)/_engine2->m_engine_const;    /////
        if(steep)
        {
            _engine1->rotate(n1);                               /////
            _engine2->rotate(n2);                               /////
//          board._board[x][y]=1;/////////////////////////////////////////
        }
        else
        {
            _engine1->rotate(-n1);                              /////
            _engine2->rotate(-n2);                              /////
//          board._board[y][x]=1;/////////////////////////////////////////
        }

        error -= dy;
        if(error < 0)
        {
            y += ystep;
            error += dx;
        }
    }
}
