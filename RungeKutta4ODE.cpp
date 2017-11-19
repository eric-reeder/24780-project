#include "RungeKutta4ODE.h"
#include <math.h>
#include <vector>

// Constructor
RungeKutta4ODE::RungeKutta4ODE()
{
	// initial condition
	x1 = 0.;
	x2 = 0.;
	x3 = 0.;
	x4 = 0.;

	// RK parameters setting to zero
	for (int i = 0; i < 4; i++)
	{
		k1[i] = 0.;
		k2[i] = 0.;
		k3[i] = 0.;
		k4[i] = 0.;
	}
}

void RungeKutta4ODE::computeForces(Force force1, Force force2)
{
	switch (force1.type)
	{
	case 0:
	{
		force1 = force1.getvalue[0] * sin(force1.getvalue[1] * time);
		break;
	}
	case 1:
	{
		force1 = force1.getvalue[0] * exp(-force1.getvalue[1] * time);
		break;
	}
	case 2:
	{
		force1 = force1.getvalue[0];
		break;
	}
	}
	switch (force2.type)
	{
	case 0:
	{
		force2 = force2.getvalue[0] * sin(force2.getvalue[1] * time);
		break;
	}
	case 1:
	{
		force2 = force2.getvalue[0] * exp(-force2.getvalue[1] * time);
		break;
	}
	case 2:
	{
		force2 = force2.getvalue[0];
		break;
	}
	}
}


//functions f1, f2, f3 & f4 compute instantaneous values of x1, x2, x3, x4
double f1(double x3)
{
	return x3;
}
double f2(double x4)
{
	return x4;
}
double f3(double x1, double x2, double x3, double x4, double mass[2], double springStiffness[3], double dampCoefficient[3], double force1)
{
	double f3;
	if (mass[0] != 0)
	{
		f3 = x1*((-springStiffness[0] - springStiffness[1]) / mass[0]) + x2*(springStiffness[1] / mass[0]) +
			x3*((-dampCoefficient[0]-dampCoefficient[1])/mass[0]) + x4*(dampCoefficient[1]/mass[0]) + force1/mass[0];
	}
	else
	{
		f3 = 0;
	}
	return f3;
}
double f4(double x1, double x2, double x3, double x4, double mass[2], double springStiffness[3], double dampCoefficient[3], double force2)
{
	double f4;
	if (mass[1] != 0)
	{
		f4 = x2*((-springStiffness[1] - springStiffness[2]) / mass[1]) + x1*(springStiffness[1] / mass[1]) +
			x4*((-dampCoefficient[1] - dampCoefficient[2]) / mass[1]) + x3*(dampCoefficient[1] / mass[1]) + force2 / mass[1];
	}
	else
	{
		f4 = 0;
	}
	return f4;
}



void RungeKutta4ODE::computeRKparameters(void)
{
	k1[0] = timeStep*f1(x3);
	k1[1] = timeStep*f2(x4);
	k1[2] = timeStep*f3(x1, x2, x3, x4);
	k1[3] = timeStep*f4(x1, x2, x3, x4);
	k2[0] = timeStep*f1(x3 + 0.5*k1[2]);
	k2[1] = timeStep*f2(x4 + 0.5*k1[3]);
	k2[2] = timeStep*f3(x1 + 0.5*k1[0], x2 + 0.5*k1[1], x3 + 0.5*k1[2], x4 + 0.5*k1[3], mass, springStiffness, dampCoefficient, force1);
	k2[3] = timeStep*f4(x1 + 0.5*k1[0], x2 + 0.5*k1[1], x3 + 0.5*k1[2], x4 + 0.5*k1[3], mass, springStiffness, dampCoefficient, force2);
	k3[0] = timeStep*f1(x3 + 0.5*k2[2]);
	k3[1] = timeStep*f2(x4 + 0.5*k2[3]);
	k3[2] = timeStep*f3(x1 + 0.5*k2[0], x2 + 0.5*k2[1], x3 + 0.5*k2[2], x4 + 0.5*k2[3], mass, springStiffness, dampCoefficient, force1);
	k3[3] = timeStep*f4(x1 + 0.5*k2[0], x2 + 0.5*k2[1], x3 + 0.5*k2[2], x4 + 0.5*k2[3], mass, springStiffness, dampCoefficient, force2);
	k4[0] = timeStep*f1(x3 + 0.5*k3[2]);
	k4[1] = timeStep*f2(x4 + 0.5*k3[3]);
	k4[2] = timeStep*f3(x1 + 0.5*k3[0], x2 + 0.5*k3[1], x3 + 0.5*k3[2], x4 + 0.5*k3[3], mass, springStiffness, dampCoefficient, force1);
	k4[3] = timeStep*f4(x1 + 0.5*k3[0], x2 + 0.5*k3[1], x3 + 0.5*k3[2], x4 + 0.5*k3[3], mass, springStiffness, dampCoefficient, force2);
	time = time + timeStep;
}

std::vector<double> RungeKutta4ODE::solveDisp(double tS, double m[2], double sS[3], double dC[3], Force force1, Force force2)
{ 
	timeStep = tS;
	for (int i = 0; i < 2; i++)
	{
		mass[i] = m[i];
	}
	for (int i = 0; i < 3; i++)
	{
		springStiffness[i] = sS[i];
		dampCoefficient[i] = dC[i];
	}
	computeForces(force1, force2);
	computeRKparameters();
	x1 = x1 + (k1[0] + 2.*k2[0] + 2.*k3[0] + k4[0]) / 6.;
	x2 = x2 + (k1[1] + 2.*k2[1] + 2.*k3[1] + k4[1]) / 6.;
	std::vector<double> disp = { x1, x2 };

	return disp;
}

std::vector<double> RungeKutta4ODE::solveVelocity(void)
{
	x3 = x3 + (k1[2] + 2.*k2[2] + 2.*k3[2] + k4[2]) / 6.;
	x4 = x4 + (k1[3] + 2.*k2[3] + 2.*k3[3] + k4[3]) / 6.;
	std::vector<double> vel = { x3, x4 };
	return vel;
}

// Destructor
RungeKutta4ODE::~RungeKutta4ODE()
{
}