#include "SimulationObject.h"

// Creates simulation object and sets it's position to zero and color to black
SimulationObject::SimulationObject()
{
    position = 0;
    redVal = 0;
    blueVal = 0;
    greenVal = 0;
}


// Returns the position of the object in pixels
double getPosition(void)
{
    return position;
}


// Sets the position of the object in pixels
void setPosition(double newPosition)
{
    position = newPosition;
}


int getRedVal(void)
{
    return redVal;
}

void setRedVal(int newRedVal);
{
    redVal = newRedVal;
}

int getBlueVal(void)
{
    return blueVal;
}


void setBlueVal(int newBlueVal)
{
    blueVal = newBlueVal;
}


int getGreenVal(void)
{
    return greenVal;
}


void setGreenVal(int newGreenVal)
{
    greenVal = newGreenVal;
}
