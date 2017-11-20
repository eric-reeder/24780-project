#ifndef _PlotWindow_IS_INCLUDED_ 
#define _PlotWindow_IS_INCLUDED_

class PositionData
{ //This class creates the position data as a variable array 
protected: 
	double timestep; //timestep variable 
	double *position[]; //creates empty array for position data 

public: 
	PositionData(); //constructor
	~PositionData(); //destructor 
	void CleanUp(); //cleans up data 

	PositionData(const PositionData &incoming); //copy constructor 
	void CopyFrom(const PositionData &incoming);

	void GraphPosition(void); //graphs data
};

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