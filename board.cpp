#include "board.h"

Board::Line Board::recalc_length(int ix, int iy)
{
    line.a = sqrt(pow(boardOffset.x + ix,2) + pow(boardOffset.y + dim.y - iy,2));
    line.b = sqrt(pow(dist - boardOffset.x - ix - headWidth,2) + pow(boardOffset.y + dim.y - iy,2));
    return line;
}

Board::Board()
{
    _engine1.setMotorId(1);
    _engine2.setMotorId(2);
    boardOffset.x = (dist - dim.x) / 2;
    boardOffset.y = 100;
}

void Board::setPos(float x2, float y2, float speed)
{
    Line line1;// = recalc_length(x2, y2);
    Pos delta, stairdelta;
    delta.x = x2 - pos.x; // Liczymy delte calkowitego ruchu w x i y
    delta.y = y2 - pos.x;
    float moveLength = sqrt(pow(delta.x,2) + pow(delta.y,2)); // Liczymy calkowita dlugosc ruchu
    int stairs = moveLength / resolution; // Liczymy ilosc stopni na jakie zostanie podzielony ruch
    stairdelta.x = delta.x / stairs;  // Luczymy delte pojedynczego stopnia
    stairdelta.y = delta.y / stairs;
    float time = (60000 / speed) * resolution; // Liczymy czas wykonania jednego stopnia
    for(int i = 0; i < stairs; i++) // Wykoonujemy wszystkie stopnie
    {
        pos.x += stairdelta.x; // Dodajemy delte stopnia do pozycji
        pos.y += stairdelta.y;
        line1 = recalc_length(pos.x, pos.y); // Przeliczamy dlugosci linek i przesylamy do silnikow
        _engine1.setLength(line1.a);
        _engine2.setLength(line1.b);
        sys.delay(time); // Czekamy na wykonanie ruchu
    }
}


/** @brief Ustalenie pozycji poczatkowej
  * dojezdza do lewego silnika, resetuje enkoder
  * dojezdza do prawego silnika, resetuje enkoder
  * dojezdza do pozycji poczatkowej
  */
void Board::home()
{
    _engine2.resetEncoder();
    _engine2.setLength(dist, 500);
    while(hSens1)
    {
        _engine1.rotate(-10, 500);
        sys.delay(10);
    }
    _engine1.resetEncoder();
    _engine1.setLength(dist - headWidth, 500);
    while(hSens2)
    {
        _engine2.rotate(-10, 500);
        sys.delay(10);
    }
    _engine2.resetEncoder();
    setPos(0,0,1000);
}

