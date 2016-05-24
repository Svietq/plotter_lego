#ifndef ENGINE_H
#define ENGINE_H

class Engine
{
    const double radius{5}; //of pulley
    const double spc{3}; //steps per circle

public:
    Engine();
    virtual ~Engine();
    void setLength(float x);
    float getLength();
protected:
private:

};

#endif // ENGINE_H
