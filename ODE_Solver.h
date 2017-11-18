// ODE_Solver header
// This header should be included in the main file

#ifndef __ODE_SOLVER_IS_INCLUDED__
#define __ODE_SOLVER_IS_INCLUDED__

#include "Runge_Kutta.h"
#include "Mass.h"
#include "Spring.h"
#include "Damper.h"
#include "Force.h"

class ODE_Solver
{
protected:
	double *mass, *springStiffness, *dampCoefficient;			// Values of masses, spring stiffness and damping coefficients for solving the ODEs
																// Zeros will be stored wherever necessary (given from input)
	int massNo, springNo, damperNo;								// Number of masses, springs and dampers (Input for this will be given from the main())	
	int forceNo;												// Number of forces (1:1 relation with number of masses)
	int *forceType;												// Force type (0 for sine, 1 for exponential, 2 for constant)
	double *forceValue;											// Values of amplitudes, constants etc. in the forcing functions
	double timeStep;											// Time step to be taken as input from the main()								
	double disp, velocity;										// Displacement and velocity at a particular time step
	RungeKutta *RK;												// Object for the Runge-Kutta solver

public:
	ODE_Solver();												// Constructor
	void mass_init(int,const Mass&,const Mass&);							// Takes Mass objects from the main() and fills mass[]		
	void spring_init(int,const Spring&,const Spring&,const Spring&);						// Takes Spring objects from the main() and fills springStiffness[]
	void damper_init(int,const Damper&, const Damper&, const Damper&);						// Takes an Damper objects from the main() and fills dampCoefficient[]
	void force_init(int, const Force&, const Force&);							// Initializes the forcing functions; Takes Force objects from the main()
	double solveDisp(double);									// Solves the ODE system for displacement; Takes timeStep from the main()
																// It internally takes care of whether it's a 2 mass system or single mass system
																// User only needs to call this function from the main() and the displacement at corresponding time step will be calculated
	double solveVelocity(double);								// Solves the ODE system for the velocity
																// User only needs to call this function from the main() and the velocity at corresponding time step will be calculated
	void reset();												// Reset the variables when user presses the reset button
	void CleanUp();												// To release memory
	~ODE_Solver();												// Destructor
};

#endif
