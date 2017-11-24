#ifndef _PositionData_IS_INCLUDED_
#define _PositionData_IS_INCLUDED_

class Position
{ //This class creates the position data as a variable array 
protected:
	double timestep; //timestep variable 
	double *position; //creates empty array for position data 

public:
	Position(); //constructor
	~Position(); //destructor 
	void CleanUp(); //cleans up data 

	Position(const Position &incoming); //copy constructor 
	void CopyFrom(const PositionData &incoming);

	void GraphPosition(void);
};

#endif