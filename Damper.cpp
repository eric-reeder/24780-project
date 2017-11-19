#include "Damper.h"
#include "UIWindow.h"
#include "fssimplewindow.h"


Damper::Damper()
{
	position = 0;
	length = 0;
	damping = 0;
    state = true;
    redVal = 0;
    blueVal = 0;
    greenVal = 255;
}


double Damper::getDamping(void) const
{
	return damping;
}


void Damper::setDamping(const UIWindow uiWindow)
{
	// @Sidarth this is you
}


double Damper::getLength(void) const
{
	return length;
}


void Damper::setLength(const double newLength)
{
	length = newLength;
}


void Damper::draw(void) const
{
	glColor3ub(redVal, greenVal, blueVal);

	// @Terri all yours

	glEnd();
}
