#ifndef ENGINE_H
#define ENGINE_H

class Engine
{
    const double radius{5}; //of pulley
    const double rps{3}; //radians per step

public:
    Engine();
    void rotate(int steps);
    double engine_const();

};

#endif // ENGINE_H
