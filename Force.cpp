#include "Force.h"
#include<assert.h>

// Constructor
Force::Force()
{
	type = -1;
}

void Force::setType(int force_type)
{
	type = force_type;
}

int Force::getType() const
{
	return type;
}

void Force::setValue(double val1, double val2 = 0)
{
	assert(type != -1);										// To ensure the type has been initialized
															// Program will stop running and point to this error
	if (type == 2)
	{
		value.push_back(val1);								// Constant function
	}
	else
	{
		value.push_back(val1);								// Sine or exponential function
		value.push_back(val2);
	}
}

std::vector<double> Force::getValue() const
{
	return value;
}
