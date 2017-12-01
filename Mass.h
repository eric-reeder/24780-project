#ifndef MASS_H
#define MASS_H

#include "SimulationObject.h"

class Mass : public SimulationObject
{
protected:
    double mass;
    double velocity;
    double maxDisplacement;

    int widthm;
    int heightm;

public:
    Mass();

    double getMass(void) const;
    void setMass(const double newMass);

    double getVelocity(void) const;
    void setVelocity(const double newVelocity);
    double Weee(void);
    void CheckState(void);
    
    int getWidth(void);
    int getHeight(void);

    void draw(const int xOffset, const int yOffset) const;
};

#endif /* MASS_H */
