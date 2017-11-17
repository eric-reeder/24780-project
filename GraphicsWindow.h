#ifndef GRAPHICSWINDOW_H
#define GRAPHICSWINDOW_H

class GraphicsWindow
{
protected:
    int width;
    int height;
    int margin; // Pixels between edges of graphics windows
    int xPosition;
    int yPosition;

    int borderWeight; // Thickness of border
    int borderRed;
    int borderGreen;
    int borderBlue;

    int backgroundRed;
    int backgroundGreen;
    int backgroundBlue;

    void drawBackground(void) const;
    void drawBorder(void) const;

public:
    GraphicsWindow(int appWidth, int appHeight, double widthFraction, 
        double heightFraction);
    void setPosition(const int newXPosition, const int newYPosition);
    void draw(void) const;
};

#endif /* GRAPHICSWINDOW_H */
