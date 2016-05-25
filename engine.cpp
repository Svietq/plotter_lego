#include "engine.h"

Engine::Engine(hMotor motor)
{
    m_motor = motor;
    m_spmm = m_spc / (m_radius * 3.1415);
}

void Engine::rotate(int steps)
{
    m_motor.rotRel(x);
}

void setLengthSteps(int x)
{
    m_motor.rotAbs(x);
}

int getLengthSteps();
{
    return m_motor.getEncoderCnt();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void Engine::resetEncoder()
{
    m_motor.resetEncoderCnt();
}

int Engine::mmToSteps(float x)
{
    return x * m_spmm;
}

void Engine::setLength(float x)
{
    setLengthSteps(mmToSteps(x))
}

float Engine::getLength()
{
    return m_motor.getEncoderCnt()/m_spmm;
}

