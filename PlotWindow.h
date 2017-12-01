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
	int axiscolorBlue;
	int axiscolorGreen;

	double position1;
	double position2;

	double velocity1;
	double velocity2;

	std::vector <double> storedvelocity1;
	std::vector <double> storedvelocity2;

	std::vector <double> storedposition1;
	std::vector <double> storedposition2;
public:
	PlotWindow(); //Initalizes plot window

	//function to draw axes 
	void DrawPositionAxes(void);
	void DrawVelocityAxes(void); 

	//function to draw graphs 
	void GraphPosition(void); //function for drawing position graph
	void GraphVelocity(void);
	
	
	//Functions that call real-time positions and velocities from the Mass class
	void Velocity(Mass mass1, Mass mass2) const;
	void Position(Mass mass1, Mass mass2) const;

	//Draws Windows
	void draw(Mass mass1, Mass mass2, double timeStep);
	
	//Resets info 
	void reset(void);
};

#endif