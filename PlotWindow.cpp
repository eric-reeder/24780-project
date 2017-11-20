#include <stdio.h>
#include <GraphingFunction.h>
#include "fssimplewindow.h"

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
	if (NULL != data)
	{
		delete[] dat;
	}
	dat = NULL;
	timestep = 0; //initializes the time step 
}

PositionData::PositionData(const PositionData &incoming)
{
	dat = nullptr;
	CopyFrom(incoming);
}

void PositionData::CopyFrom(const PositionData &incoming)
{//Copy Constructor 
	if (&incoming != this)
	{
		CleanUp();
		dat = new char[incoming.timestep];
		for (int i = 0; i<incoming.timestep; ++i)
		{
			dat[i] = incoming.dat[i];
		}
		timestep = incoming.timestep;
	}
}

void PositionData::GraphPosition(void)
{//This grapsh the position data 
	double timestep;
	glColor3ub(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	const double y = timestep*x;
}

//This repeats for the Velocity Data
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
	if (NULL != data)
	{
		delete[] dat;
	}
dat = NULL;
timestep = 0; //initializes the time step 
}

VelocityData::VelocityData(const VelocityData &incoming)
{
	dat = nullptr;
	CopyFrom(incoming);
}

void VelocityData::CopyFrom(const VelocityData &incoming)
{//Copy Constructor 
	if (&incoming != this)
	{
		CleanUp();
		dat = new char[incoming.timestep];
		for (int i = 0; i<incoming.timestep; ++i)
		{
			dat[i] = incoming.dat[i];
		}
		timestep = incoming.timestep;
	}
}


void VelocityData::GraphVelocity(void)
{
	double timestep;
	glColor3ub(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	const double y = timestep*x;
}