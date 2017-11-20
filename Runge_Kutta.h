// Base class for Runge-Kutta (4th order)solver
// The 2-mass system solver and single mass system solver will be derived from this

#ifndef __RK_IS_INCLUDED__
#define __RK_IS_INCLUDED__

#include<vector>
#include "Force.h"

class RungeKutta
{
protected:
	double time, timeStep;
public:
	RungeKutta();
	virtual std::vector<double> solveDisp(double tS, double m[2], double sS[3], double dC[3], Force force1, Force force2) = 0;
	virtual std::vector<double> solveVelocity(void) = 0;
	~RungeKutta();
};
#endif