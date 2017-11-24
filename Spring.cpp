#include "Spring.h"
#include "SimulationObject.h"
#include "fssimplewindow.h"

Spring::Spring()
{
	position = 0;
	length = 0;
	equilibriumLength = 0;
	stiffness = 0;
    state = true;
    redVal = 0;
    blueVal = 255;
    greenVal = 0;
}


double Spring::getStiffness(void) const
{
	return stiffness;
}


void Spring::setStiffness(const double newStiffness)
{
	stiffness = newStiffness;
}


double Spring::getLength(void) const
{
	return length;
}



void Spring::setLength(const double newLength)
{
	length = newLength;
}


double Spring::getEquilibriumLength(void) const
{
	return equilibriumLength;
}


void Spring::setEquilibriumLength(const double newEquilibriumLength)
{
	equilibriumLength = newEquilibriumLength;
}


void Spring::draw(void) const
{
	glColor3ub(redVal, greenVal, blueVal);

	// @Terri this is you

	glEnd();
}
