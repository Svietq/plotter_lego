#include "engine.h"

Engine::Engine()
{

}

Engine::Engine(int id):m_id(id)
{

}

void Engine::rotate(int steps)
{
    if(m_id==1)
    {
        hMot1.rotRel(steps);
    }
    else if(m_id==2)
    {
        hMot2.rotRel(steps);
    }
}
