#ifndef GRAPHICSWINDOW_H
#define GRAPHICSWINDOW_H

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
    GraphicsWindow(int appWidth, int appHeight, double widthFraction, 
        double heightFraction);
    void setPosition(const int newXPosition, const int newYPosition);
    void draw(void) const;
};

#endif /* GRAPHICSWINDOW_H */
