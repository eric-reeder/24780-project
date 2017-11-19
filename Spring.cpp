#include "Spring.h"
#include "UIWindow.h"
#include "fssimplewindow.h"


Spring::Spring()
{
	position = 0;
	length = 0;
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


void Spring::setStiffness(const UIWindow uiWindow)
{
	// @Sidharth this is you
}


double Spring::getLength(void) const
{
	return length;
}



void Spring::setLength(const double newLength)
{
	length = newLength;
}


void draw(void) const
{
	glColor3ub(redVal, greenVal, blueVal);

	// @Terri this is you

	glEnd();
}
