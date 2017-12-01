#include "Slider.h"
#include "fssimplewindow.h"

void Slider::Initialize(const double winWidth, const double winHeight, const double sliderYCoord)
{
	double margin = (8 * 14);
	dialStartX = winWidth / 20 + 1.5*margin;
	dialStartY = sliderYCoord;

	sliderX = dialStartX;
	width = (3 * winWidth) / 7;
	height = (2 * winHeight) / 200;
	output = 0;
}

void Slider::DrawSlider(void) const
{

	glBegin(GL_LINES);
	glVertex2d(dialStartX, dialStartY);
	glVertex2d(dialStartX + width, dialStartY);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2d(sliderX, dialStartY - height);
	glVertex2d(sliderX + (2 * width / 70), dialStartY - height);
	glVertex2d(sliderX + (2 * width / 70), dialStartY + height);
	glVertex2d(sliderX, dialStartY + height);
	glEnd();

}

const double Slider::SliderOutput(double size, double lowest)
{
	output = lowest + ((sliderX - dialStartX) / (width)) * size;

	return output;
}

double Slider::returnXValue(void) const
{
	return dialStartX;
}

const double Slider::returnYValue(void) const
{
	return dialStartY;
}

const double Slider::returnHeightValue(void) const
{
	return height;
}

const double Slider::returnWidthValue(void) const
{
	return width;
}

void Slider::SetValue(const int mx)
{
	sliderX = mx;
	
}
