#include "AnimationWindow.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "fssimplewindow.h"

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
    windowysize=0;// portion of y window I am allowed
    windowxsize=0;// portion of x window I am allowed
    WinXStart=0; // Xstart point in the window
    WinYStart=0; // Y start point in the window
    margin=0;
    thickness=0;
}
// ERIC THIS WILL POP AN ERROR I NEED MORE INFO FOR MY PROJECT WHAT IT IS ASKING FOR IS NOT SENT
void AnimationWindow::setPosition(double XStart,double YStart)
{
    WinXStart=XStart;
    WinYStart=YStart;
    windowxsize=dsa.animationWindowWidthFraction;
    windowysize=dsa.animationWindowHeightFraction;
    windowx=dsa.width;
    windowy=dsa.height;
    margin=dsa.margin;
    thickness=margin*5;
}
void AnimationWindow::setConstants(void)
{
    force1state=newforce1state;
    force2state=newforce2state;
    mass1state=newmass1state;
    mass2state=NewMass2State;
    damper1state=NewDamper1;
    damper2state=NewDamper2;
    damper3state=NewDamper3;
    spring1state=NewSpring1;
    spring2state=NewSpring2;
    spring3state=NewSpring3;
    force2=NewForce2;
    force1=NewForce1;
}
void AnimationWindow::SpringDraw(void)
{
    {
        // A few constants non spring dependent
        double Wx=1-windowxsize;
        double SpacingX=windowxsize*windowx/3;
        float linethickness=10;
        double lspring=windowx*windowy/50000;
        
        double xl1=WinXStart+3*margin+2*thickness;
        double xc1=windowx*Wx+x1*c+SpacingX;
        double xdist=xc1-xl1;
        double xspring=xdist/20;
        double yspring=sqrt(pow(lspring,2)-pow(xspring,2));
        double x=xl1;
        double yc1=windowy*windowysize*windowysize+windowy/40;
        double yu1=yc1-yspring;
        double yd1=yc1+yspring;
        
        double xl2=windowx*Wx+x1*c+SpacingX;
        double xr2=windowx*Wx+x2+2*SpacingX;
        double xdist2=xr2-xl2;
        double xspring2=xdist2/20;
        double yspring2=sqrt(pow(lspring,2)-pow(xspring2,2));
        double x2a=xl2;
        double yc2=windowy*windowysize*windowysize+windowy/40;
        double yu2=yc1-yspring2;
        double yd2=yc1+yspring2;
        
        double xl3=windowx*Wx+x2+2*SpacingX;
        double xr3=windowx-3*margin-2*thickness;
        double xdist3=xr3-xl3;
        double xspring3=xdist3/20;;
        double yspring3=sqrt(pow(lspring,2)-pow(xspring3,2));
        double x3a=xl3;
        double yc3=windowy*windowysize*windowysize+windowy/40;
        double yu3=yc1-yspring3;
        double yd3=yc1+yspring3;
        
        glBegin(GL_LINES);
        glLineWidth(linethickness);
        if (spring1state==1)
        {
            for (int i=0;i<5;i++)
            {
                glVertex2d(x,yc1);
                x=x+xspring;
                glVertex2d(x,yu1);
                glVertex2d(x,yu1);
                x=x+xspring;
                glVertex2d(x,yc1);
                glVertex2d(x,yc1);
                x=x+xspring;
                glVertex2d(x,yd1);
                glVertex2d(x,yd1);
                x=x+xspring;
                glVertex2d(x,yc1);
            }
        }
        if (spring2state==1)
        {
            for (int i=0;i<5;i++)
            {
                glVertex2d(x2a,yc2);
                x2a=x2a+xspring2;
                glVertex2d(x2a,yu2);
                glVertex2d(x2a,yu2);
                x2a=x2a+xspring2;
                glVertex2d(x2a,yc2);
                glVertex2d(x2a,yc2);
                x2a=x2a+xspring2;
                glVertex2d(x2a,yd2);
                glVertex2d(x2a,yd2);
                x2a=x2a+xspring2;
                glVertex2d(x2a,yc2);
            }
        }
        
        if (spring3state==1)
        {
            for (int i=0;i<5;i++)
            {
                glVertex2d(x3a,yc3);
                x3a=x3a+xspring3;
                glVertex2d(x3a,yu3);
                glVertex2d(x3a,yu3);
                x3a=x3a+xspring3;
                glVertex2d(x3a,yc3);
                glVertex2d(x3a,yc3);
                x3a=x3a+xspring3;
                glVertex2d(x3a,yd3);
                glVertex2d(x3a,yd3);
                x3a=x3a+xspring3;
                glVertex2d(x3a,yc3);
            }
        }
        
        glEnd();
    }
}
void AnimationWindow::DrawMass()
{
    glColor3ub(200,0,0);
    glBegin(GL_QUADS);
    
    double yc=windowy*windowysize/2;
    double yt=yc-windowy/10;
    double yb=yc+windowy/20;
    double Wx=1-windowxsize;
    double SpacingX=windowxsize*windowx/3;
    if (mass1state==1)
    {
        double xc1=windowx*Wx+x1*c+SpacingX;
        double xl1=xc1-windowx/25;
        double xr1=xc1+windowx/25;
        glVertex2f(xl1,yt);
        glVertex2f(xl1,yb);
        glVertex2f(xr1,yb);
        glVertex2f(xr1,yt);
    }
    if (mass2state==1)
    {
        double xc2=windowx*Wx+x2+2*SpacingX;
        double xl2=xc2-windowx/25;
        double xr2=xc2+windowx/25;
        
        glVertex2f(xl2,yt);
        glVertex2f(xl2,yb);
        glVertex2f(xr2,yb);
        glVertex2f(xr2,yt);
    }
    glEnd();
}
void AnimationWindow::DrawWalls()
{
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(WinXStart+3*margin+thickness,3*margin+thickness);
    glVertex2f(WinXStart+3*margin+thickness,windowy*windowysize-3*margin-thickness);
    glVertex2f(WinXStart+3*margin+6*thickness,windowy*windowysize-3*margin-thickness);
    glVertex2f(WinXStart+3*margin+6*thickness,3*margin+thickness);
    
    glVertex2f(windowx-3*margin-thickness,3*margin+thickness);
    glVertex2f(windowx-3*margin-thickness,windowy*windowysize-3*margin-thickness);
    glVertex2f(windowx-3*margin-6*thickness,windowy*windowysize-3*margin-thickness);
    glVertex2f(windowx-3*margin-6*thickness,3*margin+thickness);
    glEnd();
    
    
}
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
void AnimationWindow::DrawDamper(void)
{
    {
        double Wx=1-windowxsize;
        double SpacingX=windowxsize*windowx/3;
        float linethickness=10;
        double yct=windowy*.01;
        
        double xl1=WinXStart+3*margin+2*thickness;
        double xc1=windowx*Wx+x1*c+SpacingX;
        double xdist=xc1-xl1;
        double yc1=windowy*windowysize*windowysize-windowy/35;
        double partiallength=xdist/3;
        
        double xl2=windowx*Wx+x1*c+SpacingX;
        double xr2=windowx*Wx+x2+2*SpacingX;
        double xdist2=xr2-xl2;
        double yc2=windowy*windowysize*windowysize-windowy/35;
        double partiallength2=xdist2*5/12;
        
        double xl3=windowx*Wx+x2+2*SpacingX;
        double xr3=windowx-3*margin-2*thickness;
        double xdist3=xr3-xl3;
        double yc3=windowy*windowysize*windowysize-windowy/35;
        double partiallength3=xdist3*5/12;
        
        
        glBegin(GL_LINES);
        glLineWidth(linethickness);
        if (damper1state==1)
        {
            glVertex2d(xl1, yc1);
            glVertex2d(xl1+partiallength, yc1);
            
            glVertex2d(xl1+partiallength, yc1+yct);
            glVertex2d(xl1+partiallength, yc1-yct);
            
            glVertex2d(xl1+2*partiallength/3, yc1+2*yct);
            glVertex2d(xl1+3*partiallength/2, yc1+2*yct);
            
            glVertex2d(xl1+2*partiallength/3, yc1-2*yct);
            glVertex2d(xl1+3*partiallength/2, yc1-2*yct);
            
            glVertex2d(xl1+3*partiallength/2, yc1+2*yct);
            glVertex2d(xl1+3*partiallength/2, yc1-2*yct);
            
            glVertex2d(xl1+3*partiallength/2, yc1);
            glVertex2d(xc1, yc1);
            
        }
        if (damper2state==1)
        {
            glVertex2d(xl2, yc2);
            glVertex2d(xl2+partiallength2, yc2);
            
            glVertex2d(xl2+partiallength2, yc2+yct);
            glVertex2d(xl2+partiallength2, yc2-yct);
            
            glVertex2d(xl2+2*partiallength2/3, yc2+2*yct);
            glVertex2d(xl2+3*partiallength2/2, yc2+2*yct);
            
            glVertex2d(xl2+2*partiallength2/3, yc2-2*yct);
            glVertex2d(xl2+3*partiallength2/2, yc2-2*yct);
            
            glVertex2d(xl2+3*partiallength2/2, yc2+2*yct);
            glVertex2d(xl2+3*partiallength2/2, yc2-2*yct);
            
            glVertex2d(xl2+3*partiallength2/2, yc2);
            glVertex2d(xr2, yc2);
            
        }
        if (damper3state==1)
        {
            glVertex2d(xl3, yc3);
            glVertex2d(xl3+partiallength3, yc3);
            
            glVertex2d(xl3+partiallength3, yc3+yct);
            glVertex2d(xl3+partiallength3, yc3-yct);
            
            glVertex2d(xl3+2*partiallength3/3, yc3+2*yct);
            glVertex2d(xl3+3*partiallength3/2, yc3+2*yct);
            
            glVertex2d(xl3+2*partiallength3/3, yc3-2*yct);
            glVertex2d(xl3+3*partiallength3/2, yc3-2*yct);
            
            glVertex2d(xl3+3*partiallength3/2, yc3+2*yct);
            glVertex2d(xl3+3*partiallength3/2, yc3-2*yct);
            
            glVertex2d(xl3+3*partiallength3/2, yc3);
            glVertex2d(xr3, yc3);
            
        }
        glEnd();
    }
}
void AnimationWindow::draw(int mass1, int mass2, int spring1, int spring2, int spring3, int damper1,
                           int damper2, int damper3)
{
    x1=mass1;
    x2=mass2;
    DrawDamper();
    SpringDraw();
    DrawWalls();
    DrawForce();
    DrawBorder();
    DrawMass();
    
    
}
