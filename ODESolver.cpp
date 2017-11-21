// ODE Solver Implementation file

#include "ODESolver.h"
#include "Runge_Kutta.h"
#include "RungeKutta2ODE.h"
#include "RungeKutta4ODE.h"

// Constructor
ODESolver::ODESolver()
{
// Nullifying the pointers
	RK = nullptr;
	mass = nullptr;
	springStiffness = nullptr;
	dampCoefficient = nullptr;
	massNo = 0;
	springNo = 0;
	damperNo = 0;
}

// Function to initialize mass[]; Takes mass objects from the main()
void ODESolver::massInit(const Mass& m1, const Mass& m2)
{
	// Initializing the mass array for the solver
	this->massNo = (int)m1.getState() + (int)m2.getState();			// Determining 1 or 2 masses in the system
	this ->mass = new double[massNo];
	if(massNo == 2)
	{
		this ->mass[0] = m1.getMass();
		this ->mass[1] = m2.getMass();
	}
	else if(massNo = 1)
		this ->mass[0] = (int)(m1.getState()) * m1.getMass() + (int)(m2.getState()) * m2.getMass();
}

// Function to initialize springStiffness[]; Takes number of springs and their values from the main()
void ODESolver::springInit(const Spring& s1, const Spring& s2, const Spring& s3)
{
	// Initializing the spring stifness array for the solver
	// 3 springs (max) for 2 mass system and 1 spring for single mass system
	if(massNo == 2)
	{
		springNo = 3;
		this ->springStiffness = new double[springNo];
		this ->springStiffness[0] = (int)(s1.getState())*s1.getStiffness();
		this ->springStiffness[1] = (int)(s2.getState())*s2.getStiffness();
		this ->springStiffness[2] = (int)(s3.getState())*s3.getStiffness();
	}
	else if(massNo == 1)
	{
		springNo = 1;
		this ->springStiffness = new double[springNo];
		this ->springStiffness[0] = (int)(s1.getState()) * s1.getStiffness() + (int)(s3.getState()) * s3.getStiffness();
	}
}

// Function to initialize dampCoefficient[]; Takes number of dampers and their values from the main()
void ODESolver::damperInit(const Damper& d1, const Damper& d2, const Damper& d3)
{
	// Initializing the damper array for the solver
	// 3 dampers (max) for 2 mass system and 1 damper for single mass system
	if(massNo == 2)
	{
		damperNo = 3;
		this ->dampCoefficient = new double[damperNo];
		this ->dampCoefficient[0] = (int)(d1.getState())*d1.getCoefficient();
		this ->dampCoefficient[1] = (int)(d2.getState())*d2.getCoefficient();
		this ->dampCoefficient[2] = (int)(d3.getState())*d3.getCoefficient();
	}
	else if(massNo == 1)
	{
		damperNo = 1;
		this ->dampCoefficient = new double[damperNo];
		this ->dampCoefficient[0] = (int)(d1.getState())*d1.getCoefficient() + (int)(d3.getState())*d3.getCoefficient();
	}
}

// Function to initialize the forces
void ODESolver::forceInit(const Force& force1, const Force& force2)
{
	this ->force1 = force1;
	this ->force2 = force2;
}

// Function to solve the ODE for displacement and velocity
void ODESolver::solve(double timeStep, Mass& mass1, Mass& mass2)
{
	// Solves the ODE by calling the 2 ODE RK solver or the 4 ODE RK solver according to the number of masses
	if (massNo == 1)
	{
		RK = new RungeKutta2ODE;
		disp = RK->solveDisp(timeStep, mass, springStiffness, dampCoefficient, force1, force2);
		velocity = RK->solveVelocity();
		if (mass1.getState())
		{
			mass1.setPosition(mass1.getPosition() + disp[0]);		// Updating position of mass1
			mass1.setVelocity(velocity[0]);							// Updating the velocity of mass2
		}
		else
		{
			mass2.setPosition(mass2.getPosition() + disp[0]);		// Updating position of mass2
			mass2.setVelocity(velocity[0]);							// Updating the velocity of mass2
		}
	}
	else if (massNo == 2)
	{
		RK = new RungeKutta4ODE;
		// Updating displacements
		disp = RK->solveDisp(timeStep, mass, springStiffness, dampCoefficient, force1, force2);
		mass1.setPosition(mass1.getPosition() + disp[0]);		// Updating position of mass1
		mass2.setPosition(mass2.getPosition() + disp[1]);		// Updating position of mass2

		// Updating velocities
		velocity = RK->solveVelocity();
		mass1.setVelocity(velocity[0]);
		mass1.setVelocity(velocity[1]);
	}
}

/*
// Function to solve the ODE for velocity
void ODESolver::solveVelocity(double timeStep, Mass& mass1, Mass& mass2)
{
	// Solves the ODE by calling the 2 ODE RK solver or the 4 ODE RK solver according to the number of masses
	if (massNo == 1)
	{
		RK = new RungeKutta2ODE;
		velocity = RK->solveVelocity();
		if(mass1.getState())
			mass1.setVelocity(velocity[0]);
		else
			mass2.setVelocity(velocity[0]);
	}
	else if (massNo == 2)
	{
		RK = new RungeKutta4ODE;
		velocity = RK->solveVelocity();
		mass1.setVelocity(velocity[0]);
		mass1.setVelocity(velocity[1]);
	}
}
*/

void ODESolver::CleanUp()
{
// Releasing the requested memory
	delete RK;
	delete[] mass;
	delete[] springStiffness;
	delete[] dampCoefficient;
	
// Nullifying the pointers
	RK = nullptr;
	mass = nullptr;
	springStiffness = nullptr;
	dampCoefficient = nullptr;
}

// Function to reset the variables when required
void ODESolver::reset()
{
	CleanUp();
	velocity.resize(0);
	disp.resize(0);
	massNo = 0;
	springNo = 0;
	damperNo = 0;
}

ODESolver::~ODESolver()
{
	CleanUp();
}
