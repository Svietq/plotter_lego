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
        break;
    case 'G':
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
