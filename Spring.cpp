#include "Spring.h"
#include "fssimplewindow.h"
#include <stdio.h>
#include <math.h>


Spring::Spring()
{
    position = 0;
    length = 0;
    stiffness = 0;
    state = true;
    redVal = 0;
    blueVal = 255;
    greenVal = 0;
    lineThickness=2;
}


double Spring::getStiffness(void) const
{
    return stiffness;
}


void Spring::setStiffness(const double newStiffness)
{
    stiffness = newStiffness;
}


double Spring::getLength(void) const
{
    return length;
}

/* Hey eric which class sets this length?  I have the equations to do it I just dont quite know where to put them.  Alternativly we could import the x position or the change in length just lmk this is like 7 seconds */
void Spring::setLength(const double newLength)
{
    length = newLength;
}

void Spring::setVisualLength(const double VisLeng)
{
    Visilength = VisLeng;
}


void Spring:: draw(double startxPoint,double startyPoint,double lspring) const
{
    double xl1=startxPoint;
    //printf("v %lf",Visilength);
    double xspring=Visilength/20;
    //printf("x %lf",xspring);
    //printf("l %lf",lspring);
    double yspring=sqrt(pow(lspring,2)-pow(xspring,2));
    //printf("y %lf",yspring);
    double x=xl1;
    double yc1=startyPoint;
    double yu1=yc1-yspring;
    double yd1=yc1+yspring;
    
    glColor3ub(redVal, greenVal, blueVal);
    glBegin(GL_LINES);
    glLineWidth(lineThickness);
    if (state==1)
    {
        for (int i=0;i<5;i++)
        {
            glVertex2d(x,yc1);
            x=x+xspring;
            // printf(" %lf ",x);
            glVertex2d(x,yu1);
            glVertex2d(x,yu1);
            x=x+xspring;
            // printf(" %lf ",x);
            glVertex2d(x,yc1);
            glVertex2d(x,yc1);
            x=x+xspring;
            // printf(" %lf ",x);
            glVertex2d(x,yd1);
            glVertex2d(x,yd1);
            x=x+xspring;
            // printf(" %lf ",x);
            glVertex2d(x,yc1);
        }
        
    }
    
    
    glEnd();
}

 