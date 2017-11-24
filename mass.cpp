#include "Mass.h"
#include "SimulationObject.h"
#include "fssimplewindow.h"


Mass::Mass()
{
    position = 0;
    mass = 0.0;
    velocity = 0.0;
    width = 50;
    height = 50;
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


void Mass::setVelocity(const double newVelocity)
{
    velocity = newVelocity;
}


void Mass::draw(const int xPos, const int yOffset) const
{
    if (state == true)
    {
        glColor3ub(redVal, greenVal, blueVal);
        glBegin(GL_QUADS);
        glVertex2f(xPos+width/2,yoffset-height/2);
        glVertex2f(xPos+width/2,yoffset+height/2);
        glVertex2f(xPos-width/2,yoffset+height/2);
        glVertex2f(xPos-width/2,yoffset-height/2);
    }
    glEnd();
}
