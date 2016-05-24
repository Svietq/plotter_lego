#include <iostream>
#include "interpreter.h"
using namespace std;
Interpreter::Interpreter()
{
    //ctor
}

Interpreter::~Interpreter()
{
    //dtor
}

float Interpreter::check(char *com)
{
    return getInt(com, 1);
}
void Interpreter::doCommand(char *com)
{
    int length = 0;
    while(com[length] != '\0')
        length++;
    switch (com[0])
    {
    case 'M':
        switch (getInt(com, 1))
        {
        case 300:
            M300(com);
            break;
        default:
            break;
        }
        break;
    case 'G':
        switch (getInt(com, 1))
        {
        case 1:
            G1(com);
            break;
        case 4:
            G4(com);
            break;
        case 92:
            G92(com);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

float Interpreter::getFloat(char* com, int startPos)
{
    bool sign = 0;
    int pos = startPos;
    if (com[startPos] == '-')
    {
        sign = 1;
        pos++;
    }
    float result = 0;
    while (com[pos] != '.')
    {
        result *= 10;
        result += int(com[pos] - '0');
        pos++;
    }
    pos++;
    float dotted = 0;
    int divider = 10;
    while (com[pos] != ' ' && com[pos] != '\0')
    {
        dotted = float(com[pos] - '0');
        dotted /= divider;
        divider *= 10;
        result += dotted;
        pos++;
    }
    if(sign)
        result = -result;
    return result;
}

int Interpreter::getInt(char* com, int startPos)
{
    bool sign = 0;
    int pos = startPos;
    if (com[startPos] == '-')
    {
        sign = 1;
        pos++;
    }
    int result = 0;
    while (com[pos] != ' ' && com[pos] != '\0')
    {
        result *= 10;
        result += int(com[pos] - '0');
        pos++;
    }
    if(sign)
        result = -result;
    return result;
}

void Interpreter::G1(char* com)
{
    int pos = 0;
    float x, y, speed;
    while(com[pos] != 'X')
        pos++;
    pos++;
    x = getFloat(com, pos);
    while(com[pos] != 'Y')
        pos++;
    pos++;
    y = getFloat(com, pos);
    while(com[pos] != 'F')
        pos++;
    pos++;
    speed = getFloat(com, pos);
    m_board.setPos(x, y, speed);
}

void Interpreter::M300(char* com)
{
    int pen, pos = 0;
    while(com[pos] != 'S')
        pos++;
    pos++;
    pen = getInt(com, pos);
    switch (pen)
    {
    case 30:
        m_servo.setPen1();
        break;
    case 50:
        m_servo.setOff();
    default:
        break;
    }
}

void Interpreter::G92(char* com)
{
    m_board.home();
}
