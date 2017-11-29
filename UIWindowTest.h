#ifndef UIWINDOWTEST_H
#define UIWINDOWTEST_H

#include "GraphicsWindow.h"

class UIWindowTest : public GraphicsWindow
{
public:
	double getMass1Mass(void);
	double getMass2Mass(void);
    
    bool getMass1State(void);
    bool getMass2State(void);

	double getSpring1Stiffness(void);
	double getSpring2Stiffness(void);
	double getSpring3Stiffness(void);
    
    bool getSpring1State(void);
    bool getSpring2State(void);
    bool getSpring3State(void);

	double getDamper1Damping(void);
	double getDamper2Damping(void);
	double getDamper3Damping(void);
    
    bool getDamper1State(void);
    bool getDamper2State(void);
    bool getDamper3State(void);

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
