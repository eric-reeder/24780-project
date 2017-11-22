#include "SimulationObject.h"

/*  Creates simulation object and sets it's position to zero, state to active
    (true), and color to black  */
SimulationObject::SimulationObject()
{
    position = 0;
    state = true;
    redVal = 0;
    blueVal = 0;
    greenVal = 0;
}


void SimulationObject::setState(const bool newState)
{
    state = newState;
}


bool SimulationObject::getState(void) const
{
    return state;
}


void SimulationObject::setPosition(const double newPosition)
{
    position = newPosition;
}


double SimulationObject::getPosition(void) const
{
    return position;
}


int SimulationObject::getRedVal(void) const
{
    return redVal;
}


int SimulationObject::getBlueVal(void) const
{
    return blueVal;
}


int SimulationObject::getGreenVal(void) const
{
    return greenVal;
}


void SimulationObject::setColor(const int newRedVal, const int newGreenVal, 
    const int newBlueVal)
{
    redVal = newRedVal;
    greenVal = newGreenVal;
    blueVal = newBlueVal;
}
