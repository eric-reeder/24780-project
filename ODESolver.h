// ODE_Solver header
// This header should be included in the main file

#ifndef __ODE_SOLVER_IS_INCLUDED__
#define __ODE_SOLVER_IS_INCLUDED__

#include "Runge_Kutta.h"
#include "Mass.h"
#include "Spring.h"
#include "Damper.h"
#include "Force.h"
#include<vector>

class ODESolver
{
protected:
	double *mass, *springStiffness, *dampCoefficient;			// Values of masses, spring stiffness and damping coefficients for solving the ODEs
																// Zeros will be stored wherever necessary (given from input)
	int massNo, springNo, damperNo;								// Number of masses, springs and dampers (Input for this will be given from the main())	
	Force force1, force2;									// Force objects containing info about the force types and values		
	double timeStep;											// Time step to be taken as input from the main()								
	double time;												// Total time
	std::vector<double> disp, velocity;										// Displacement and velocity at a particular time step
	RungeKutta *RK;												// Object for the Runge-Kutta solver

public:
	ODESolver();												// Constructor
	void massInit(const Mass&,const Mass&);							// Takes Mass objects from the main() and fills mass[]		
	void springInit(const Spring&,const Spring&,const Spring&);						// Takes Spring objects from the main() and fills springStiffness[]
	void damperInit(const Damper&, const Damper&, const Damper&);						// Takes an Damper objects from the main() and fills dampCoefficient[]
	void forceInit(const Force&, const Force&);							// Initializes the forcing functions; Takes Force objects from the main()
	void solve(double, Mass&, Mass&);									// Solves the ODE system for displacement and velocity; Takes timeStep and mass objects from the main()
																// It internally takes care of whether it's a 2 mass system or single mass system
																// User only needs to call this function from the main() and the displacement at corresponding time step will be calculated
	//void solveVelocity(double, Mass&, Mass&);								// Solves the ODE system for the velocity
																// User only needs to call this function from the main() and the velocity at corresponding time step will be calculated
	void reset();												// Reset the variables when user presses the reset button
	void CleanUp();												// To release memory
	~ODESolver();												// Destructor
};

#endif
