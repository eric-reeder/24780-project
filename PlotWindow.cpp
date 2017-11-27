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
{//Constructs plot window 
	borderWeight = 6;
	borderRed = 0;
	borderGreen = 0;
	borderBlue = 0;

	backgroundRed = 255;
	backgroundGreen = 255;
	backgroundBlue = 255;

	/*plotWeight = 1;
	
	graphRed = 0;
	graphGreen = 0;
	graphBlue = 0;

	initialtime = 0.0;
	time = 9.0; 

	PositionGraphXMargin = 2; 
	PositionGraphYMargin = 2;

	VelocityGraphXMargin = 2;
	VelocityGraphYMargin = 4; 

	velocity = 8.7; 
	position = 12.0;*/
}

void PlotWindow::DrawPositionAxes(void)
{//Draws postion graph axes 
	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	glLineWidth(0.1);

	//Draws y axis 
	glVertex2i(450, 650);
	glVertex2i(450, 450);

	//Draws x axis 
	glVertex2i(800, 650);
	glVertex2i(450, 650);

	glEnd();
}


void PlotWindow::DrawVelocityAxes(void)
{//Draws velocity graph axes
	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	glLineWidth(0.1); 

	//Draws y axis 
	glVertex2i(850, 650);
	glVertex2i(850, 450);

	//Draws x axis 
	glVertex2i(1200, 650);
	glVertex2i(850, 650);

	glEnd();
}

//double Mass::getVelocity(void) const
//{
//	return velocity;
//}
//
//double Mass::getPosition(void) 
//{
//	position = position + 1;
//	return position;
//}


void PlotWindow::GraphPosition(void)
{
	glColor3ub(0, 0, 255);
	glBegin(GL_LINE_STRIP);
	glVertex2d(500, 600);
	glVertex2d(600, 650);
	glEnd();
}

void PlotWindow::GraphVelocity(void)
{
	glColor3ub(0, 255, 0);
	glBegin(GL_LINE_STRIP);
	glVertex2d(1000, 600);
	glVertex2d(1100, 600);
	glEnd();
}

void PlotWindow::reset(void)
{

}

void PlotWindow::draw(Mass mass1, Mass mass2, double timeStep)
{
	drawBackground();
	drawBorder();
	DrawPositionAxes();
	DrawVelocityAxes();
	GraphPosition(); 
	GraphVelocity();

}