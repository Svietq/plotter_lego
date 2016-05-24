#ifndef ENGINE_H
#define ENGINE_H

class Engine
{
    const double m_radius{5}; //of pulley
    const double m_spc{720}; //steps per circle

public:
    Engine();
    virtual ~Engine();
    void setLength(float x);
    float getLength();
protected:
private:
    double m_spmm; // steps per milimeter

};

#endif // ENGINE_H
