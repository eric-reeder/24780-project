#ifndef _VelocityData_IS_INCLUDED_
#define _VelocityData_IS_INCLUDED_

class Velocity
{//This class creates the velocity data as an incoming array with the appropriate constructors and deconstructors
//and then plots the data

protected:
	double timeStep;  //timestep variable 
	double *velocity; //creates empty array for velocity 

public:
	Velocity(); //constructor
	~Velocity(); //deconstructor 
	void CleanUp(); //cleans up data

	Velocity(const Velocity &incoming); //copy constructor 
	void CopyFrom(const Velocity &incoming);

	void DrawVelocityGraph(void); //function to draw velocity graph

};
#endif

