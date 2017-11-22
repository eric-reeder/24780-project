#include "RungeKutta2ODE.h"
#include <math.h>

// Constructor
RungeKutta2ODE::RungeKutta2ODE()
{
	// initial condition
	x1 = 0.;
	x2 = 0.;
	
	// RK parameters setting to zero
	for (int i = 0; i < 2; i++)
	{
		k1[i] = 0.;
		k2[i] = 0.;
		k3[i] = 0.;
		k4[i] = 0.;
	}
}

void RungeKutta2ODE::computeForces(Force force1)
{
	switch (force1.getType())
	{
	case 0:
	{
		Force1 = force1.getValue()[0] * sin(force1.getValue()[1] * time);
		break;
	}
	case 1:
	{
		Force1 = force1.getValue()[0] * exp(-force1.getValue()[1] * time);
		break;
	}
	case 2:
	{
		Force1 = force1.getValue()[0];
		break;
	}
	}
}

double f1(double x2)
{
	return x2;
}
double f2(double x1, double x2, double mass, double springStiffness, double dampCoefficient, double Force1)
{
	double f2;
	if (mass != 0)
	{
		f2 = x1*(-springStiffness / mass) + x2*(-dampCoefficient / mass) + Force1 / mass;
	}
	return f2;
}


void RungeKutta2ODE::computeRKparameters(void)
{
	k1[0] = timeStep*f1(x2);
	k1[1] = timeStep*f2(x1, x2, mass, springStiffness, dampCoefficient, Force1);
	k2[0] = timeStep*f1(x1 + 0.5*k1[0]);
	k2[1] = timeStep*f2(x1 + 0.5*k1[0], x2 + 0.5*k1[1], mass, springStiffness, dampCoefficient, Force1);
	k3[0] = timeStep*f1(x1 + 0.5*k2[0]);
	k3[1] = timeStep*f2(x1 + 0.5*k2[0], x2 + 0.5*k2[1], mass, springStiffness, dampCoefficient, Force1);
	k4[0] = timeStep*f1(x1 + 0.5*k3[0]);
	k4[1] = timeStep*f2(x1 + 0.5*k3[0], x2 + 0.5*k3[1], mass, springStiffness, dampCoefficient, Force1);
	time = time + timeStep;
}

std::vector<double> RungeKutta2ODE::solveDisp(double tS, double m[2], double sS[3], double dC[3], Force force1, Force force2)
{
	timeStep = tS;
	mass = m[0];
	springStiffness = sS[0];
	dampCoefficient = dC[0];
	computeForces(force1);
	computeRKparameters();
	x1 = x1 + (k1[0] + 2.*k2[0] + 2.*k3[0] + k4[0]) / 6.;
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
