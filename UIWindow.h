#ifndef UI_WINDOW_H
	#define UI_WINDOW_H
	const int N_MASS = 2; //number of masses
	const int N_SPRINGS = 3; // number of springs
	const int N_DAMPENERS = 3; // number of dampeners
	const int N_FORCES = 2; // forces acting on each mass
	const double YS_PI = 3.1415927;
	
	void DrawCircle(double cx, double cy, double radius, int fill); //Draws the circle to make the radio button, fill option used to tell whether the radio button is selected or not
	void DrawRect(double x, double y, double height, double width); //Draws the slider you can move on the dial
	void DrawLine(double x0, double y0, double width);//Draws the dial
	class Slider
	{
	// class for the slider associated with each type of element
	protected:
	double dialStartX, dialStartY, height, width; //dialStartX is the x co-ordinate of the dials, width is the horizontal length occupied by the slider, height is the vertical length occupied by the slider
	double sliderX; //X co-ordinate of the slider moving on the dial
	double output; // output consistent with the dial value set by the user
	public:
	void Initialize(double winWidth, double winHeight, double sliderYCoord); //sets initial values of dialStartX, dialStartY and sliderX
	void DrawSlider(double SliderYCoord); // Draws the slider
	double SliderOutput(void);//outputs the value of mass, spring constant or damping coefficient as per the user selection, the state ensures the condition that all masses cannot be zero, all forces cannot be zero and that both spring constant and damping coefficient cannot be zero together, moreover ensures that frequency cannot be toggled if type of force selected is not sinosoidal
	};
	class MassSlider : public Slider
	{
	
	};	
	class SpringSlider : public Slider
	{

	};
	class DampenerSlider: public Slider
	{

	};
	class ForceSlider : public Slider
	{

	};
	class AmplitdeSlider : public Slider
	{

	};
	class FrequencySlider: public Slider
	{

	};


	class RadioButton
	{
	protected:
		int state; //determines whether or not radio button is selected, and gives suitable output(0=no button selected, 1 = constant force, 2 = exponential force and 3 = sinosoidal force)
		
		double centreX, centreY, radius; // parameters of the radio button
	public:
		void Initialize(double winWidth,double startY); //sets initial values of the centre co-ordinates, state and radius of the radio button
		void DrawRadio(void); // draws the radio button
		
	};
	class UIWindow
	{
	//Makes the UI window
	protected:
		MassSlider mslider[N_MASSES];
		SpringSlider k[N_SPRINGS];
		DampenerSlider c[N_DAMPENERS];
		AmplitudeSlider A[N_FORCES];
		FrequencySlider f[N_FORCES];
		RadioButton r[N_FORCES];		
	public:
		void DrawUIWindow(double winWidth, double winHeight);
		
	}; 
#endif