#include <stdio.h>
#include "PlotWindow.h"
#include "Mass.h"
#include "fssimplewindow.h"

/*Creates a graphics window object with black border and white background
Inputs :
appWidth: Width of app window
appHeight : Height of app window
inputMargin : Margin between this window and other windows
widthFraction : Fraction of app window width this window will be
heightFraction : Fraction of app window height this window will be
inputXPosition : X coordinate of top left corner
inputYPosition : Y coordinate of top left corner  * /
// Sets x and y coordinates of top left corner
Inputs:
newXPosition: X coordinate of top left corner
newYPosition: Y coordinate of top left corner  */



PlotWindow::PlotWindow()
{
	plotWindowXPosition = 400;
	plotWindowYPosition = 800;

	PlotWindowWidth = 600;
	PlotWindowHeight = 500;
	
	borderWeight = 6;
	borderRed = 0;
	borderGreen = 0;
	borderBlue = 0;

	backgroundRed = 255;
	backgroundGreen = 255;
	backgroundBlue = 255;

	plotWeight = 1;
	
	graphRed = 0;
	graphGreen = 0;
	graphBlue = 0;

	initialtime = 0.0;
	time = 9.0; 

	velocity = 8.7; //test value
	position = 12.0; //test value 
}

void PlotWindow::DrawPositionAxes(void)
{//Draws postion graph axes 
	glColor3ub(borderRed, borderGreen, borderBlue);
	glBegin(GL_LINES);
	glLineWidth(plotWeight);

	glVertex2i(PositionGraphXMargin, PositionGraphYMargin);
	glVertex2i(PositionGraphXMargin + PositionXAxisLength, PositionGraphYMargin + PositionYAxisHeight);

	glEnd();
}


void PlotWindow::DrawVelocityAxes(void)
{//Draws velocity graph axes
	glColor3ub(borderRed, borderGreen, borderBlue);
	glBegin(GL_LINES);
	glLineWidth(plotWeight);

	glVertex2i(VelocityGraphXMargin, VelocityGraphYMargin);
	glVertex2i(VelocityGraphXMargin + VelocityXAxisLength, VelocityGraphYMargin + VelocityYAxisHeight);

	glEnd();
}

//double Mass::getPosition(void) const
//{//Gets the real-time position from the Mass class
//	return position;
//}

//double Mass::getVelocity(void) const
//{//Gets the real-time velocity from the Mass class 
//	return velocity;
//}

//void Mass::setVelocity(const double newVelocity)
//{
//	velocity = newVelocity;
//}

void PlotWindow::GraphPosition(void)
{
	glColor3ub(graphRed, graphGreen, graphBlue);
	glBegin(GL_LINE_STRIP);
	glVertex2d(initialtime, initialposition);
	glVertex2d(initialtime + time, initialposition + position);
	glEnd();
}

void PlotWindow::GraphVelocity(void)
{
	glColor3ub(graphRed, graphGreen, graphBlue);
	glBegin(GL_LINE_STRIP);
	glVertex2d(initialtime, initialvelocity);
	glVertex2d(initialtime + time, initialposition + velocity);
	glEnd();
}

void PlotWindow::reset(void)
{

}

void PlotWindow::draw(Mass mass1, Mass mass2, double timeStep)
{
	drawBackground();
	drawBorder();
}
