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


};

#endif // INTERPRETER_H
