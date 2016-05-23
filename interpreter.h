#ifndef INTERPRETER_H
#define INTERPRETER_H


class Interpreter
{
    public:
        Interpreter();
        virtual ~Interpreter();
        void doCommand(char* com);
        float check(char* com);
    protected:
    private:
        float getFloat(char* com, int startPos);
        int getInt(char* com, int startPos);
        void M300(char* com);
        void G1(char* com);
        void G4(char* com);
        void G92(char* com);


};

#endif // INTERPRETER_H
