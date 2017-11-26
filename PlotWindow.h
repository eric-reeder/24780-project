#ifndef _PLOTWINDOW_IS_INCLUDED_
#define _PLOTWINDOW_IS_INCLUDED_ 

#include "GraphicsWindow.h"
#include "Mass.h"
#include <vector>

//This class creates the plot window. It inherits information from the Graphics Class. 

class PlotWindow : public GraphicsWindow
{//Public members from the GraphicsWindow class will be available. 

protected: 
	std::vector<double> disp, velocity; //creates variable arrays for the displacement and velocity
	double timeStep; //Time step variable
	double time; //Time variable

	int plotWeight;
				 
	//defines width of plot window
	int PlotWindowWidth; 
	int PlotWindowHeight; 

	//sets origin of sub window
	int PlotWindowxPosition;
	int PlotWindowyPosition;
	
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
