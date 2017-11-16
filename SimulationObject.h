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
    int getBlueVal(void) const;
    int getGreenVal(void) const;

    void setColor(const int newRedVal, const int newGreenVal, 
        const int newBlueVal);
}

#endif /* SIMULATIONOBJECT_H */
