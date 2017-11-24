#ifndef _PLOTWINDOW_IS_INCLUDED_
#define _PLOTWINDOW_IS_INCLUDED_ 

#include "GraphicsWindow.h"

//This class creates the plot window. It inherits information from the Graphics Class. 

class PlotWindow::public GraphicsWindow
{//Public memebers from the GraphicsWindow class will be available. 

public: 
	void reset(void);
};

#endif