#include "Damper.h"
#include "fssimplewindow.h"
#include "ysglfontdata.h"



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
    linethickness=7;
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

double Damper::getVisiLength(void) const
{
    return VisLength;
}


void Damper::setVisiLength(const double newvLength)
{
    VisLength = newvLength;
}


void Damper::draw(double startxPoint,double startyPoint,double lspring,double windowy) const
{
    double yct=windowy*.03;
    
    double xl1=startxPoint;
    double xc1=startxPoint+VisLength;
    double xdist=xc1-xl1;
    double yc1=startyPoint;
    double partiallength=5*xdist/12;
    glLineWidth(linethickness);
    
    glColor3ub(redVal, greenVal, blueVal);
    
    if (state==1)
    {
        glBegin(GL_LINES);
        glLineWidth(linethickness);
        glVertex2d(xl1, yc1);
        glVertex2d(xl1+partiallength*14/12, yc1);
        
        glVertex2d(xl1+partiallength*14/12, yc1+yct);
        glVertex2d(xl1+partiallength*14/12, yc1-yct);
        
        glVertex2d(xl1+partiallength, yc1+2*yct);
        glVertex2d(xl1+3*partiallength/2, yc1+2*yct);
        
        glVertex2d(xl1+partiallength, yc1-2*yct);
        glVertex2d(xl1+3*partiallength/2, yc1-2*yct);
        
        glVertex2d(xl1+3*partiallength/2, yc1+2*yct);
        glVertex2d(xl1+3*partiallength/2, yc1-2*yct);
        
        glVertex2d(xl1+3*partiallength/2, yc1);
        glVertex2d(xc1, yc1);
        glEnd();
        int Dampera=damping/10;
        int Damperb=damping-Dampera;
        int Damperc=damping-Dampera-Damperb;
        char YayDamper[11];
        for (int i=0;i<10;i++)
        {
            if (Dampera==i)
            {
                YayDamper[0]=48+i;
                if (YayDamper[0]==48)
                {
                    YayDamper[0]=32;
                }
            }
        }
        for (int j=0;j<10;j++)
        {
            if (Damperb==j)
            {
                YayDamper[1]=48+j;
            }
        }
        for (int k=0;k<10;k++)
        {
            if (Damperc==k)
            {
                YayDamper[2]=46;
                YayDamper[3]=48+k;

                
            }
        }
        YayDamper[4]=32;
        YayDamper[5]=78;
        YayDamper[6]=47;
        YayDamper[7]=109;
        YayDamper[8]=94;
        YayDamper[9]=50;
        YayDamper[10]=0;
        char* d=&YayDamper[0];
        glColor3b(0, 0, 0);
        glRasterPos2d(xl1+5*partiallength/4-60,yc1-4*yct);
        YsGlDrawFontBitmap12x16(d);
        
        
        
    }
    
}

