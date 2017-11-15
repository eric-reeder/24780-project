#include "fssimplewindow.h"
#include "GraphicsWindow.h"

GraphicsWindow::GraphicsWindow(int appWidth, int appHeight, int inputMargin, double widthFraction, double heightFraction, int inputXPosition, int inputYPosition)
{
    margin = inputMargin;
    width = (int)((double)appWidth * widthFraction) - 2 * margin;
    height = (int)((double)appHeight * widthFraction) - 2 * margin;
    xPosition = inputXPosition + margin;
    yPosition = inputYPosition + margin;

    borderWeight = 2;
    borderRed = 0;
    borderGreen = 0;
    borderBlue = 0;

    backgroundRed = 255;
    backgroundGreen = 255;
    backgroundBlue = 255;
}

void draw(void)
{
    // Draw backgound
    glColor3ub(backgroundRed, backgroundGreen, backgroundBlue);
    glBegin(GL_QUADS);
    glVertex2i(xPosition, yPosition);
    glVertex2i(xPosition + width, yPosition);
    glVertex2i(xPosition + width, yPosition + height);
    glVertex2i(xPosition, yPosition + height);
    glEnd();

    // Draw border
    glColor3ub(borderRed, borderGreen, borderBlue)
    glLineWidth(borderWeight);
    glBegin(GL_LINES);
    glVertex2i(xPosition, yPosition);
    glVertex2i(xPosition + width, yPosition);
    glVertex2i(xPosition + width, yPosition + height);
    glVertex2i(xPosition, yPosition + height);
    glEnd();
}
