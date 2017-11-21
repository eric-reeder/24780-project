#ifndef DAMPER_H
#define DAMPER_H

#include "SimulationObject.h"

class Damper : public SimulationObject
{
protected:
	double damping;
    double velocity;
	double length;

public:
	Damper();

	double getDamping(void) const;
	void setDamping(const double newDamping);
    
    double getVelocity(void) const;
    void setVelocity(const double newVelocity);

	double getLength(void) const;
	void setLength(const double newLength);

	void draw(void) const;
};

#endif /* DAMPER_H */
