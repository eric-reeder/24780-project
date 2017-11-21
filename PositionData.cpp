#include <stdio.h>
#include "PositionData.h"

PositionData::PositionData()
{//This is the constructor for the position data. 
	position = NULL;
	CleanUp();
}

PositionData::~PositionData()
{//This is the destructor. 
	CleanUp();
}

void PositionData::CleanUp(void)
{//This deletes the position data
	if (NULL != position)
	{
		delete[] position;
	}
	position = NULL;
	timestep = 0; //initializes the time step 
}

PositionData::PositionData(const PositionData &incoming)
{
	position= nullptr;
	CopyFrom(incoming);
}

void PositionData::CopyFrom(const PositionData &incoming)
{//Copy Constructor 
	if (&incoming != this)
	{
		CleanUp();
		position = new double[incoming.timestep];
		for (int i = 0; i<incoming.timestep; ++i)
		{
			position[i] = incoming.position[i];
		}
		timestep = incoming.timestep;
	}
}

