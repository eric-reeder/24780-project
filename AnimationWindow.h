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

class AnimationWindow
{
protected:
    // window size values
    double windowx;// total x window size
    double windowy;// total y window size
    double windowysize;// portion of y window I am allowed
    double windowxsize;// portion of x window I am allowed
    double WinXStart; // Xstart point in the window
    double WinYStart; // Y start point in the window
    double margin;
    double thickness;
    
    
    // size constant to be changed if the masses are moving too much
    // would be cool to add a ruler after eric does the first compile
    double c;
    
public:
    // states
    int spring1state;
    int spring2state;
    int spring3state;
    int damper1state;
    int damper2state;
    int damper3state;
    int mass1state;
    int mass2state;
    int force1state;
    int force2state;
    
    
    // constants
    double stiffness1;
    double stiffness2;
    double stiffness3;
    
    double dampingConstant1;
    double dampingConstatn2;
    double dampingConstant3;
    
    dynamicSystemApp dsa;
    
    double mass1;
    double mass2;
    
    // location values
    double x1;
    double x2;
    
    // force values
    double force1;
    double force2;
    
    AnimationWindow();
    void draw(int mass1, int mass2, int spring1, int spring2, int spring3, int damper1,
              int damper2, int damper3);
    void SpringDraw(void);
    void DrawDamper(void);
    void DrawMass(void);
    void DrawWalls(void);
    void DrawBorder(void);
    void DrawForce(void);
    void setPosition(double XStart,double YStart);
    void setConstants(void);
    
};

#endif /* AnimationWindow_h */
