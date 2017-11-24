#include <stdio.h>
#include "Position.h"
#include "fsssimplewindow.h"

Position::Position()
{//This is the constructor for the position data. 
	position = NULL;
	CleanUp();
}

Position::~Position()
{//This is the destructor. 
	CleanUp();
}

void Position::CleanUp(void)
{//This deletes the position data
	if (NULL != position)
	{
		delete[] position;
	}
	position = NULL;
	timestep = 0; //initializes the time step 
}

Position::Position(const Position &incoming)
{
	position= nullptr;
	CopyFrom(incoming);
}

void Position::CopyFrom(const Position &incoming)
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

void Position::GraphPosition(void)
{
	glBegin(GL_LINE_STRIP);
	/*for(int i = 0; i)*/

}