#ifndef RADIOBUTTON_H
  #define RADIOBUTTON_H

  const double YS_PI = 3.1415927;
class RadioButton
{
protected:
	int state;
	double radioSpaceMargin = (8 * 14);
	double radioSpaceMargin2 = (3 * 14);
	double centreX, centreY, radius;
public:
	void Initialize(const double winWidth, const double startY);
	void DrawRadio(int n) const;
	void SetValue(int set);
	const int RadioOutput(void) const;
	double returnCentreX(void) const;
	const double returnCentreY(void) const;
	const double returnRadius(void) const;
	const double returnRadioSpaceMargin1(void) const;
	const double returnRadioSpaceMargin2(void) const;

};


  void DrawCircle(const double cx,const double cy,const double radius,const int fill);

  #endif