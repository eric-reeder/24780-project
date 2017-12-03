#include "RungeKutta2ODE.h"
#include <math.h>
#include <vector>


#include<iostream>

// Constructor
RungeKutta2ODE::RungeKutta2ODE(double t, double x1_in, double x2_in)
{
	// initial condition
	x1 = x1_in;
	x2 = x2_in;
	time = t;
	
	// RK parameters setting to zero
	for (int i = 0; i < 2; i++)
	{
		k1[i] = 0.;
		k2[i] = 0.;
		k3[i] = 0.;
		k4[i] = 0.;
	}
}

double RungeKutta2ODE::computeForces(Force force1, double t)
{
	switch (force1.getType())
	{
	case 0:
	{
		Force1 = force1.getValue()[0] * sin(force1.getValue()[1] * t);
		//std::cout << "Force 1: " << Force1 << "\n";
		//std::cout << "TIME: " << time << "\n";
		break;
	}
	case 1:
	{
		Force1 = force1.getValue()[0] * exp(-(1.0/force1.getValue()[1]) * t);
		//std::cout << "Force 1: " << Force1 << "\n";
		//std::cout << "TIME: " << time << "\n";
		break;
	}
	case 2:
	{
		Force1 = force1.getValue()[0];
		//std::cout << "Force 1: " << Force1 << "\n";
		//std::cout << "TIME: " << time << "\n";
		break;
	}
	}

	return Force1;
}

double RungeKutta2ODE::f1(double x2)
{
	return x2;
}
double RungeKutta2ODE::f2(double x1, double x2, double mass, double springStiffness, double dampCoefficient, Force force1,double t)//, double Force1)
{
	double f2;
	if (mass != 0)
	{
		f2 = x1*(-springStiffness / mass) + x2*(-dampCoefficient / mass) + computeForces(force1, t) / mass;
	}
	return f2;
}


void RungeKutta2ODE::computeRKparameters(Force force1)
{
	k1[0] = timeStep*f1(x2);
	k1[1] = timeStep*f2(x1, x2, mass, springStiffness, dampCoefficient,force1, time);
	k2[0] = timeStep*f1(x2 + 0.5*k1[1]);
	k2[1] = timeStep*f2(x1 + 0.5*k1[0], x2 + 0.5*k1[1], mass, springStiffness, dampCoefficient, force1, time + timeStep/2.0);
	k3[0] = timeStep*f1(x2 + 0.5*k2[1]);
	k3[1] = timeStep*f2(x1 + 0.5*k2[0], x2 + 0.5*k2[1], mass, springStiffness, dampCoefficient, force1, time + timeStep / 2.0);
	k4[0] = timeStep*f1(x2 + k3[1]);
	k4[1] = timeStep*f2(x1 + k3[0], x2 + k3[1], mass, springStiffness, dampCoefficient, force1, time + timeStep);
}

std::vector<double> RungeKutta2ODE::solveDisp(double tS, double m[2], double sS[3], double dC[3], Force force1, Force force2)
{
	timeStep = tS;
	mass = m[0];
	//std::cout << "MASS IN solveDisp()" << mass<<"\n";
	springStiffness = sS[0];
	//std::cout << "SPRING IN solveDisp(): " << springStiffness << "\n";
	
	dampCoefficient = dC[0];
	//computeForces(force1);
	computeRKparameters(force1);
	x1 = x1 + (k1[0] + 2.*k2[0] + 2.*k3[0] + k4[0]) / 6.;
	//std::cout << "FORCE IN solveDisp(): " << Force1 << "\n";
	//std::cout << "X1: " << x1 << "\n";
	std::vector<double> disp = { x1 };

	return disp;
}

std::vector<double> RungeKutta2ODE::solveVelocity(void)
{
	x2 = x2 + (k1[1] + 2.*k2[1] + 2.*k3[1] + k4[1]) / 6.;
	std::vector<double> vel = { x2 };
	return vel;
}

// Destructor
RungeKutta2ODE::~RungeKutta2ODE()
{
}
