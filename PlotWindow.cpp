#include <stdio.h>
#include "PlotWindow.h"
  
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

const int PlotWindowXposition = 400; 
const int PlotWindowYposition = 800; 

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


void GraphicsWindow::setPosition(const int newXPosition, const int newYPosition)
{
	PlotWindowXposition = newXPosition;
	PlotWindowYposition = newYPosition;
}

void GraphicsWindow::setSize(const int newWidth, const int newHeight)
{
	PlotWindowWidth = newWidth;
	PlotWindowHeight = newHeight;
}

//  Draws background of graphics window  //

void GraphicsWindow::drawBackground(void) const
{
	glColor3ub(backgroundRed, backgroundGreen, backgroundBlue);
	glBegin(GL_QUADS);
	glVertex2i(xPosition, yPosition);
	glVertex2i(xPosition + width, yPosition);
	glVertex2i(xPosition + width, yPosition + height);
	glVertex2i(xPosition, yPosition + height);
	glEnd();
}

// Draws border on graphics window  //
void GraphicsWindow::drawBorder(void) const
{
	glColor3ub(borderRed, borderGreen, borderBlue);
	glBegin(GL_LINES);
	glLineWidth(borderWeight);

	glVertex2i(xPosition, yPosition);
	glVertex2i(xPosition + width, yPosition);

	glVertex2i(xPosition + width, yPosition);
	glVertex2i(xPosition + width, yPosition + height);

	glVertex2i(xPosition + width, yPosition + height);
	glVertex2i(xPosition, yPosition + height);

	glVertex2i(xPosition, yPosition + height);
	glVertex2i(xPosition, yPosition);
	glEnd();
}



//  Draws the graphics window  //
void GraphicsWindow::draw() const
{
	drawBackground();
	drawBorder();
}

voidPlotWindow::DrawPositionAxes(void)
{//Draws postion graph axes 
	glColor3ub(borderRed, borderGreen, borderBlue);
	glBegin(GL_LINES);
	glLineWidth(plotWeight);

	glVertex2i(PositionGraphXMargin, PositionGraphYMargin);
	glVertex21(PositionGraphXMargin + PositionXAxisLength, PositionGraphYMargin + PositionYAxisHeight)

	glEnd();
}


void PlotWindow::DrawVelocityAxes(void)
{//Draws velocity graph axes
	glColor3ub(borderRed, borderGreen, borderBlue);
	glBegin(GL_LINES);
	glLineWidth(plotWeight);

	glVertex2i(VelocityGraphXMargin, VelocityGraphYMargin);
	glVertex21(VelocityGraphXMargin + VelocityXAxisLength, VelocityYMargin + VelocityYAxisHeight)

	glEnd();
}

void PlotWindow::GraphPosition(void)
{

}

void PlotWindow::GraphVelocity(void)
{

}


void PlotWindow::CleanUp();
{
	delete[] displacement; 
	delete[] velocity; 
}