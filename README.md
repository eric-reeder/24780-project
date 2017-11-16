# 24780-project
Final project for 24-780.

## Project Description
For our project, we will be creating an app to help students learn about the behavior of dynamic systems, specifically the mass-spring-damper system. This tool will allow students to visialize how the system response changes given different masses, spring constants, damping constants, input forces, and physical setups. The user will be able to select the number of masses, springs, dampers, and input forces, as well as the values used for their relevant parameters. The system will then be animated in real time, and there will be live plots of the displacement and velocity of each of the masses.

## Coding Style Guidelines
### Comments
Comments should be employed liberally throughout your code to ensure that it's function is clear to anyone reading it. It is generally good practice to use comments to describe the function of any chunk of code, even within a function. In addition, there are some areas in which comments should always be used.

First, a comment should always be placed on the first lines after the function declaration to describe what the function does, as well as what the input and out parameters are. For example:

```C++
double unitStep(double time)
{
// Calculates the value of the unit step function as a function of time
// Inputs: time [s]
// Outputs: force [N]
    
    double outForce;
    
    if (time > 0)
    {
        outForce = 1.0;
    }
    
    else
    {
        outForce = 0.0;
    }
    
    return outForce;
}
```

Similarly, a comment should also be used when defining a new class. The comment should describe what the class is and how it should be used. For example:

```C++
class Spring
{
// Used to represent a spring object in the simulation. Each spring in the system should
// be represented by an instance of this class.

protected:
    int xPos; // X-position of spring in local graphics window
    int yPos; // Y-position of spring in local graphics window
    bool active; // Indicates if the spring is currently being used in system
    double equiLength; // Length of spring at equilibrium [m]
    double length; // Current length of spring [m]
    double springConst; // Spring constant [N/m]
    
public:
    Spring();
    
    double getEquiLength(void);
    double getLength(void);
    double getSpringConst(void);
    bool getState(void);
    
    void setLength(double newLength);
    void setSpringConst(double newSpringCosnt);
    void setState(bool newState);
    
    void draw(void);
};
```

Additionally, if you an abbreviation is used in your variable name (for example, abbreviating "displacement" as "disp"), you should include a comment giving a brief description of the variable:

```C++
double dispNext = 1.1; // Displacement of mass at next time step
```

In general, when in doubt, comments should be used. If there are more comments than needed, the reader will still understand the code. The same cannot be said if there are not enough comments.

### Class Structure and Headers
When writing a class, member variables should be either private or protected members. In order to access or change a member variable, there should be corresponding get or set functions. For example:

```C++
class Box
{
protected:
    int width;
    int height;

public:
    int getWidth(void) const;
    int getHeight(void) const;

    void setWidth(const int newWidth);
    void setHeight(const int newHeight);
};
```

Additionally, each class should be contained within it's own C++ and header file. The .cpp file should be named "ClassName.cpp", and the header should be named "ClassName.h". It is important to remember to use an include guard in each header file to ensure that each class is not accidentally defined twice. The include guard macro should be named "CLASSNAME_H". For example:

```C++
// Box.cpp

class Box
{
protected:
    int width;
    int height;

public:
    int getWidth(void) const;
    int getHeight(void) const;

    void setWidth(const int newWidth);
    void setHeight(const int newHeight);
};
```

```C++
// Box.h

#ifndef BOX_H
#define BOX_H

int Box::getWidth(void) const
{
    return width;
}


int Box::getHeight(void) const
{
    return height;
}


void setWidth(const int newWidth)
{
    width = newWidth;
}


void setHeight(const int newHeight)
{
    height = newHeight;
}

#endif /* BOX_H */
```

### Use of Non-Variable Constants (a.k.a Magic Numbers)
When using constants in your code, you should ALWAYS use a constant variable rather than typing out the numerical value of the constant (with a few exceptions). For example, if you wanted to create an array to store the displacement values at each of the 10 time steps in a simulation, it should be done in the following fashion:

```C++
const int TIME_STEPS = 10;
double displacement[TIME_STEPS];
```

Under no circumstances should the following syntax be used:

```C++
double displacement[10];
```

Non-variable constants should only be used in special cases, and typically should only be a value of 0 or 1. For example, an acceptable use would be when writing a for loop to loop through an array:

```C++
for (int i = 0; i < n; i++)
{
// Loop body here
}
```

Another acceptable use would be when it is necessary to access adjacent values of an array while looping through it.

```C++
for (int i = 1, i < n - 1, i++)
{
vel[i] = (disp[i+1] - disp[i-1]) / (2*dx);
}
```

### Variable, Function, and Class Naming
The name of any variable, function, or class should be descriptive such that someone unfamiliar with the code could tell what the variable represents.

For example, if we were using a variable to store a mass value, one should write:

```C++
int mass = 1;
```

An example of a bad variable variable name would be:

```C++
int m = 1;
```

Names of variables, functions, and classes should be kept as short as possible, particularly if they are used frequently. For example, if we were using a variable to store the displacement of a block at a the next time step, one might call it

```C++
double dispNext = 1.1;
```

Although descriptive, a bad variable name would be:

```C++
double displacementAtNextTimeStep = 1.1;
```

As previously mentioned, if you an abbreviation is used in your variable name (for example, abbreviating "displacement" as "disp" as in the above example), you should include a comment giving a brief description of the variable:

```C++
double dispNext = 1.1; // Displacement of mass at next time step
```

Single letter variable names should only be used for throwaway variables, such as variables used to iterate though a for loop:

```C++
for (int i = 0; i < max; i++)
{
    // Loop body here
}
```

When creating a variable, function, or member function, lower camel case should be used. This means that the first word should be lower case, and each following word should begin with an upper case letter. For example, if we were using a varaible to store the displacement of the block at the next time step, a value that will change with each iteration through the loop, it might be named:

```C++
double dispNext = 1.1;
```

When creating a class, upper camel case should be used. This means that each word, including the first word, should begin with an upper case letter. For example:

```C++
class DynamicSystemApp
{
    // Class body here
};
```

When creating a constant, upper case characters separated by underscores should be used. For example if we were creating a variable to store the value of width of the GUI window in pixels, a value that will never be changed at any point in the program, it might be named:

```C++
int SCREEN_WIDTH = 800;
```

### White Space
White space should be employed in a manner such that the code is easily readable. In general, sections of code that have similar functionality or are all working to complete a specific task should be seperated from other parts of the code by empty lines. Here are some general guidelines that should be followed:

When declaring a new function, loop, or other code artifact that requires use of curly braces, the curly braces should start on the next line after the declaration, and should close on the line after the last line of code contained within the braces. For example:

```C++
int main(void)
{
    // Main function body here
}
```

When writing mathematical expressions, terms should be seperated with spaces on either side of the operator seperating the terms:

```C++
double y = a*(x*x) + b*x + c;
```

Two lines should be left between function declarations:

```C++
int functionOne(void)
{
    // Function body here
}


int functionTwo(void)
{
    // Function body here
}
```

These are only some examples of practices to follow to ensure code is readable. In general, make your best effort to make the code easy to follow for someone who didn't write the code.
