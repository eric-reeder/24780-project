#include "Damper.h"
#include "fssimplewindow.h"


Damper::Damper()
{
    position = 0.0;
    length = 0.0;
    damping = 0.0;
    velocity = 0.0;
    state = true;
    redVal = 0;
    blueVal = 0;
    greenVal = 255;
    linethickness=2;
}


double Damper::getDamping(void) const
{
    return damping;
}


void Damper::setDamping(const double newDamping)
{
    damping = newDamping;
}


double Damper::getVelocity(void) const
{
    return velocity;
}


void Damper::setVelocity(const double newVelocity)
{
    velocity = newVelocity;
}


double Damper::getLength(void) const
{
    return length;
}


void Damper::setLength(const double newLength)
{
    length = newLength;
}


void Damper::draw(double startxPoint,double startyPoint,double lspring,double windowy) const
{
    double yct=windowy*.01;
    
    double xl1=startxPoint;
    double xc1=startxPoint+length;
    double xdist=xc1-xl1;
    double yc1=startyPoint;
    double partiallength=xdist/3;
   
    glColor3ub(redVal, greenVal, blueVal);
    glBegin(GL_LINES);
    glLineWidth(linethickness);
    if (state==1)
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
    
    
    glEnd();
}
