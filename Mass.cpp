#include "Mass.h"
#include "SimulationObject.h"
#include "fssimplewindow.h"


Mass::Mass()
{
	position = 0;
	mass = 0.0;
	velocity = 0.0;
	maxDisplacement = 1;
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


void Mass::draw(const int xOffset, const int yOffset) const
{
	if (state == true)
	{
		glColor3ub(redVal, greenVal, blueVal);
		glBegin(GL_TRIANGLE_FAN);

		if (position < maxDisplacement)
		{
			glVertex2i(position + xOffset, yOffset);
			glVertex2i(position + xOffset + width, yOffset);
			glVertex2i(position + xOffset + width, yOffset + height);
			glVertex2i(position + xOffset, yOffset + height);
		}

		else
		{
			glVertex2i(maxDisplacement + xOffset, yOffset);
			glVertex2i(maxDisplacement + xOffset + width, yOffset);
			glVertex2i(maxDisplacement + xOffset + width, yOffset + height);
			glVertex2i(maxDisplacement + xOffset, yOffset + height);
		}
		
		glEnd();
	}
}
