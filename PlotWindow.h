#ifndef _PLOTWINDOW_IS_INCLUDED_
#define _PLOTWINDOW_IS_INCLUDED_ 

#include "GraphicsWindow.h"
#include "Mass.h"
#include <vector>
#include "UIWindow.h"

//This class creates the plot window. It inherits information from the Graphics Class. 

class PlotWindow : public GraphicsWindow
{//Public members from the GraphicsWindow class will be available. 

protected:

	int axiscolorRed;
	int axiscolorGreen;
	int axiscolorBlue;

	int plot1Red;
	int plot1Green;
	int plot1Blue;

	int plot2Red;
	int plot2Green;
	int plot2Blue;

	int fontRed; 
	int fontGreen; 
	int fontBlue;

	double velocity1;
	double velocity2;

	double maxposition; 
	double maxvelocity; 

	double minposition; 
	double minvelocity; 

	// Magnifiers for position and velocity
	double magnifier_pos;
	double magnifier_vel;

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

	//function to draw axes and legend
	void DrawPositionAxes(void);
	void DrawVelocityAxes(void);
	void DrawLegend(void);

	////function to draw graphs 
	void GraphPosition(double pos1, double pos2, double time, double maxTime); //function for drawing position graph
	void GraphVelocity(double vel1, double vel2, double time, double maxTime);
	
	////Functions that call real-time positions and velocities from the Mass class
	void Velocity(double vel1, double vel2, double time);
	void Position(double pos1, double pos2);

	//Draws Windows
	void plot(double vel1, double vel2, double pos1, double pos2, double time, double maxTime);

	//Resets info 
	void reset(void);
};

#endif
