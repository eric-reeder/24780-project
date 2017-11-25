#ifndef _PLOTWINDOW_IS_INCLUDED_
#define _PLOTWINDOW_IS_INCLUDED_ 

#include "GraphicsWindow.h"
#include "DynamicSystemApp.h"
#include <vector>

//This class creates the plot window. It inherits information from the Graphics Class. 

class PlotWindow : public GraphicsWindow
{//Public members from the GraphicsWindow class will be available. 

protected: 
	std::vector<double> disp, velocity; //creates variable arrays for the displacement and velocity
	double timeStep; //Time step variable
	double time; //Time variable

public:
	PlotWindow(); //Constructor 
	
	void reset(void); //function to reset window
	void DrawAxes(void); //function to draw axes 
	void GraphPosition(void); //function for drawing position graph
	void LabelPosition(void); //labels position graph
	void GraphVelocity(void); //function for 
	void LabelVelocity(void);
	CleanUp();

	~PlotWindow(); //deconstructor 

};

#endif