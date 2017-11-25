#ifndef RADIOBUTTON_H
  #define RADIOBUTTON_H

  class RadioButton
{
protected:
	int state;
	double centreX, centreY, radius;
public:
	void Initialize(const double winWidth, const double startY);
	void DrawRadio(void) const;
	void SetValue(int set);
	const int RadioOutput(void) const;
	double returnCentreX(void) const;
	const double returnCentreY(void) const;
	const double returnRadius(void) const;

};


  void DrawCircle(const double cx,const double cy,const double radius,const int fill);

  #endif
