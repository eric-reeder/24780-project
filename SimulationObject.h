class SimulationObject
{
protected:
    double position;
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
