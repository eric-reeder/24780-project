#ifndef UI_WINDOW_H
  #define UI_WINDOW_H
  
  #include "Slider.h"
  #include "RadioButton.h"
  
class UIWindow: public GraphicsWindow
{
protected:
	Slider mass1;
	Slider mass2;
	Slider Spring1;
	Slider Spring2;
	Slider Spring3;
	Slider Dampener1;
	Slider Dampener2;
	Slider Dampener3;
	Slider Amplitude1;
	Slider Amplitude2;
	Slider Frequency1;
	Slider Frequency2;
	RadioButton r1;
	RadioButton r2;
	
	int xPosition, yPosition, width, height, startX,startY,startWidth,startHeight;
	int On;

public:
	void setPosition(const int uiWindowXPosition, const int uiWindowYPosition);
	void setSize(const int uiWindowWidth, const int uiWindowHeight);
	const double getMass1Mass(void);
	const double getMass2Mass(void);
	const double getSpring1Stiffness(void);
	const double getSpring2Stiffness(void);
	const double getSpring3Stiffness(void);
	const double getDamper1Damping(void);
	const double getDamper2Damping(void);
	const double getDamper3Damping(void);
	const int getForce1Type(void);
	const int getForce2Type(void);
	const double getForce1Value1(void);
	const double getForce1Value2(void);
	const double getForce2Value1(void);
	const double getForce2Value2(void);
	void DrawUIWindow(void);
	void DrawStart(double sliderYCoord);
	const double returnStartX(void);
	const double returnStartY(void);
	const double returnStartHeight(void);
	const double returnStartWidth(void);
	void returnOn(const int play);
};
#endif
