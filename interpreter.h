#ifndef INTERPRETER_H
#define INTERPRETER_H
#include "board.h"
#include "servo.h"
#include "file.h"

class Interpreter
{
    private:
        Board m_board;
        Servo m_servo;
        float getFloat(char* com, int startPos);
        int getInt(char* com, int startPos);
        void M300(char* com);
        void G1(char* com);
        void G4(char* com);
        void G92(char* com);
        File m_file = File("test.gcode");
        void drawFromFile();
    public:
        Interpreter();
        virtual ~Interpreter();
        void doCommand(char* com);
        float check(char* com);

};

#endif // INTERPRETER_H
