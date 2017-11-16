#ifndef SIMULATIONOBJECT_H
#define SIMULATIONOBJECT_H

class SimulationObject
{
protected:
    double position;
    bool state; // "true" corresponds to active, "false" to inactive
    int redVal;
    int blueVal;
    int greenVal;

public:
    SimulationObject();

    double getPosition(void) const;
    void setPosition(const double newPosition);

    int getRedVal(void) const;
    void setRedVal(const int newRedVal);

    int getBlueVal(void) const;
    void setBlueVal(const int newBlueVal);
    
    int getGreenVal(void) const;
    void setGreenVal(const int newGreenVal);
}

#endif /* SIMULATIONOBJECT_H */
