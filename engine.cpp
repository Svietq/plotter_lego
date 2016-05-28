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
void Engine::rotate(int x, int speed)
{
    if(m_motorid == 1)
        hMot1.rotRel(x, speed);
    else
        hMot2.rotRel(x, speed);
}

void Engine::setLengthSteps(int x, int speed)
{
    if(m_motorid == 1)
        hMot1.rotAbs(x, speed);
    else
        hMot2.rotAbs(x, speed);
}

int Engine::getLengthSteps()
{
    if(m_motorid == 1)
        return hMot1.getEncoderCnt();
    else
        return hMot2.getEncoderCnt();
}

/** @brief Resetowanie enkodera
  *
  * Uzycie wbudowanych funkcji silinkow do zresetowania enkodera
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

void Engine::setLength(float x, int speed)
{
    setLengthSteps(mmToSteps(x), speed);
}

float Engine::getLength()
{
    if(m_motorid == 1)
        return hMot1.getEncoderCnt()/m_spmm;
    else
        return hMot2.getEncoderCnt()/m_spmm;
}

