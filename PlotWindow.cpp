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

int PlotWindowXposition = 400; 
int PlotWindowYposition = 800; 

int PlotWindowWidth = 600;
int PlotWindowHeight = 500;

PlotWindow::PlotWindow()
{
	borderWeight = 2;
	borderRed = 0;
	borderGreen = 0;
	borderBlue = 0;

	backgroundRed = 255;
	backgroundGreen = 255;
	backgroundBlue = 255;

	plotWeight = 1; 
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

void PlotWindow::GraphPosition(void)
{

}

void PlotWindow::GraphVelocity(void)
{

}

void PlotWindow::reset(void)
{
    
}

void PlotWindow::draw(Mass mass1, Mass mass2, double timeStep)
{
    drawBackground();
    drawBorder();
}
