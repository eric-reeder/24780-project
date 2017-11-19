// Base class for Runge-Kutta (4th order)solver
// The 2-mass system solver and single mass system solver will be derived from this

#ifndef __RK_IS_INCLUDED__
#define __RK_IS_INCLUDED__

class RungeKutta
{
protected:
	double time, timeStep;
public:
	RungeKutta();
	virtual double solveDisp(double timeStep,double time, force1, force2) = 0;
	virtual double solveVelocity(double) = 0;
	~RungeKutta();
};
#endif