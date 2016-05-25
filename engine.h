#ifndef ENGINE_H
#define ENGINE_H

#include <hFramework.h>

class Engine
{
    const double m_radius{2}; //of pulley
    const double m_spc{720}; //steps per circle
    const double m_rps{3}; //radians per step

public:
    Engine();
    ~Engine();
    void setMotorId(int id);
    void setLength(float x);
    float getLength();
    void setLengthSteps(int x);
    int getLengthSteps();
    void resetEncoder();
    const double m_engine_const = m_radius * m_rps;
    void rotate(int steps);
    int mmToSteps(float x);
protected:
private:
    double m_spmm; // steps per milimeter
    int m_motorid;

};

#endif // ENGINE_H
