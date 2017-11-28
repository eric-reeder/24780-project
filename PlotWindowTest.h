#ifndef PLOTWINDOWTEST_H
#define PLOTWINDOWTEST_H

#include "GraphicsWindow.h"
#include "Mass.h"

class PlotWindowTest : public GraphicsWindow
{
public:
	void reset(void);
	void draw(Mass mass1, Mass mass2, double elapsedTime);
};

#endif
