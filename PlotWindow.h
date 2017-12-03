#ifndef _PLOTWINDOW_IS_INCLUDED_
#define _PLOTWINDOW_IS_INCLUDED_ 

#include "GraphicsWindow.h"
#include "Mass.h"
#include <vector>

//This class creates the plot window. It inherits information from the Graphics Class. 

class PlotWindow : public GraphicsWindow
{//Public members from the GraphicsWindow class will be available. 

protected:

	/*int axislength;
	int axisheight;*/

	int axiscolorRed;
	int axiscolorGreen;
	int axiscolorBlue;

	int plot1Red;
	int plot1Green;
	int plot1Blue;

	int plot2Red;
	int plot2Green;
	int plot2Blue;

	double velocity1;
	double velocity2;

	// Magnifiers for position and velocity
	double magnifier_pos;
	double magnifier_vel;

	// Magnifier for x coordinates 

	double magnifier_x; 

	double positiontranslation;
	double velocitytranslation;

	std::vector <double> storedvelocity1;
	std::vector <double> storedvelocity2;

	std::vector<double> timePeriods;				// Stores all the different time values at which calculations are done

	double plotvelocity1[100];

	std::vector <double> storedposition1;
	std::vector <double> storedposition2;

public:
	PlotWindow(); //Initalizes plot window

				  //Retrieves coordinates from Animation Class
				  //void GetCoordinates(void);

				  //function to draw axes 
	void DrawPositionAxes(void);
	void DrawVelocityAxes(void);

	////function to draw graphs 
	void GraphPosition(double pos1, double pos2, double time, double maxTime); //function for drawing position graph
	void GraphVelocity(double vel1, double vel2, double time, double maxTime);
	//
	//
	////Functions that call real-time positions and velocities from the Mass class
	void Velocity(double vel1, double vel2, double time);
	void Position(double pos1, double pos2);

	//Draws Windows
	//void draw(double vel1, double vel2, double time, double maxTime);

	void plot(double vel1, double vel2, double pos1, double pos2, double time, double maxTime);

	//Resets info 
	void reset(void);
};

#endif
