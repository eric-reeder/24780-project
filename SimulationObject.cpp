#include "SimulationObject.h"

// Creates simulation object and sets it's position to zero and color to black
SimulationObject::SimulationObject()
{
    position = 0;
    state = true;
    redVal = 0;
    blueVal = 0;
    greenVal = 0;
}


// Returns the position of the object in pixels
double getPosition(void) const
{
    return position;
}


// Sets the position of the object in pixels
void setPosition(const double newPosition)
{
    position = newPosition;
}


int getRedVal(void) const
{
    return redVal;
}


void setRedVal(const int newRedVal);
{
    redVal = newRedVal;
}


int getBlueVal(void) const
{
    return blueVal;
}


void setBlueVal(const int newBlueVal)
{
    blueVal = newBlueVal;
}


int getGreenVal(void) const
{
    return greenVal;
}


void setGreenVal(const int newGreenVal)
{
    greenVal = newGreenVal;
}
