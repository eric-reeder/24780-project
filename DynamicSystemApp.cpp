#include "DynamicSystemApp.h"
#include "Mass.h"
#include "Spring.h"
#include "Damper.h"
#include "Force.h"
#include "UIWindow.h"
#include "AnimationWindow.h"
#include "PlotWindow.h"
#include "ODESolver.h"
#include "fssimplewindow.h"
#include <chrono>

// Creates app object and sets values for app window width and height
// Inputs:
// windowWidth - width of app window in pixels
// windowHeight - height of app window in pixels
DynamicSystemApp::DynamicSystemApp(int windowWidth, int windowHeight)
{
    width = windowWidth;
    height = windowHeight;
}


void initializeSimulationObjects(void)
{
    mass1.setMass(uiWindow);
    mass2.setMass(uiWindow);
    spring1.setStiffness(uiWindow);
    spring2.setStiffness(uiWindow);
    spring3.setStiffness(uiWindow);
    damper1.setDamping(uiWindow);
    damper2.setDamping(uiWindow);
    damper3.setDamping(uiWindow);
    force1.setForce(uiWindow);
    force2.setForce(uiWindow);
}


void resetSystem(void)
{
    elapsedTime = 0.0;
    mass1.setPosition(0.0);
    mass1.setVelocity(0.0);
    mass2.setPosition(0.0);
    mass2.setVelocity(0.0);
    spring1.setLength(0.0);
    spring2.setLength(0.0);
    spring3.setLength(0.0);
    damper1.setVelocity(0.0);
    damper2.setVelocity(0.0);
    damper3.setVelocity(0.0);
    plotWindow.reset();
}


void drawApp(void)
{
    uiWindow.draw();
    animationWindow.draw(mass1, mass2, spring1, spring2, spring3, damper1, 
        damper2, damper3);
    plotWindow.draw(mass1, mass2, elapsedTime);
}


// Runs app until user presses the esc key
void dynamicSystemApp::run(void)
{
    // Set mass, spring, and damper values based on sliders
    initializeSimulationObjects();

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
        // animation if max sim 
        // time is exceeded
        if (uiWindow.checkRunning() == true)
        {
            if (elapsedTime <= MAX_SIM_TIME)
            {
                timeStep = std::chrono::duration_cast<std::chrono::milliseconds>(current - last).count() * MILLISEC_TO_SEC;
                // The solve function should use call by reference to modify the 
                // parameters of the simulation objects
                solver.solve(mass1, mass2, spring1, spring2, spring3, damper1, 
                    damper2, damper3, force1, force2, timeStep);
                elapsedTime += timeStep;
            }
        }

        bool resetPress = uiWindow.checkMouse(mouseLeft, mouseX, mouseY);
        if (resetPress == true)
        {
            resetSystem();
        }

        drawApp();
        FsSwapBuffers();
        FsSleep(SLEEP_TIME);
    }
}
