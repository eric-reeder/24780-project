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

    double getPosition(void);
    void setPosition(double newPosition);

    int getRedVal(void);
    int setRedVal(void);
    int getBlueVal(void);
    int setBlueVal(void);
    int getGreenVal(void);
    int setGreenVal(void);
}
