
#ifndef SPRING_H
#define SPRING_H

#include "SimulationObject.h"
#include <math.h>

class Spring : public SimulationObject
{
protected:
    double stiffness;
    double length;
    double lineThickness;
    double Visilength;
    
public:
    Spring();
    
    double getStiffness(void) const;
    void setStiffness(const double newStiffness);
    
    double getLength(void) const;
    void setLength(const double newLength);
    
    void setVisualLength(const double VisLeng);
    
    void draw(double startxPoint,double startyPoint,double lspring) const;
};

#endif /* SPRING_H */
