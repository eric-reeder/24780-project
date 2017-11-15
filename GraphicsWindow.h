class GraphicsWindow
{
protected:
    int width;
    int height;
    int margin;
    int xPosition;
    int yPosition;

    int borderWeight;
    int borderRed;
    int borderGreen;
    int borderBlue;

    int backgroundRed;
    int backgroundGreen;
    int backgroundBlue;

public:
    GraphicsWindow(int appWidth, int appHeight, double widthFraction, double heightFraction);
    void draw(void);
};
