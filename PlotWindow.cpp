#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include "PlotWindow.h"
#include "Mass.h"
#include "fssimplewindow.h"



PlotWindow::PlotWindow()
{//Constructs plot window 
	borderWeight = 6;
	borderRed = 0;
	borderGreen = 0;
	borderBlue = 0;

	backgroundRed = 255;
	backgroundGreen = 255;
	backgroundBlue = 255;
}

void PlotWindow::GetCoordinates(void)
{

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

void PlotWindow::Velocity(Mass mass1, Mass mass2) const 
{//This calls the velocities for mass 1 and 2  from the Mass class 
	double velocity1 = mass1.getVelocity();
	double velocity2 = mass2.getVelocity(); 
	
	std::vector <double> storedvelocity1;
	std::vector <double> storedvelocity2;

	storedvelocity1.push_back(velocity1);
	storedvelocity2.push_back(velocity2);

	//std::transform(storedvelocity1.begin(), storedvelocity1.end(), storedvelocity1.begin(), bind2nd()

}


void PlotWindow::Position(Mass mass1, Mass mass2) const
{//This calls the positions for mass 1 and 2 from the Mass class 
	double position1 = mass1.Weee();
	double position2 = mass2.Weee(); 

	std::vector <double> storedposition1; 
	std::vector <double> storedposition2;

	storedposition1.push_back(position1);
	storedposition2.push_back(position2);

}



void PlotWindow::GraphPosition(void)
{
	glColor3ub(0, 0, 255);
	glBegin(GL_LINE_LOOP);

	for (int i = 0; i < storedposition1.size(); i++)
	{
		glVertex2d(i, storedposition1[i]);
		
	}

	for (int j = 0; j < storedposition2.size(); j++)
	{
		glVertex2d(j, storedposition2[j]);
	}
	glEnd();

}

void PlotWindow::GraphVelocity(void)
{
	glColor3ub(0, 255, 0);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < storedvelocity1.size(); i++)
	{
		glVertex2d(i, storedvelocity1[i]);
	}

	for (int j = 0; j < storedvelocity2.size(); j++)
	{
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