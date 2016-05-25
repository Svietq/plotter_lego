#include "engine.h"

Engine::Engine()// id)
{
    m_spmm = m_spc / (m_radius * 3.1415);
    //m_motorid = id;
}
Engine::~Engine()
{
}
void Engine::setMotorId(int id)
{
    m_motorid = id;
}
void Engine::rotate(int x)
{
    if(m_motorid == 1)
        hMot1.rotRel(x);
    else
        hMot2.rotRel(x);
}

void Engine::setLengthSteps(int x)
{
    if(m_motorid == 1)
        hMot1.rotAbs(x, 200);
    else
        hMot2.rotAbs(x, 200);
}

int Engine::getLengthSteps()
{
    if(m_motorid == 1)
        return hMot1.getEncoderCnt();
    else
        return hMot2.getEncoderCnt();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void Engine::resetEncoder()
{
    if(m_motorid == 1)
        hMot1.resetEncoderCnt();
    else
        hMot2.resetEncoderCnt();
}

int Engine::mmToSteps(float x)
{
    return x * m_spmm;
}

void Engine::setLength(float x)
{
    setLengthSteps(mmToSteps(x));
}

float Engine::getLength()
{
    if(m_motorid == 1)
        return hMot1.getEncoderCnt()/m_spmm;
    else
        return hMot2.getEncoderCnt()/m_spmm;
}

