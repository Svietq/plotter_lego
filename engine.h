#ifndef ENGINE_H
#define ENGINE_H

#include <hFramework.h>

class Engine
{
    const double m_radius{5}; //of pulley
    const double m_spc{720}; //steps per circle
    const double m_rps{3}; //radians per step

public:
    Engine();
    Engine(int id);
    virtual ~Engine();
    void setLength(float x);
    float getLength();
    void setLengthSteps(int x);
    int getLengthSteps();
    const double m_engine_const = m_radius * m_rps;
    void rotate(int steps);
protected:
private:
    double m_spmm; // steps per milimeter

};

#endif // ENGINE_H
