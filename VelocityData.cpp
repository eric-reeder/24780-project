#include "VelocityData.h"
#include <stdio.h>

VelocityData::VelocityData()
{//This is the constructor for the position data. 
	velocity = NULL;
	CleanUp();
}

VelocityData::~VelocityData()
{//This is the destructor. 
	CleanUp();
}

void VelocityData::CleanUp(void)
{//This deletes the position data
	if (NULL != velocity)
	{
		delete[] velocity;
	}
	velocity = NULL;
	timestep = 0; //initializes the time step 
}

VelocityData::VelocityData(const VelocityData &incoming)
{
	velocity = nullptr;
	CopyFrom(incoming);
}

void VelocityData::CopyFrom(const VelocityData &incoming)
{//Copy Constructor 
	if (&incoming != this)
	{
		CleanUp();
		velocity = new double[incoming.timestep];
		for (int i = 0; i<incoming.timestep; ++i)
		{
			velocity[i] = incoming.velocity[i];
		}
		timestep = incoming.timestep;
	}
}


