#include "Slider.h"

void Slider::Initialize(const double winWidth, const double winHeight,const double sliderYCoord)
{
  double margin = (8*14);
  dialStartX = winWidth/20 + margin;
  dialStartY = sliderYCoord;

  sliderX = dialStartX;
  width = (2*winWidth)/3;
  height = (2*winHeight)/70;
  output = 0;
}

void Slider::DrawSlider(void) const
{
  glBegin(GL_LINES);
  glVeretx2d(dialStartX,dialStartY);
  glVeretx2d(dialStartX + width,dialStartY);
  glEnd();

  glBegin(GL_QUADS);
  glVertex2d(dialStartX, dialStartY - height);
  glVertex2d(dialStartX + width, dialStartY - height);
  glVertex2d(dialStartX + width, dialStartY + height);
  glVertex2d(dialStartX, dialStartY + height);
  glEnd();

}

const double Slider::SliderOutput(void)
{
  output = (sliderX - dialStartX)/100;

  return output;
}
