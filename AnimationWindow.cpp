#include "AnimationWindow.h"
#include "Spring.h"
#include "Damper.h"
#include "Mass.h"
#include "GraphicsWindow.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "fssimplewindow.h"
#include "AnimationWindow.h"

// The x values need to be set by the main function everything else should work for itself
// Oh and the state values should be set for each of them

AnimationWindow::AnimationWindow()
{
    c=1;
    // c is the variable so if we wanted to up the animations responsiveness to position change or downgrade the animations response to position change we could
    
    // These variables are not being passed from the inital function so are hard coded to values.  May want to improve it later.  The thickness controls the wall thicknesses.  The margin controls the distance from the xstart point to the walls
    WallMargin=5;
    ThicknessMargin=10;
    //Max displacemnt prevents the object from going off screne
    maxdisplacment=30;
    mindisplacment=-30;
    springHeight=25;
}
double AnimationWindow::getLocations(void) const
{
    return x1;
    return x2;
}
// Brings Mass1 and Mass2s position into the animation window

// prevents the object from going offscrene
void AnimationWindow::setLocations(Mass mass1, Mass mass2)
{
    
    /*int i;
    i=i+1;
    i=i%10;
    if (i>5)
    {
        x1=x1+.1;
        x2=x2+.2;
    }
    else
    {
        x1=x1-.1;
        x2=x2-.2;
    }
    printf(" i %lf ",i);
    */
    x1=mass1.Weee();
    x2=mass2.Weee();
    if (x1>maxdisplacment)
    {
        x1=maxdisplacment;
    }
    else if(x1<mindisplacment)
    {
        x1=mindisplacment;
    }
    else
    {
        x1=x1;
    }
    if (x2>maxdisplacment)
    {
        x2=maxdisplacment;
    }
    else if(x2<mindisplacment)
    {
        x2=mindisplacment;
    }
    else
    {
        x2=x2;
    }
}
void AnimationWindow:: SetZeros(void)
{
    LeftCenter=xPosition+WallMargin+ThicknessMargin/2;
    RightCenter=xPosition+width-WallMargin-ThicknessMargin;
    Spacing=(width)/3;
    X1Zero=xPosition+Spacing;
    X2Xero=xPosition+2*Spacing;
    X1Actual=X1Zero+x1;
    X2Actual=X2Xero+x2+x1;
    YSpring=height/2+height/20;
    YDamper=height/2-height/10;
    YMass=height/2;
    YForce=height/2-height/15;
    if (X1Actual+50>X2Actual)
    {
        X1Actual=X2Actual-50;
    }
}

//Walls spring mass damper is conected to
void AnimationWindow::DrawWalls()
{
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(LeftCenter+WallMargin-ThicknessMargin/2,yPosition+WallMargin);
    glVertex2f(LeftCenter+WallMargin-ThicknessMargin/2,height-WallMargin);
    glVertex2f(LeftCenter+WallMargin+ThicknessMargin/2,height-WallMargin);
    glVertex2f(LeftCenter+WallMargin+ThicknessMargin/2,yPosition+WallMargin);
    
    glVertex2f(RightCenter-WallMargin-ThicknessMargin/2,yPosition+WallMargin);
    glVertex2f(RightCenter-WallMargin-ThicknessMargin/2,height-WallMargin);
    glVertex2f(RightCenter-WallMargin+ThicknessMargin/2,height-WallMargin);
    glVertex2f(RightCenter-WallMargin+ThicknessMargin/2,yPosition+WallMargin);
    glEnd();
    
    
}
/* This function draws a border which I think is a good idea to have so theres a clear divide between the windows however I will leave this at erics discretion
 note if you want this in the function I may have deleted a few perameters but I can add them back in later
 
 void AnimationWindow::DrawBorder()
 {
 double cx1=XPosition+margin;
 double cx2=width-margin;
 double cx3=cx2-thickness;
 double cx4=cx1+thickness;
 double cy1=margin;
 double cy2=height*heightsize-margin;
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
 double lengthsize=width*.05;
 double Wx=1-widthsize;
 double SpacingX=widthsize*width/3;
 double xc1=width*Wx+x1*c+SpacingX;
 double xc2=width*Wx+x2+2*SpacingX;
 double yc=height*heightsize/2;
 double yt=yc-height/15;
 if (force1state==1)
 {
 if (force1<0)
 {
 glBegin(GL_LINES);
 glVertex2d(xc1, yt);
 glVertex2d(xc1-lengthsize, yt);
 glEnd();
 
 glBegin(GL_TRIANGLES);
 glVertex2d(xc1-lengthsize, yt+.01*height);
 glVertex2d(xc1-lengthsize, yt-.01*height);
 glVertex2d(xc1-3*lengthsize/2, yt);
 
 }
 else
 {
 glBegin(GL_LINES);
 glVertex2d(xc1, yt);
 glVertex2d(xc1+lengthsize, yt);
 glEnd();
 
 glBegin(GL_TRIANGLES);
 glVertex2d(xc1+lengthsize, yt+.01*height);
 glVertex2d(xc1+lengthsize, yt-.01*height);
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
 glVertex2d(xc2-lengthsize, yt+.01*height);
 glVertex2d(xc2-lengthsize, yt-.01*height);
 glVertex2d(xc2-3*lengthsize/2, yt);
 
 }
 else
 {
 glBegin(GL_LINES);
 glVertex2d(xc2, yt);
 glVertex2d(xc2+lengthsize, yt);
 glEnd();
 
 glBegin(GL_TRIANGLES);
 glVertex2d(xc2+lengthsize, yt+.01*height);
 glVertex2d(xc2+lengthsize, yt-.01*height);
 glVertex2d(xc2+lengthsize+lengthsize/3, yt);
 
 }
 
 }
 
 glEnd();
 }
 */
void AnimationWindow::draw(Mass mass1, Mass mass2, Spring spring1, Spring spring2, Spring spring3, Damper damper1, Damper damper2, Damper damper3)
{
    //printf("%lf %lf",x1,x2);
    drawBackground();
    drawBorder();
    setLocations(mass1, mass2);
    spring1len=X1Actual-LeftCenter+ThicknessMargin/2;
    spring2len=X2Actual-X1Actual;
    spring3len=RightCenter-X2Actual-ThicknessMargin/4;
    

    spring1.setVisualLength(spring1len);
    spring2.setVisualLength(spring2len);
    spring3.setVisualLength(spring3len);
    damper1.setVisiLength(spring1len);
    damper2.setVisiLength(spring2len);
    damper3.setVisiLength(spring3len);
    
    SetZeros();
    
    spring1.draw(LeftCenter,YSpring,springHeight);
    spring2.draw(X1Actual,YSpring,springHeight);
    spring3.draw(X2Actual,YSpring,springHeight);
    
    damper1.draw(LeftCenter,YDamper,spring1len,height);
    damper2.draw(X1Actual,YDamper,spring2len,height);
    damper3.draw(X2Actual,YDamper,spring3len,height);
    
    mass1.draw(X1Actual, YMass);
    mass2.draw(X2Actual, YMass);
    DrawWalls();
    
    
}


