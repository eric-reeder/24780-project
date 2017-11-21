#ifndef _VelocityData_IS_INCLUDED_
#define _VelocityData_IS_INCLUDED_

class VelocityData
{//This class creates the velocity data as an incoming array
protected:
	double timestep;  //timestep variable 
	double *velocity[]; //creates empty array for velocity 

public:
	VelocityData(); //constructor
	~VelocityData(); //deconstructor 
	void CleanUp(); //cleans up data

	VelocityData(const VelocityData &incoming); //copy constructor 
	void CopyFrom(const VelocityData &incoming);

	void GraphVelocity(void); //graphs data 

};
#endif

