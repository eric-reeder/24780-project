//#pragma once
// Runge-Kutta solver for 2 ODE system

#ifndef _RK2_IS_INCLUDED_
#define  _RK2_IS_INCLUDED_

#include "Runge_Kutta.h"
#include "Force.h"

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
	double Force1;

public:
	// Constructor
	RungeKutta2ODE(double t, double x1_in, double x2_in);

	//computes forces
	void computeForces(Force force1);

	//computes RK parameters
	void computeRKparameters(void);

	//solves for displacement
	std::vector<double> solveDisp(double tS, double m[2], double sS[3], double dC[3], Force force1, Force force2);

	//solves for velocity
	std::vector<double> solveVelocity(void);

	// Destructor
	~RungeKutta2ODE();

};

#endif
