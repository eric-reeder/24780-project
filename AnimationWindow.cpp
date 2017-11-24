#include "AnimationWindow.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "fssimplewindow.h"

// The x values need to be set by the main function everything else should work for itself
// Oh and the state values should be set for each of them

AnimationWindow::AnimationWindow()
{
    c=1;
    
    force1=0;
    force2=0;
    x1=0;// center position of mass 1
    x2=0;// center position of mass2
    
    spring1state=0;
    spring2state=0;
    spring3state=0;
    
    stiffness1=0;
    stiffness2=0;
    stiffness3=0;
    
    dampingConstant1=0;
    dampingConstatn2=0;
    dampingConstant3=0;
    
    damper1state=0;
    damper2state=0;
    damper3state=0;
    
    mass1=0;
    mass2=0;
    
    mass1state=0;
    mass2state=0;
    
    force1state=0;
    force2state=0;
    
    
    windowx=0;// total x window size
    windowy=0;// total y window size
    // windowysize=0;// portion of y window I am allowed
    // windowxsize=0;// portion of x window I am allowed
    WinXStart=0; // Xstart point in the window
    WinYStart=0; // Y start point in the window
    // These variables are not being passed from the inital function so are hard coded to values.  May want to improve it later.  The thickness controls the wall thicknesses.  The margin controls the distance from the xstart point to the walls
    margin=5;
    thickness=5;
}
// ERIC THIS WILL POP AN ERROR I NEED MORE INFO FOR MY PROJECT WHAT IT IS ASKING FOR IS NOT SENT
void AnimationWindow::WindowInfo(void)
{
    WinXStart=XStart;
    WinYStart=YStart;
    windowx=WindowWidth;
    windowy=WindowHeight;
}

double AnimationWindow::getLocations(void) const
{
    return x1;
    return x2;
}


void AnimationWindow::setLocations(const double Newx1,double Newx2)
{
    x1=Newx1;
    x2=Newx2;
    if (x1>maxdisplacment)
    {
        x1=maxdisplacment;
    }
    else
    {
        x1=x1;
    }
    if (x2>maxdisplacment)
    {
        x2=maxdisplacment
    }
    else
    {
        x2=x2;
    }
}
double AnimationWindow:: SetZeros(void) const
{
    LeftCenter=WinXStart+margin+thickness/2;
    RightCenter=windowx-margin-thickness;
    Spacing=(windowx-WinXStart)/3;
    X1Zero=WinXStart+Spacing;
    X2Xero=WinXStart+2*Spacing;
    X1Actual=X1Zero+x1;
    X2Actual=X2Xero+x2+x1;
    YSpring=windowy/4+windowy/35;
    YDamper=windowy/4-windowy/35;
    YMass=windowy/4;
    YForce=windowy/4-windowy/15;
}
void AnimationWindow::setConstants(void)
{
    spring1len=X1Actual-LeftCenter;
    spring2len=X2Actual-X1Actual;
    spring3len=RightCenter-X2Actual;
    
    spring1.setLength(spring1len);
    spring2.setLength(spring2len);
    spring3.setLength(spring3len);
    damper1.setLength(spring1len);
    damper2.setLength(spring2len);
    damper3.setLength(spring2len);
    
    force1state=newforce1state;
    force2state=newforce2state;
    mass1state=newmass1state;
    mass2state=NewMass2State;
    force2=NewForce2;
    force1=NewForce1;
}

void AnimationWindow::DrawWalls()
{
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(LeftCenter+margin-thickness/2,margin);
    glVertex2f(LeftCenter+margin-thickness/2,windowy/2-margin);
    glVertex2f(LeftCenter+margin+thickness/2,windowy/2-margin);
    glVertex2f(LeftCenter+margin+thickness/2,margin);
    
    glVertex2f(RightCenter-margin-thickness/2,margin);
    glVertex2f(RightCenter-margin-thickness/2,windowy/2-margin);
    glVertex2f(RightCenter-margin+thickness/2,windowy/2-margin);
    glVertex2f(RightCenter-margin+thickness/2,margin);
    glEnd();
    
    
}
/* This function draws a border which I think is a good idea to have so theres a clear divide between the windows however I will leave this at erics discretion
 note if you want this in the function I may have deleted a few perameters but I can add them back in later
 
 void AnimationWindow::DrawBorder()
{
    double cx1=WinXStart+margin;
    double cx2=windowx-margin;
    double cx3=cx2-thickness;
    double cx4=cx1+thickness;
    double cy1=margin;
    double cy2=windowy*windowysize-margin;
    double cy3=cy2-thickness;
    double cy4=cy1+thickness;
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    
    glVertex2d(cx1,cy1);
    glVertex2d(cx2,cy1);
    glVertex2d(cx2,cy4);
    glVertex2d(cx1,cy4);
    
    glVertex2d(cx3,cy1);
    glVertex2d(cx2,cy1);
    glVertex2d(cx2,cy2);
    glVertex2d(cx3,cy2);
    
    glVertex2d(cx1,cy2);
    glVertex2d(cx2,cy2);
    glVertex2d(cx2,cy3);
    glVertex2d(cx1,cy3);
    
    
    glVertex2d(cx4,cy1);
    glVertex2d(cx1,cy1);
    glVertex2d(cx1,cy2);
    glVertex2d(cx4,cy2);
    
    glEnd();
    
}
 */
/* How do you want me to do the forcing function? With the sine changes or the other things
 void AnimationWindow::DrawForce()
{
    glColor3ub(0,0,0);
    double lengthsize=windowx*.05;
    double Wx=1-windowxsize;
    double SpacingX=windowxsize*windowx/3;
    double xc1=windowx*Wx+x1*c+SpacingX;
    double xc2=windowx*Wx+x2+2*SpacingX;
    double yc=windowy*windowysize/2;
    double yt=yc-windowy/15;
    if (force1state==1)
    {
        if (force1<0)
        {
            glBegin(GL_LINES);
            glVertex2d(xc1, yt);
            glVertex2d(xc1-lengthsize, yt);
            glEnd();
            
            glBegin(GL_TRIANGLES);
            glVertex2d(xc1-lengthsize, yt+.01*windowy);
            glVertex2d(xc1-lengthsize, yt-.01*windowy);
            glVertex2d(xc1-3*lengthsize/2, yt);
            
        }
        else
        {
            glBegin(GL_LINES);
            glVertex2d(xc1, yt);
            glVertex2d(xc1+lengthsize, yt);
            glEnd();
            
            glBegin(GL_TRIANGLES);
            glVertex2d(xc1+lengthsize, yt+.01*windowy);
            glVertex2d(xc1+lengthsize, yt-.01*windowy);
            glVertex2d(xc1+lengthsize+lengthsize/3, yt);
            
        }
        
    }
    if (force2state==1)
    {
        if (force2<0)
        {
            glBegin(GL_LINES);
            glVertex2d(xc2, yt);
            glVertex2d(xc2-lengthsize, yt);
            glEnd();
            
            glBegin(GL_TRIANGLES);
            glVertex2d(xc2-lengthsize, yt+.01*windowy);
            glVertex2d(xc2-lengthsize, yt-.01*windowy);
            glVertex2d(xc2-3*lengthsize/2, yt);
            
        }
        else
        {
            glBegin(GL_LINES);
            glVertex2d(xc2, yt);
            glVertex2d(xc2+lengthsize, yt);
            glEnd();
            
            glBegin(GL_TRIANGLES);
            glVertex2d(xc2+lengthsize, yt+.01*windowy);
            glVertex2d(xc2+lengthsize, yt-.01*windowy);
            glVertex2d(xc2+lengthsize+lengthsize/3, yt);
            
        }
        
    }
    
    glEnd();
}
 */
void AnimationWindow::draw(int mass1, int mass2, int spring1, int spring2, int spring3, int damper1,
                           int damper2, int damper3)
{
    AnimationWindow.SetZeros();
    AnimationWindow.setConstants();
    spring1.draw(LeftCenter,YSpring,spring1len);
    spring2.draw(X1Actual,YSpring,spring2len);
    spring3.draw(X2Actual,YSpring,spring3len);
    damper1.draw(LeftCenter,YDamper,spring1len,windowy);
    damper2.draw(X1Actual,YDamper,spring2len,windowy);
    damper3.draw(X2Actual,YDamper,spring3len,windowy);
    mass1.draw(X1Actual, YMass) const;
    mass2.draw(X2Actual, YMass) const;
    DrawWalls();
    // DrawForce();
    
    
}
