#include "Servo.h"

Servo::Servo()
{
    //ctor
}

Servo::~Servo()
{
    //dtor
}

void Servo::setPen1()
{
    hMot3.rotAbs(90);
}

void Servo::setPen2()
{
    hMot3.rotAbs(-90);
}

void Servo::setOff()
{
    hMot3.rotAbs(0);
}
