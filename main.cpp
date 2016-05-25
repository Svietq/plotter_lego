#include <hFramework.h>
#include <stdio.h>
#include "engine.h"
#include "interpreter.h"
void hMain()
{
    Interpreter inter;
    Engine engine1;
    engine1.setMotorId(1);
    Engine engine2;
    engine2.setMotorId(2);

    while(1)
    {
        inter.doCommand("G1 X40.0 Y10.0 F23.0");
        sys.delay(10000);
        inter.doCommand("G1 X50.0 Y30.0 F23.0");
        sys.delay(10000);
        inter.doCommand("G1 X20.0 Y20.0 F23.0");
        sys.delay(10000);
    }
}
