#include "RadioButton.h"
#include "fssimplewindow.h"
#include<math.h>



void DrawCircle(double cx, double cy, double radius, int fill)
{
	double x,y,angle;
	if(fill!=0)
	{
		glBegin(GL_TRIANGLE_FAN);
	}
	else
	{
		glBegin(GL_LINE_LOOP);
	}
	for(int i=0;i<64;++i)
	{
		angle = ((double)i*YS_PI)/32.0;
		x = cx + (radius*cos(angle));
		y = cy + (radius*sin(angle));
		glVertex2d(x,y);

	}
	glEnd();
}

void RadioButton::Initialize(const double winWidth, const double startY)
{
	radius = 6;
	centreX = winWidth / 20;
	centreY = startY;
	state = 0;
}

void RadioButton::DrawRadio(void) const
{
	
	int fill = 0;
	int buttonSpace = (8 * 14);
	DrawCircle(centreX, centreY, radius, fill);
	DrawCircle(centreX + buttonSpace, centreY, radius, fill);
	DrawCircle(centreX + (2 * buttonSpace), centreY, radius, fill);
}

void RadioButton::SetValue(int set)
{
	state = set;
}

double RadioButton::returnCentreX(void) const
{
	return centreX;
}

const double RadioButton::returnCentreY(void) const
{
	return centreY;
}

const double RadioButton::returnRadius(void) const
{
	return radius;
}


const int RadioButton::RadioOutput(void) const
{
	return state;
}
