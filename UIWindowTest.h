#ifndef UIWINDOWTEST_H
#define UIWINDOWTEST_H

#include "GraphicsWindow.h"

class UIWindowTest : public GraphicsWindow
{
public:
	void setPosition(int xPosition, int yPosition);
	void setSize(int width, int height);

	double getMass1Mass(void);
	double getMass2Mass(void);

	double getSpring1Stiffness(void);
	double getSpring2Stiffness(void);
	double getSpring3Stiffness(void);

	double getDamper1Damping(void);
	double getDamper2Damping(void);
	double getDamper3Damping(void);

	int getForce1Type(void);
	double getForce1Value1(void);
	double getForce1Value2(void);

	int getForce2Type(void);
	double getForce2Value1(void);
	double getForce2Value2(void);

	bool checkRunning(void);
	bool checkMouse(int mouseLeft, int mouseX, int mouseY);
};

#endif
