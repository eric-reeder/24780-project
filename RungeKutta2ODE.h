//#pragma once
// Runge-Kutta solver for 2 ODE system

#include "Runge_Kutta.h"

//The 2 ODE solver inhertits from the base RungeKutta class
class RungeKutta2ODE :public RungeKutta
{
protected:
	// Variables for the single mass system
	double mass, springStiffness, dampCoefficient;

	// x1 & x2: displaments of mass 1 & 2| x3 & x4: velocities of mass 1 & 2
	double x1;
	double x2;
	
	// RK parameters
	double k1[2], k2[2], k3[2], k4[2];

	//forces on masses
	double force1;

public:
	// Constructor
	RungeKutta2ODE();

	//computes forces
	void computeForces(Force force1);

	//computes RK parameters
	void computeRKparameters(void);

	//solves for displacement
	double solveDisp(double tS, double m, double sS, double dC, Force force1);

	//solves for velocity
	double solveVelocity(void);

	// Destructor
	~RungeKutta2ODE();

};