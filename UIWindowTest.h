#ifndef UIWINDOWTEST_H
#define UIWINDOWTEST_H

#include "GraphicsWindow.h"

class UIWindowTest : public GraphicsWindow
{
public:
    void Initialize(void);
    
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
    
    bool getDampener1State(void);
    bool getDampener2State(void);
    bool getDampener3State(void);

	int getForce1Type(void);
	double getForce1Value1(void);
	double getForce1Value2(void);

	int getForce2Type(void);
	double getForce2Value1(void);
	double getForce2Value2(void);

	bool checkRunning(void);
	bool checkMouse();
};

#endif
