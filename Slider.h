#ifndef SLIDER_H
  #define SLIDER_H
  class Slider
{
protected:
	double dialStartX, dialStartY, height, width;
	double sliderX;
	double output;
public:
	void Initialize(const double winWidth, const double winHeight, const double sliderYCoord);
	void DrawSlider(void) const;
	const double SliderOutput(void);
	void SetValue(const int mx);
	const double returnXValue(void) const;
	const double returnYValue(void) const;
	const double returnWidthValue(void) const;
	const double returnHeightValue(void) const;

};
#endif
