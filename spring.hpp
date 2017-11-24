
#ifndef SPRING_H
#define SPRING_H

#include "SimulationObject.h"

class Spring : public SimulationObject
{
protected:
    double stiffness;
    double length;
    double lineThickness;
    
public:
    Spring();
    
    double getStiffness(void) const;
    void setStiffness(const double newStiffness);
    
    double getLength(void) const;
    void setLength(const double newLength);
    
    void draw(double startxPoint,double startyPoint,double lspring) const
};

#endif /* SPRING_H */
