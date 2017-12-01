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
	centreX = winWidth / 15;
	centreY = startY;
	state = 3;
}

void RadioButton::DrawRadio(int n) const
{

	int fill = 0;
	int buttonSpace1 = (8 * 14);
	int buttonSpace2 = (3 * 14);
	if (n == 3)
	{
		if (state == 3)
		{
			DrawCircle(centreX, centreY, radius, fill);
			DrawCircle(centreX + buttonSpace1, centreY, radius, fill);
			DrawCircle(centreX + (2 * buttonSpace1), centreY, radius, fill);
		}
		if (state == 2)
		{
			DrawCircle(centreX, centreY, radius, 1);
			DrawCircle(centreX + buttonSpace1, centreY, radius, fill);
			DrawCircle(centreX + (2 * buttonSpace1), centreY, radius, fill);
		}
		if (state == 1)
		{
			DrawCircle(centreX, centreY, radius, fill);
			DrawCircle(centreX + buttonSpace1, centreY, radius, 1);
			DrawCircle(centreX + (2 * buttonSpace1), centreY, radius, fill);
		}
		if (state == 0)
		{
			DrawCircle(centreX, centreY, radius, fill);
			DrawCircle(centreX + buttonSpace1, centreY, radius, fill);
			DrawCircle(centreX + (2 * buttonSpace1), centreY, radius, 1);
		}

	}
	if (n == 2)
	{
		if (state == 0)
		{
			DrawCircle(centreX, centreY, radius, fill);
			DrawCircle(centreX + buttonSpace2, centreY, radius, fill);

		}
		if (state == 1)
		{
			DrawCircle(centreX, centreY, radius, 1);
			DrawCircle(centreX + buttonSpace2, centreY, radius, fill);

		}
		if (state == 2)
		{
			DrawCircle(centreX, centreY, radius, fill);
			DrawCircle(centreX + buttonSpace2, centreY, radius, 1);
			
		}

	}

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
const double RadioButton::returnRadioSpaceMargin1(void) const
{
	return radioSpaceMargin;
}

const double RadioButton::returnRadioSpaceMargin2(void) const
{
	return radioSpaceMargin2;
}

const int RadioButton::RadioOutput(void) const
{
	return state;
}