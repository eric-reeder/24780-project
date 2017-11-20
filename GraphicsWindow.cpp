#include "fssimplewindow.h"
#include "GraphicsWindow.h"

/*  Creates a graphics window object with black border and white background
    Inputs:
    appWidth: Width of app window
    appHeight: Height of app window
    inputMargin: Margin between this window and other windows
    widthFraction: Fraction of app window width this window will be
    heightFraction: Fraction of app window height this window will be
    inputXPosition: X coordinate of top left corner
    inputYPosition: Y coordinate of top left corner  */
GraphicsWindow::GraphicsWindow()
{
    borderWeight = 2;
    borderRed = 0;
    borderGreen = 0;
    borderBlue = 0;

    backgroundRed = 255;
    backgroundGreen = 255;
    backgroundBlue = 255;
}

/*  Sets x and y coordinates of top left corner
    Inputs:
    newXPosition: X coordinate of top left corner
    newYPosition: Y coordinate of top left corner  */
void GraphicsWindow::setPosition(const int newXPosition, const int newYPosition)
{
    xPosition = newXPosition;
    yPosition = newYPosition;
}

void GraphicsWindow::setSize(const int newWidth, const int newHeight)
{
    width = newWidth;
    height = newHeight;
}

/*  Draws background of graphics window  */
void GraphicsWindow::drawBackground(void) const
{
    glColor3ub(backgroundRed, backgroundGreen, backgroundBlue);
    glBegin(GL_QUADS);
    glVertex2i(xPosition, yPosition);
    glVertex2i(xPosition + width, yPosition);
    glVertex2i(xPosition + width, yPosition + height);
    glVertex2i(xPosition, yPosition + height);
    glEnd();
}

/*  Draws border on graphics window  */
void GraphicsWindow::drawBorder(void) const
{
    glColor3ub(borderRed, borderGreen, borderBlue);
    glBegin(GL_LINES);
    glLineWidth(borderWeight);

    glVertex2i(xPosition, yPosition);
    glVertex2i(xPosition + width, yPosition);

    glVertex2i(xPosition + width, yPosition);
    glVertex2i(xPosition + width, yPosition + height);

    glVertex2i(xPosition + width, yPosition + height);
    glVertex2i(xPosition, yPosition + height);

    glVertex2i(xPosition, yPosition + height);
    glVertex2i(xPosition, yPosition);
    glEnd();
}

/*  Draws the graphics window  */
void GraphicsWindow::draw() const
{
    drawBackground();
    drawBorder();
}
