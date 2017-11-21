#include <stdio.h>
#include <PlotWindow.h>
#include "fssimplewindow.h"

void GraphPosition::GraphPosition(void)
{//This graphs the position data 
	double timestep;
	glColor3ub(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	const double y = timestep*x;
}
void VelocityData::GraphVelocity(void)
{//This graphs the velocity data
	double timestep;
	glColor3ub(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	const double y = timestep*x;
}