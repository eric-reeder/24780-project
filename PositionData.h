#ifndef _PositionData_IS_INCLUDED_
#define _PositionData_IS_INCLUDED_

class PositionData
{ //This class creates the position data as a variable array 
protected:
	double timestep; //timestep variable 
	double *position; //creates empty array for position data 

public:
	PositionData(); //constructor
	~PositionData(); //destructor 
	void CleanUp(); //cleans up data 

	PositionData(const PositionData &incoming); //copy constructor 
	void CopyFrom(const PositionData &incoming);
};

#endif