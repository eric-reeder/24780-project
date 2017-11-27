#ifndef _PLOTWINDOW_IS_INCLUDED_
#define _PLOTWINDOW_IS_INCLUDED_ 

#include "GraphicsWindow.h"
#include "Mass.h"
#include <vector>

//This class creates the plot window. It inherits information from the Graphics Class. 

class PlotWindow : public GraphicsWindow
{//Public members from the GraphicsWindow class will be available. 

protected:
	double time; //Time variable

	//Starting variables for graph
	double initialtime; 
	double initialposition; 
	double initialvelocity; 

	double velocity; 
	double position; 

	
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

	//colors for graphs 
	int graphRed;
	int graphGreen; 
	int graphBlue; 

public:
	PlotWindow(); //Initalizes plot window

	void DrawPositionAxes(void); //function to draw axes 
	void DrawVelocityAxes(void);
	void GraphPosition(void); //function for drawing position graph
	void GraphVelocity(void);
	void reset(void);
	void draw(Mass mass1, Mass mass2, double timeStep);
};

#endif