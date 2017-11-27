#include "DynamicSystemApp.h"
#include "Mass.h"
#include "Spring.h"
#include "Damper.h"
#include "Force.h"
#include "UIWindowTest.h"
#include "AnimationWindowTest.h"
#include "PlotWindow.h"
#include "ODESolver.h"
#include "fssimplewindow.h"
#include <chrono>
#include <iostream>

/*  Creates app object and sets values for app window width and height
    Inputs:
    windowWidth - width of app window in pixels
    windowHeight - height of app window in pixels  */
DynamicSystemApp::DynamicSystemApp(int windowWidth, int windowHeight)
{
    width = windowWidth;
    height = windowHeight;
    margin = 10;

    // Set position and size of UI Window
    uiWindowWidthFraction = 0.3;
    uiWindowHeightFraction = 1.0;
    uiWindowXPosition = margin;
    uiWindowYPosition = margin;
    uiWindowWidth = (int)((double)windowWidth * uiWindowWidthFraction) -
    2 * margin;
    uiWindowHeight = (int)((double)windowHeight * uiWindowHeightFraction) -
    2 * margin;
    

    // Set position and size of animation window
    animationWindowWidthFraction = 0.7;
    animationWindowHeightFraction = 0.5;
    animationWindowXPosition = (int)((1.0 - animationWindowWidthFraction) 
        * (double)width) + margin;
    animationWindowYPosition = margin;
    animationWindowWidth = (int)((double)windowWidth * 
        animationWindowWidthFraction) - 2 * margin;
    animationWindowHeight = (int)((double)windowHeight * 
        animationWindowHeightFraction) - 2 * margin;


    // Set position and size of plot window
    plotWindowWidthFraction = 0.7;
    plotWindowHeightFraction = 0.5;
    plotWindowXPosition = (int)((1.0 - plotWindowWidthFraction) * 
        (double)width) + margin;
    plotWindowYPosition = (int)((1.0 - plotWindowHeightFraction) *
        (double)height) + margin;
    plotWindowWidth = (int)((double)windowWidth * plotWindowWidthFraction) -
        2 * margin;
    plotWindowHeight = (int)((double)windowHeight * plotWindowHeightFraction) -
        2 * margin;
}

/*  Sets relevant values of masses, springs, and dampers based on values
    of input sliders  */
void DynamicSystemApp::initializeSystemComponents(void)
{
    // Set simulation object values
    mass1.setMass(uiWindow.getMass1Mass());
    mass2.setMass(uiWindow.getMass2Mass());

    spring1.setStiffness(uiWindow.getSpring1Stiffness());
    spring1.setLength(mass1.getPosition());

    spring2.setStiffness(uiWindow.getSpring2Stiffness());
    spring2.setLength(mass2.getPosition() - mass1.getPosition());

    spring3.setStiffness(uiWindow.getSpring3Stiffness());
    spring3.setLength(mass2.getPosition());

    damper1.setDamping(uiWindow.getDamper1Damping());
    damper1.setLength(spring1.getLength());
    damper1.setVelocity(mass1.getVelocity());

    damper2.setDamping(uiWindow.getDamper2Damping());
    damper2.setLength(spring2.getLength());
    damper2.setVelocity(mass2.getVelocity() - mass1.getVelocity());

    damper3.setDamping(uiWindow.getDamper3Damping());
    damper3.setLength(spring3.getLength());
    damper3.setVelocity(-mass2.getVelocity());

    force1.setType(uiWindow.getForce1Type());
    force1.setValue(uiWindow.getForce1Value1(), uiWindow.getForce1Value2());
    force2.setType(uiWindow.getForce2Type());
    force2.setValue(uiWindow.getForce2Value1(), uiWindow.getForce2Value2());
}

/*  Sets positions and sizes of sub-windows  */
void DynamicSystemApp::initializeGraphicsWindows(void)
{
    // Set position and size of sub-windows
    uiWindow.setPosition(uiWindowXPosition, uiWindowYPosition);
    uiWindow.setSize(uiWindowWidth, uiWindowHeight);
    animationWindow.setPosition(animationWindowXPosition, animationWindowYPosition);
    animationWindow.setSize(animationWindowWidth, animationWindowHeight);
    plotWindow.setPosition(plotWindowXPosition, plotWindowYPosition);
    plotWindow.setSize(plotWindowWidth, plotWindowHeight);
}

/*  Sends mass, spring, damper, and force values to those contained in objects  */
void DynamicSystemApp::initializeSolver(void)
{
    // Initialize ODE solver parameters
    solver.massInit(mass1, mass1);
    solver.springInit(spring1, spring2, spring3);
    solver.damperInit(damper1, damper2, damper3);
    solver.forceInit(force1, force2);
}

/*  Initializes all app components  */
void DynamicSystemApp::initializeApp(void)
{
    initializeSystemComponents();
    initializeGraphicsWindows();
    initializeSolver();
}

/*  Resets positions and velocities of all simulation objects to zero and clears
    the plot window.  */
void DynamicSystemApp::resetSystem(void)
{
    elapsedTime = 0.0;
    mass1.setPosition(0.0);
    mass1.setVelocity(0.0);
    mass2.setPosition(0.0);
    mass2.setVelocity(0.0);
    spring1.setLength(0.0);
    spring2.setLength(0.0);
    spring3.setLength(0.0);
    damper1.setLength(0.0);
    damper1.setVelocity(0.0);
    damper2.setLength(0.0);
    damper2.setVelocity(0.0);
    damper3.setLength(0.0);
    damper3.setVelocity(0.0);
    plotWindow.reset();
}

/*  Draws all components of the App (sliders/UI window, animation, and plots)  */
void DynamicSystemApp::drawApp(void)
{    
    uiWindow.draw();
    animationWindow.draw(mass1, mass2, spring1, spring2, spring3, damper1, damper2, damper3);
    plotWindow.draw(mass1, mass2, elapsedTime);
}

/*  Runs app until user presses escape key  */
void DynamicSystemApp::run(void)
{
    initializeApp();

    // Start timer (this value is temporary and won't be used after first iteration)
    std::chrono::steady_clock::time_point last = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point current = std::chrono::steady_clock::now();

    // Create app window and run animation
    FsOpenWindow(16, 16, width, height, 1);
    int key = FSKEY_NULL;
    while(key != FSKEY_ESC)
    {
        FsPollDevice();
        FsGetMouseEvent(mouseLeft, mouseMiddle, mouseRight, mouseX, mouseY);
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        // Measure time since last iteration
        last = current;
        current = std::chrono::steady_clock::now();

        // If the animation is running, update positions of masses, or stop 
        // animation if max sim time is exceeded
        if (uiWindow.checkRunning() == true)
        {
            if (elapsedTime <= maxSimTime)
            {
                timeStep = std::chrono::duration_cast<std::chrono::milliseconds>(current - last).count() * MILLISEC_TO_SEC;
                solver.solve(timeStep, mass1, mass2);
                elapsedTime += timeStep;
            }
        }

        bool resetPress = uiWindow.checkMouse(mouseLeft, mouseX, mouseY);
        initializeSystemComponents();
        initializeSolver();
        if (resetPress == true)
        {
            resetSystem();
        }

        drawApp();
        FsSwapBuffers();
        FsSleep(sleepTime);
    }
}
