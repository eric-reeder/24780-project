#ifndef FORCE_H
#define FORCE_H

#include <vector>
class Force
{
protected:
	int type;									// Nature of the force; 0 for sine, 1 for exponential, 2 for constant
	std::vector<double> value;					// The values of coefficients in the forcing functions
												// For sine -> value[0] = amplitude, value[1] = frequency
												// For exp (Ae^(-k*t)) -> value[0] = amplitude (A), value[1] = k
												// For constant (c) -> value[0] = c


public:
	Force();
	void setType(int);							// Initializes the type of the function
	int getType() const;						// Returns the type of the force
	void setValue(double, double);				// Initializes the values of all coefficients in the forcing functions
												// Takes TWO values as parameters for sine and exp functions
												// Takes only ONE value as parameter for constant function
	std::vector<double> getValue() const;		// Returns the values of coefficients corresponding to a force


};

#endif 
