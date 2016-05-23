#include "board.h"
#include "head.h"
#include "interpreter.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    Interpreter in;
    in.print_coords();
    return 0;
}
