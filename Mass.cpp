#include "Mass.h"
#include "SimulationObject.h"
#include "fssimplewindow.h"
#include <stdio.h>
#include "ysglfontdata.h"



Mass::Mass()
{
    position = 0;
    mass = 0.0;
    velocity = 0.0;
    widthm = 100;
    heightm = 100;
    state = true;
    redVal = 255;
    blueVal = 0;
    greenVal = 0;
}


double Mass::getMass(void) const
{
    return mass;
}


void Mass::setMass(const double newMass)
{
    mass = newMass;
}


double Mass::getVelocity(void) const
{
    return velocity;
}

double Mass::Weee(void)
{
    return position;
}


void Mass::setVelocity(const double newVelocity)
{
    velocity = newVelocity;
}


void Mass::draw(const int xPos, const int yOffset) const
{
    glColor3ub(redVal, greenVal, blueVal);
    if (state == true)
    {
        glBegin(GL_QUADS);
        glVertex2f(xPos+widthm/2,yOffset-heightm/2);
        glVertex2f(xPos+widthm/2,yOffset+heightm/2);
        glVertex2f(xPos-widthm/2,yOffset+heightm/2);
        glVertex2f(xPos-widthm/2,yOffset-heightm/2);
        glEnd();
        int massa=mass/10;
        int massb=mass-massa;
        int massc=mass-massa-massb;
        char masses[8];
        for (int i=0;i<10;i++)
        {
            if (massa==i)
            {
                masses[0]=48+i;
                if (masses[0]==48)
                {
                    masses[0]=32;
                }
            }
        }
        for (int j=0;j<10;j++)
        {
            if (massb==j)
            {
                masses[1]=48+j;
            }
        }
        for (int k=0;k<10;k++)
        {
            if (massc==k)
            {
                masses[2]=46;
                masses[3]=48+k;

            }
        }
        masses[4]=32;
        masses[5]=107;
        masses[6]=103;
        masses[7]=0;
        char* d=&masses[0];
        glColor3b(0, 0, 0);
        glRasterPos2d(xPos-42,yOffset);
        YsGlDrawFontBitmap12x16(d);
        
    }
}
