#ifndef MASS_H
#define MASS_H

#include "SimulationObject.h"
#include "UIWindow.h"

class Mass : public SimulationObject
{
protected:
    double mass;
    double velocity;

    int width;
    int heigth;

public:
    Mass();

    double getMass(void) const;
    void setMass(const double newMass);

    double getVelocity(void) const;
    void setVelocity(const double newVelocity);

    void draw(void) const;
};

#endif /* MASS_H */