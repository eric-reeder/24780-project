#include "Mass.h"
#include "SimulationObject.h"
#include "fssimplewindow.h"


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

double Mass::getPosition(void) const
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
    glBegin(GL_QUADS);
    if (state == true)
    {
        glVertex2f(xPos+widthm/2,yOffset-heightm/2);
        glVertex2f(xPos+widthm/2,yOffset+heightm/2);
        glVertex2f(xPos-widthm/2,yOffset+heightm/2);
        glVertex2f(xPos-widthm/2,yOffset-heightm/2);
    }
    glEnd();
}
