#include <stdio.h>
#include "PlotWindow.h"
#include "Mass.h"
#include "fssimplewindow.h"
#include "ysglfontdata.h"

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

	magnifier_vel = 100;
	magnifier_pos = 300;

	velocitytranslation = 900.0;
	positiontranslation = 450.0;

	//gray axes 
	axiscolorRed = 200;
	axiscolorBlue = 200;
	axiscolorGreen = 200;

	fontRed = 0;
	fontGreen = 0;
	fontBlue = 0;

	//Draws red line for the first plot
	plot1Red = 255;
	plot1Green = 0;
	plot1Blue = 0;

	//Draws blue line for second plot
	plot2Red = 0;
	plot2Green = 255;
	plot2Blue = 255;

}



void PlotWindow::DrawPositionAxes(void)
{//Draws postion graph axes 
	char* positiontitle = "Real-Time Relative Position"; //Position Graph Label 
	glRasterPos2d(500, 425);
	glColor3ub(fontRed, fontBlue, fontGreen);
	YsGlDrawFontBitmap12x16(positiontitle);

	char* xpositionlabel = "t"; //label axes
	glRasterPos2d(805, 550);
	glColor3ub(fontRed, fontBlue, fontGreen);
	YsGlDrawFontBitmap12x16(xpositionlabel);

	char* ypositionlabel = "x"; //label axes
	glRasterPos2d(450, 445);
	glColor3ub(fontRed, fontBlue, fontGreen);
	YsGlDrawFontBitmap12x16(ypositionlabel);
	
	glColor3ub(axiscolorRed, axiscolorGreen, axiscolorBlue); //draw axes 
	glBegin(GL_LINES);
	glLineWidth(0.3);
	
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
	char* velocitytitle = "Real-Time Relative Velocity";
	char* xpositionlabel = "t";
	char* ypositionlabel = "v";
	glColor3ub(fontRed, fontBlue, fontGreen);

	glRasterPos2d(950, 425);
	YsGlDrawFontBitmap12x16(velocitytitle);	
	glRasterPos2d(1305, 550);
	YsGlDrawFontBitmap12x16(xpositionlabel);

	glRasterPos2d(905, 445);
	YsGlDrawFontBitmap12x16(ypositionlabel);
	
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

void PlotWindow::DrawLegend(void)
{//Draws Legend 
	char* mass1label = "Mass 1";
	char* mass2label = "Mass 2";
	char* ratiolabel = "Position:Velocity Ratio = 3:1";
	
	
	glColor3ub(0, 0, 0);
	glRasterPos2d(1305, 395);
	YsGlDrawFontBitmap10x14(mass1label); //Mass 1 Text
	glRasterPos2d(1305, 420);
	YsGlDrawFontBitmap10x14(mass2label); //Mass 2 Text 
	glRasterPos2d(775, 685);
	YsGlDrawFontBitmap10x14(ratiolabel); //Ratio Text 

	glColor3ub(plot1Red, plot1Green, plot1Blue); //Draws Mass 1 Line
	glBegin(GL_LINES);
	glLineWidth(2);
	glVertex2i(1300, 400);
	glVertex2i(1350, 400);
	
	glColor3ub(plot2Red, plot2Green, plot2Blue); //Draws Mass 2 Line 
	glBegin(GL_LINES);
	glLineWidth(1);
	glVertex2i(1300, 425);
	glVertex2i(1350, 425);

	glEnd();
}


void PlotWindow::Velocity(double vel1, double vel2, double time)
{//This calls the velocities for mass 1 and 2  from the Mass class 

	velocity1 = 550 - magnifier_vel*vel1; //magnifies data and shifts based on the axes 
	velocity2 = 550 - magnifier_vel*vel2;

	storedvelocity1.push_back(velocity1); //reads 
	storedvelocity2.push_back(velocity2);

	// Adding the time to the timePeriods vectors
	timePeriods.push_back(time);


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
	glLineWidth(1);
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
	glLineWidth(1);
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
	storedvelocity1.resize(0);  
	storedvelocity2.resize(0); 
	storedposition1.resize(0);
	storedposition2.resize(0);
	timePeriods.resize(0);
}


void PlotWindow::plot(double vel1, double vel2, double pos1, double pos2, double time, double maxTime)
{

	drawBackground();
	drawBorder();
	DrawPositionAxes();
	DrawVelocityAxes();
	DrawLegend();
	
	GraphVelocity(vel1, vel2, time, maxTime);
	GraphPosition(pos1, pos2, time, maxTime);

	reset();
}
