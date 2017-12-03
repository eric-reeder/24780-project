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
	//Constructs plot window 
	borderWeight = 6;
	borderRed = 0;
	borderGreen = 0;
	borderBlue = 0;

	backgroundRed = 255;
	backgroundGreen = 255;
	backgroundBlue = 255;

	//magnifier = 400.0;
	magnifier_vel = 300;
	magnifier_pos = 300;

	//magnifier_x = 100;

	velocitytranslation = 900.0;
	positiontranslation = 450.0;

	axiscolorRed = 0;
	axiscolorBlue = 0;
	axiscolorGreen = 0;

	//Draws orange line for the first plot
	plot1Red = 255;
	plot1Green = 69;
	plot1Blue = 0;

	//Draws teal line for second plot
	plot1Red = 92;
	plot1Green = 233;
	plot1Blue = 233;

}



void PlotWindow::DrawPositionAxes(void)
{//Draws postion graph axes 
	glColor3ub(axiscolorRed, axiscolorGreen, axiscolorBlue);
	glBegin(GL_LINES);

	//Draws y axis 
	glVertex2i(450, 650); //glVertex2i()
	glVertex2i(450, 450);

	//Draws x axis 
	glVertex2i(800, 550);
	glVertex2i(450, 550);

	glEnd();
}


void PlotWindow::DrawVelocityAxes(void)
{//Draws velocity graph axes
	glColor3ub(axiscolorRed, axiscolorGreen, axiscolorBlue);
	glBegin(GL_LINES);

	//Draws y axis 
	glVertex2i(900, 650);
	glVertex2i(900, 450);

	//Draws x axis 
	glVertex2i(1300, 550);
	glVertex2i(900, 550);

	glEnd();
}

void PlotWindow::Velocity(double vel1, double vel2, double time)
{//This calls the velocities for mass 1 and 2  from the Mass class 
 //double velocity1 = magnifier*mass1.getVelocity() +velocitytranslation; //magnifies data and shifts based on the axes 
 //double velocity2 = magnifier*mass2.getVelocity() +velocitytranslation;

	velocity1 = 550 - magnifier_vel*vel1; //magnifies data and shifts based on the axes 
	velocity2 = 550 - magnifier_vel*vel2;

	//double velo1 = 900.0; //magnifies data and shifts based on the axes 
	//double velo2 = 900.0;

	//printf("SCALED VEL: %d\n", velo1);

	//printf("MASS 1 VELOCITY: %d\n", vel1);

	storedvelocity1.push_back(velocity1); //reads 
	storedvelocity2.push_back(velocity2);

	//printf("TIME (PLOT_WINDOW): %d\n", time);

	// Adding the time to the timePeriods vectors
	timePeriods.push_back(time);

	//printf("VELOCITY>PLOT_WINDOW\n");
	/*std::copy(storedvelocity1.begin(), storedvelocity1.end(), plotvelocity1); //converts to array

	for (int i = 0; i < storedvelocity1.size(); i++)
	{
	//debugging to check values are actually printing

	printf("%lf", storedvelocity1[i]);
	}*/

}


void PlotWindow::Position(double pos1, double pos2)
{//This calls the positions for mass 1 and 2 from the Mass class 
	double position1 = 550 - magnifier_pos*pos1;
	double position2 = 550 - magnifier_pos*pos2;


	storedposition1.push_back(position1);
	storedposition2.push_back(position2);
	
}




void PlotWindow::GraphPosition(double pos1, double pos2, double time, double maxTime)
{
	Position(pos1, pos2);
	glLineWidth(2);
	glBegin(GL_LINE_STRIP);
	glColor3ub(plot1Red, plot1Green, plot1Blue);

	//draws line based on 
	for (int i = 0; i < storedposition1.size(); i++)
	{
		double x;												// Screen coordinate for time (time axis)
		//glDrawArrays(GL_LINE_LOOP, 0, plotvelocity1[i]);
		x = (450 + timePeriods[i] * ((800 - 450) / maxTime));
		glVertex2d(x, storedposition1[i]);
	}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	glColor3ub(plot2Red, plot2Green, plot2Blue);
	for (int i = 0; i < storedposition2.size(); i++)
	{
		double x;												// Screen coordinate for time (time axis)
																//glDrawArrays(GL_LINE_LOOP, 0, plotvelocity1[i]);
		x = (450 + timePeriods[i] * ((800 - 450) / maxTime));
		glVertex2d(x, storedposition2[i]);
	}
	glEnd();

}


void PlotWindow::GraphVelocity(double vel1, double vel2, double time, double maxTime)
{
	Velocity(vel1, vel2, time);

	glColor3ub(plot1Red, plot1Green, plot1Blue);
	glLineWidth(2);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < storedvelocity1.size(); i++)
	{
		double x;												// Screen coordinate for time (time axis)
																//glDrawArrays(GL_LINE_LOOP, 0, plotvelocity1[i]);
		x = (900 + timePeriods[i] * ((1300 - 900) / maxTime));
		glVertex2d(x, storedvelocity1[i]);
	}
	glEnd();

	glColor3ub(plot2Red, plot2Green, plot2Blue);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < storedvelocity2.size(); i++)
	{
		double x;												// Screen coordinate for time (time axis)
																//glDrawArrays(GL_LINE_LOOP, 0, plotvelocity1[i]);
		x = (900 + timePeriods[i] * ((1300 - 900) / maxTime));
		
		glVertex2d(x, storedvelocity2[i]);
	}
	glEnd();
}

void PlotWindow::reset(void)
{//resets velocity value information
 /*storedvelocity1.resize(0);
 storedvelocity2.resize(0); 
 storedposition1.resize(0);
 storedposition2.resize(0);*/
}


//void PlotWindow::draw(double vel1, double vel2, double time, double maxTime)
//{
//	//printf("PLOT_WINDOW_DRAW\n");
//	//printf("MASS 1 VELOCITY: %d\n", vel1);
//	//printf("TIME (PLOT_WINDOW): %d\n", time);
//
//	drawBackground();
//	drawBorder();
//	DrawPositionAxes();
//	DrawVelocityAxes();
//	//GraphPosition(); 
//	GraphVelocity(vel1, vel2, time, maxTime);
//	//reset();
//
//}

void PlotWindow::plot(double vel1, double vel2, double pos1, double pos2, double time, double maxTime)
{
	//printf("PLOT_WINDOW_DRAW\n");
	//printf("MASS 1 VELOCITY: %d\n", vel1);
	//printf("TIME (PLOT_WINDOW): %d\n", time);

	drawBackground();
	drawBorder();
	DrawPositionAxes();
	DrawVelocityAxes();
	
	GraphVelocity(vel1, vel2, time, maxTime);
	GraphPosition(pos1, pos2, time, maxTime);
	
	//reset();

}
