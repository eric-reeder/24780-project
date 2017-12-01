#ifndef DYNAMICSYSTEMAPP_H
#define DYNAMICSYSTEMAPP_H

#include "Mass.h"
#include "Spring.h"
#include "Damper.h"
#include "Force.h"
#include "UIWindow.h"
#include "AnimationWindow.h"
#include "PlotWindow.h"
#include "ODESolver.h"

/*  Highest level class in the app, controls overall functionality  */
class DynamicSystemApp
{
protected:
    // App window
    int width;
    int height;
    int margin; // Margin between app window edges and sub-windows, as well as
                // margin between sub-windows

    double uiWindowWidthFraction; // Fraction of app window width
    double uiWindowHeightFraction; // Fraction of app window height
    int uiWindowXPosition; // X coordinate of top left corner
    int uiWindowYPosition; // Y coordinate of top left corner
    int uiWindowWidth;
    int uiWindowHeight;

    double animationWindowWidthFraction;
    double animationWindowHeightFraction;
    int animationWindowXPosition;
    int animationWindowYPosition;
    int animationWindowWidth;
    int animationWindowHeight;

    double plotWindowWidthFraction;
    double plotWindowHeightFraction;
    int plotWindowXPosition;
    int plotWindowYPosition;
    int plotWindowWidth;
    int plotWindowHeight;

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
    const double MILLISEC_TO_SEC = 1.0 / 1000.0;
    const double maxSimTime = 60;
    const int sleepTime = 20;

    // Protected member functions
    void initializeSystemComponents(void);
    void initializeGraphicsWindows(void);
    void initializeSolver(void);
    void initializeApp(void);
    void resetSystem(void);
    void drawApp(void);
    void debugPrint(void);

public:
    DynamicSystemApp(int windowWidth, int windowHeight);
    void run(void);
};

#endif /* DYNAMICSYSTEMAPP_H */
