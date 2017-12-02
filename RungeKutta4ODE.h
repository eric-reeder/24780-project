// Runge-Kutta solver for 4 ODE system

#ifndef _RK4_IS_INCLUDED_
#define  _RK4_IS_INCLUDED_

#include "Runge_Kutta.h"
#include "Force.h"
#include<iostream>
#include <vector>
using namespace std;

//The 4 ODE solver inhertits from the base RungeKutta class
class RungeKutta4ODE :public RungeKutta
{
protected:
	// Variables for the single mass system
	double mass[2], springStiffness[3], dampCoefficient[3];	
	
	// x1 & x2: displaments of mass 1 & 2| x3 & x4: velocities of mass 1 & 2
	double x1;
	double x2;
	double x3;
	double x4;

	// RK parameters
	double k1[4], k2[4], k3[4], k4[4];

	//forces on masses
	double Force1, Force2;

public:
	// Constructor
	RungeKutta4ODE(double t, double x1_in, double x2_in, double x3_in, double x4_in);	

	//computes forces
	vector<double> computeForces(Force force1, Force force2, double t);
	
	//functions for ODEs
	double f1(double x3);
	double f2(double x4);
	double f3(double x1, double x2, double x3, double x4, double mass[2], double springStiffness[3], double dampCoefficient[3], Force force1, Force force2, double t);
	double f4(double x1, double x2, double x3, double x4, double mass[2], double springStiffness[3], double dampCoefficient[3], Force force1, Force force2, double t);

	//computes RK parameters
	void computeRKparameters(Force force1, Force force2);
	
	//solves for displacement
	std::vector<double> solveDisp(double tS, double m[2], double sS[3], double dC[3], Force force1, Force force2);

	//solves for velocity
	std::vector<double> solveVelocity(void);

	// Destructor
	~RungeKutta4ODE();	
};

#endif
