#ifndef _PLOTWINDOW_IS_INCLUDED_
#define _PLOTWINDOW_IS_INCLUDED_ 

#include "GraphicsWindow.h"
#include "Mass.h"
#include <vector>

//This class creates the plot window. It inherits information from the Graphics Class. 

class PlotWindow : public GraphicsWindow
{//Public members from the GraphicsWindow class will be available. 

protected:
	
	int axislength;
	int axisheight;

	int axiscolorRed;
	int axiscolorGreen;
	int axiscolorBlue;
	
	int plot1Red; 
	int plot1Green; 
	int plot1Blue;

	int plot2Red; 
	int plot2Green; 
	int plot2Blue; 

	int plotx1; 

	double position1;
	double position2;

	double velocity1;
	double velocity2;

	double xstart; 
	double ystart; 

	std::vector <double> storedvelocity1;
	std::vector <double> storedvelocity2;

	std::vector <double> storedposition1;
	std::vector <double> storedposition2;

public:
	PlotWindow(); //Initalizes plot window

	//Retrieves coordinates from Animation Class
	//void GetCoordinates(void);
				  
	//function to draw axes 
	void DrawPositionAxes(void);
	void DrawVelocityAxes(void); 

	//function to draw graphs 
	void GraphPosition(void); //function for drawing position graph
	void GraphVelocity(void);
	
	
	//Functions that call real-time positions and velocities from the Mass class
	void Velocity(Mass mass1, Mass mass2);
	void Position(Mass mass1, Mass mass2);

	//Draws Windows
	void draw(Mass mass1, Mass mass2, double timeStep);
	
	//Resets info 
	void reset(void);
};

#endif