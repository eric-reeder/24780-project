//
//  AnimationWindow.h
//  AnimationWindow
//
//  Created by Teresa Kent on 11/20/17.
//  Copyright © 2017 CMU. All rights reserved.
//
#include "DynamicSystemApp.h"

#ifndef AnimationWindow_h
#define AnimationWindow_h

class AnimationWindow: public GraphicsWindow
{
protected:
    // window size values
    double windowx;// total x window size
    double windowy;// total y window size
    // double windowysize;// portion of y window I am allowed
    // double windowxsize;// portion of x window I am allowed
    double WinXStart; // Xstart point in the window
    double WinYStart; // Y start point in the window
    double WallMargin; // distance for walls from edges
    double ThicknessMargin;// walls size
    
    
    // size constant to be changed if the masses are moving too much
    // would be cool to add a ruler after eric does the first compile
    double c;
    
    double YSpring; //height location of the spring
    double YDamper; // height location of the damper
    double YMass; // height location of the center of the mass
    double YForce;// height location of the force arrow
    
    double LeftCenter; // x location of the centerof the wall
    double RightCenter;// x location of the center of the right wall
    double X1Zero; // Starting point for the first mass
    double X2Xero; // Starting point for the second mass
    double X1Actual;// Actual locaton of the first mass
    double X2Actual;// Actual location of the second mass
    
    double spring1len;
    double spring2len;
    double spring3len;
    
    double maxdisplacment;
    
    double x1;
    double x2;
    
    
public:
    
    
    AnimationWindow();
    void draw(int mass1, int mass2, int spring1, int spring2, int spring3, int damper1,
              int damper2, int damper3);
    void SpringDraw(void);
    void DrawDamper(void);
    void DrawMass(void);
    void DrawWalls(void);
    void DrawBorder(void);
    void DrawForce(void);
    
};

#endif /* AnimationWindow_h */
