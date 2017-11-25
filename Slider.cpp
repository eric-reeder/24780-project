#include "Slider.h"
#include "fssimplewindow.h"

void Slider::Initialize(const double winWidth, const double winHeight, const double sliderYCoord)
{
	double margin = (8 * 14);
	dialStartX = winWidth / 20 + margin;
	dialStartY = sliderYCoord;

	sliderX = dialStartX;
	width = (2 * winWidth) / 3;
	height = (2 * winHeight) / 70;
	output = 0;
}

void Slider::DrawSlider(void) const
{
	
	glBegin(GL_LINES);
	glVertex2d(dialStartX, dialStartY);
	glVertex2d(dialStartX + width, dialStartY);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2d(dialStartX, dialStartY - height);
	glVertex2d(dialStartX + (2*width/70), dialStartY - height);
	glVertex2d(dialStartX + (2*width/70), dialStartY + height);
	glVertex2d(dialStartX, dialStartY + height);
	glEnd();

}

const double Slider::SliderOutput(void)
{
	output = (sliderX - dialStartX) / 100;

	return output;
}

const double Slider::returnXValue(void) const
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

/*class MassSlider : public Slider
{

};

class SpringSlider : public Slider
{
};

class DampenerSlider : public Slider
{
};

class AmplitudeSlider : public Slider
{
};

class FrequencySlider : public Slider
{
};*/