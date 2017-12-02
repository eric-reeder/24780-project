#include "Spring.h"
#include "fssimplewindow.h"
#include <stdio.h>
#include <math.h>
#include "ysglfontdata.h"



Spring::Spring()
{
    position = 0;
    length = 0;
    stiffness = 0;
    state = true;
    redVal = 0;
    blueVal = 255;
    greenVal = 0;
    lineThickness=10;
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
    double xspring=Visilength/36.5;
    //printf("x %lf",xspring);
    //printf("l %lf",lspring);
    double yspring=sqrt(pow(lspring,2)-pow(xspring,2));
    //printf("y %lf",yspring);
    double x=xl1;
    double yc1=startyPoint;
    double yu1=yc1-yspring;
    double yd1=yc1+yspring;
    
    glColor3ub(redVal, greenVal, blueVal);
    glLineWidth(lineThickness);
    if (state==1)
    {
        glBegin(GL_LINES);
        for (int i=0;i<9;i++)
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
        glEnd();
        int springa=stiffness/100;
        int springb=(stiffness-springa*100)/10;
        int springc=stiffness-springa*100-springb*10;
        double springd=(stiffness-springa*100-springb*10-springc)*10;
        int springe=springd;
        // printf(" spring %d ",springe);
        char YaySpring[10];
        for (int i=0;i<10;i++)
        {
            if (springa==i)
            {
                YaySpring[0]=48+i;
                if (YaySpring[0]==48)
                {
                    YaySpring[0]=32;
                }
            }
        }
        for (int j=0;j<10;j++)
        {
            if (springb==j)
            {
                YaySpring[1]=48+j;
            }
        }
        for (int k=0;k<10;k++)
        {
            if (springc==k)
            {
                YaySpring[2]=48+k;
            }
        }
        for (int l=0;l<10;l++)
        {
            if (springe==l)
            {
                YaySpring[3]=46;
                YaySpring[4]=48+l;
            }
        }
        YaySpring[5]=32;
        YaySpring[6]=78;
        YaySpring[7]=47;
        YaySpring[8]=109;
        YaySpring[9]=0;
        char* d=&YaySpring[0];
        glColor3b(0, 0, 0);
        glRasterPos2d(xl1+Visilength/2-48,yd1+lspring);
        YsGlDrawFontBitmap12x16(d);
    }
    
    
}

 
