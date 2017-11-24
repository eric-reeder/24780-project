#include "Velocity.h"
#include "fsssimplewindow.h"
#include <stdio.h>

Velocity::Velocity()
{//This is the constructor for the velocity data. 
	velocity = NULL; 
	CleanUp();
}

Velocity::~Velocity()
{//This is the destructor. 
	CleanUp();
}

void Velocity::CleanUp(void)
{//This deletes the position data
	if (NULL != velocity)
	{
		delete[] velocity;
	}
	velocity = NULL;
	timeStep = 0; //initializes the time step 
}

Velocity::Velocity(const Velocity &incoming)
{
	velocity = nullptr;
	CopyFrom(incoming);
}

void Velocity::CopyFrom(const Velocity &incoming)
{//Copy Constructor 
	if (&incoming != this)
	{
		CleanUp();
		velocity = new double[incoming.timeStep];
		for (int i = 0; i<incoming.timeStep; ++i)
		{
			velocity[i] = incoming.velocity[i];
		}
		timeStep = incoming.timeStep;
	}
}

void Velocity::DrawVelocityGraph(void)
{
	glBegin(GL_LINE_STRIP);


}

