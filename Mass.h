#ifndef MASS_H
#define MASS_H

#include "SimulationObject.h"

class Mass : public SimulationObject
{
protected:
	// Inherited
    double position;
    bool state; // "true" corresponds to active, "false" to inactive
    int redVal;
    int blueVal;
    int greenVal;

    // New
    double mass;
    double velocity;

    int width;
    int heigth;

public:
	// Inherited
    void setState(const bool newState);

    double getPosition(void) const;
    void setPosition(const double newPosition);

    int getRedVal(void) const;
    int getBlueVal(void) const;
    int getGreenVal(void) const;

    void setColor(const int newRedVal, const int newGreenVal, 
        const int newBlueVal);

    // New
    Mass();

    double getMass(void) const;
    void setMass(const double newMass);

    double getVelocity(void) const;
    void setVelocity(const double newVelocity);

    void draw(void) const;
};

#endif /* MASS_H */