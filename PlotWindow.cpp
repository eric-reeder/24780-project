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

    axiscolorRed = 0;
    axiscolorBlue = 0;
    axiscolorGreen = 0;

	plot1Red = 127; 
	plot1Green = 0;
	plot1Blue = 0;

	plot1Red = 255;
	plot1Green = 0;
	plot1Blue = 0;

	plotx1 = 450; 

}

void GetCoordinates(void)
{
}


void PlotWindow::DrawPositionAxes(void)
{//Draws postion graph axes 
    glColor3ub(axiscolorRed, axiscolorGreen, axiscolorBlue);
	glBegin(GL_LINES);

	//Draws y axis 
	glVertex2i(plotx1, 650);
	glVertex2i(450, 450);

	//Draws x axis 
	glVertex2i(800, 650);
	glVertex2i(450, 650);

	glEnd();
}


void PlotWindow::DrawVelocityAxes(void)
{//Draws velocity graph axes
    glColor3ub(axiscolorRed, axiscolorGreen, axiscolorBlue);
	glBegin(GL_LINES);

	//Draws y axis 
	glVertex2i(850, 650);
	glVertex2i(850, 450);

	//Draws x axis 
	glVertex2i(1200, 650);
	glVertex2i(850, 650);

	glEnd();
}

void PlotWindow::Velocity(Mass mass1, Mass mass2)
{//This calls the velocities for mass 1 and 2  from the Mass class 
	double velocity1 = mass1.getVelocity();
	double velocity2 = mass2.getVelocity(); 

	storedvelocity1.push_back(velocity1);
	storedvelocity2.push_back(velocity2);
}


void PlotWindow::Position(Mass mass1, Mass mass2)
{//This calls the positions for mass 1 and 2 from the Mass class 
	double position1 = mass1.Weee();
	double position2 = mass2.Weee(); 


	storedposition1.push_back(position1);
	storedposition2.push_back(position2);
	
	for (auto &x : storedposition1)
	{
		x += plotx1;
	}

	for (int i = 0; i < storedposition1.size(); i++)
	{//debugging to check values are actually printing 

		printf("%lf", storedposition1[i]);

	}

}




void PlotWindow::GraphPosition(void)
{
	glBegin(GL_LINE_LOOP);
	glColor3ub(plot1Red, plot1Green, plot1Blue);

	//draws line based on 
	for (int i = 0; i < storedposition1.size(); i++)
	{
		
		glVertex2d(i, storedposition1[i]);
		
	}

	glColor3ub(plot2Red, plot2Green, plot2Blue);
	for (int j = 0; j < storedposition2.size(); j++)
	{
		
		glVertex2d(j, storedposition2[j]);
	}
	glEnd();

}

void PlotWindow::GraphVelocity(void)
{
	
	for (int i = 0; i < storedvelocity1.size(); i++)
	{
		glBegin(GL_LINE_LOOP);
		glColor3ub(plot1Red, plot1Green, plot1Blue);
		glVertex2d(i, storedvelocity1[i]);
	}

	for (int j = 0; j < storedvelocity2.size(); j++)
	{
		glBegin(GL_LINE_LOOP);
		glColor3ub(plot2Red, plot2Green, plot2Blue);
		glVertex2d(j, storedvelocity2[j]);
	}
	glEnd();
}

void PlotWindow::reset(void)
{//resets velocity value information
	storedvelocity1.resize(0);
	storedvelocity2.resize(0); 
	storedposition1.resize(0);
	storedposition2.resize(0);
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
