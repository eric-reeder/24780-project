#ifndef _PLOTWINDOW_IS_INCLUDED_
#define _PLOTWINDOW_IS_INCLUDED_ 

#include "GraphicsWindow.h"
#include "Mass.h"
#include <vector>

//This class creates the plot window. It inherits information from the Graphics Class. 

class PlotWindow : public GraphicsWindow
{//Public members from the GraphicsWindow class will be available. 

protected:
	
	//defintes the thickness of the line
	int plotWeight;

	//defines width of plot window
	int PlotWindowWidth;
	int PlotWindowHeight;

	//sets origin of sub window
	int plotWindowXPosition;
	int plotWindowYPosition;

	//defines location of position graph 
	int PositionXAxisLength;
	int PositionYAxisHeight;

	//defines location of velocity graph
	int VelocityXAxisLength;
	int VelocityYAxisHeight;

	//Margin between border window and position graphs
	int PositionGraphXMargin;
	int PositionGraphYMargin;

	//Margin between border window and velocity graphs 
	int VelocityGraphXMargin;
	int VelocityGraphYMargin;

	
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