#ifndef DAMPER_H
#define DAMPER_H

#include "SimulationObject.h"

class Damper : public SimulationObject
{
protected:
    double damping;
    double velocity;
    double length;
    double VisLength;
    double linethickness;
    
public:
    Damper();
    
    double getDamping(void) const;
    void setDamping(const double newDamping);
    
    double getVelocity(void) const;
    void setVelocity(const double newVelocity);
    
    double getLength(void) const;
    void setLength(const double newLength);
    
    void draw(double startxPoint,double startyPoint,double lspring,double windowy) const;
    
    double getVisiLength(void) const;
    void setVisiLength(const double newvLength);
};

#endif /* DAMPER_H */

