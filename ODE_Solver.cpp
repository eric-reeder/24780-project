// ODE Solver Implementation file

#include "ODE_Solver.h"
#include "Runge_Kutta.h"
#include "RungeKutta2ODE.h"

// Constructor
ODE_Solver::ODE_Solver()
{
// Nullifying the pointers
	RK = nullptr;
	mass = nullptr;
	springStiffness = nullptr;
	dampCoefficient = nullptr;
	disp = 0;
	velocity = 0;
	massNo = 0;
	springNo = 0;
	damperNo = 0;
}

// Function to initialize mass[]; Takes number of masses and their values from the main()
void ODE_Solver::mass_init(int massNo, const double mass[])
{
	// Initializing the mass array for the solver
	this->massNo = massNo;
	mass = new double[massNo];
	if(mass != nullptr && mass != this ->mass)
		for (int i = 0; i < massNo; i++)
			this -> mass[i] = mass[i];
}

// Function to initialize springStiffness[]; Takes number of springs and their values from the main()
void ODE_Solver::spring_init(int springNo, const double spring[])
{
	// Initializing the spring stifness array for the solver
	this->springNo = springNo;
	springStiffness = new double[springNo];
	if (spring != nullptr && spring != springStiffness)
		for (int i = 0; i < springNo; i++)
			springStiffness[i] = spring[i];
}

// Function to initialize dampCoefficient[]; Takes number of dampers and their values from the main()
void ODE_Solver::damper_init(int damperNo, const double damper[])
{
	// Initializing the damper array for the solver
	this->damperNo = damperNo;
	dampCoefficient = new double[damperNo];
	if (damper != nullptr && damper != dampCoefficient)
		for (int i = 0; i < damperNo; i++)
			dampCoefficient[i] = damper[i];
}

// Function to solve the ODE for displacement
double ODE_Solver::solveDisp(double timeStep)
{
	// Solves the ODE by calling the 2 ODE RK solver or the 4 ODE RK solver according to the number of masses
	if (massNo == 1)
	{
		RK = new RungeKutta2ODE;
		disp = RK->solveDisp(timeStep);
	}
	else if (massNo == 2)
	{
		RK = new RungeKutta4ODE;
		disp = RK->solveDisp(timeStep);
	}
	return disp;
}

// Function to solve the ODE for velocity
double ODE_Solver::solveVelocity(double timeStep)
{
	// Solves the ODE by calling the 2 ODE RK solver or the 4 ODE RK solver according to the number of masses
	if (massNo == 1)
	{
		RK = new RungeKutta2ODE;
		velocity = RK->solveVelocity(timeStep);
	}
	else if (massNo == 2)
	{
		RK = new RungeKutta4ODE;
		velocity = RK->solveVelocity(timeStep);
	}
	return disp;
}

void ODE_Solver::CleanUp()
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
void ODE_Solver::reset()
{
	CleanUp();
	disp = 0;
	velocity = 0;
	massNo = 0;
	springNo = 0;
	damperNo = 0;
}

ODE_Solver::~ODE_Solver()
{
	CleanUp();
}