#include "Mass.h"
#include "SimulationObject.h"
#include "fssimplewindow.h"


Mass::Mass()
{
	position = 0;
	mass = 0.0;
	velocity = 0.0;
	width = 50;
	height = 50;
    state = true;
    redVal = 255;
    blueVal = 0;
    greenVal = 0;
}


double Mass::getMass(void) const
{
	return mass;
}

void Mass::setMass(const double newMass)
{
	mass = newMass;
}


double Mass::getVelocity(void) const
{
	return velocity;
}


void Mass::setVelocity(const double newVelocity)
{
	velocity = newVelocity;
}


void Mass::draw(void) const
{
	glColor3ub(redVal, greenVal, blueVal);
	glBegin(GL_QUADS);

	/* @Terri I'm not sure exactly what protocol you've been doing drawing
	these, so I'm gonna leave it to you to finish this function */
	
	glEnd();
}
