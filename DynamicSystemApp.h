#include "Mass.h"
#include "Spring.h"
#include "Damper.h"
#include "Force.h"
#include "UIWindow.h"
#include "AnimationWindow.h"
#include "PlotWindow.h"
#include "ODESolver.h"

#ifndef DYNAMICSYSTEMAPP_H
#define DYNAMICSYSTEMAPP_H

/*  Highest level class in the app, controls overall functionality  */
class dynamicSystemApp
{
protected:
    // App window
    int width;
    int height;

    double uiWindowWidthFraction; // Fraction of app window width
    double uiWindowHeightFraction; // Fraction of app window height
    int uiWindowXPosition; // X coordinate of top left corner
    int uiWindowYPosition; // Y coordinate of top left corner

    double animationWindowWidthFraction;
    double animationWindowHeightFraction;
    int animationWindowXPosition;
    int animationWindowYPosition;

    double plotWindowWidthFraction;
    double plotWindowHeightFraction;
    int plotWindowXPosition;
    int plotWindowYPosition;

    // Dynamic system components
    Mass mass1;
    Mass mass2;
    Spring spring1;
    Spring spring2;
    Spring spring3;
    Damper damper1;
    Damper damper2;
    Damper damper3;
    Force force1;
    Force force2;

    // Graphics components
    UIWindow uiWindow;
    AnimationWindow animationWindow;
    PlotWindow plotWindow;
    ODESolver solver;

    // Mouse
    int mouseLeft;
    int mouseRight;
    int mouseMiddle;
    int mouseX;
    int mouseY;

    // Time
    double timeStep;
    double elapsedTime = 0.0;
    const double MILLISEC_TO_SEC = 1 / 1000.0;
    const double maxSimTime = 60;
    const int sleepTime = 20;

    // Protected member functions
    void initializeApp(void);
    void drawApp(void) const;

public:
    dynamicSystemApp();
    dynamicSystemApp(int windowWidth, int windowHeight);
    void run(void);
};

#endif /* DYNAMICSYSTEMAPP_H */
