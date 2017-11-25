#ifndef UI_WINDOW_H
  #define UI_WINDOW_H

  class UIWindow : public GraphicsWindow
{
protected:
	MassSlider mslider[N_MASSES];
	SpringSlider k[N_SPRINGS];
	DampenerSlider c[N_SPRINGS];
	AmplitudeSlider A[N_FORCES];
	FrequencySlider f[N_FORCES];
	RadioButton r[N_FORCES];
	
public:
	
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
};

#endif
