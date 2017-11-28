#include "UIWindowTest.h"

double UIWindowTest::getMass1Mass(void)
{
	return 1.0;
}

double UIWindowTest::getMass2Mass(void)
{
	return 1.0;
}

double UIWindowTest::getSpring1Stiffness(void)
{
	return 1.0;
}

double UIWindowTest::getSpring2Stiffness(void)
{
	return 1.0;
}

double UIWindowTest::getSpring3Stiffness(void)
{
	return 1.0;
}

double UIWindowTest::getDamper1Damping(void)
{
	return 0.5;
}

double UIWindowTest::getDamper2Damping(void)
{
	return 0.5;
}

double UIWindowTest::getDamper3Damping(void)
{
	return 0.5;
}

int UIWindowTest::getForce1Type(void)
{
	return 2;
}

double UIWindowTest::getForce1Value1(void)
{
	return 10.0;
}

double UIWindowTest::getForce1Value2(void)
{
	return 0.0;
}

int UIWindowTest::getForce2Type(void)
{
	return 2;
}

double UIWindowTest::getForce2Value1(void)
{
	return 10.0;
}

double UIWindowTest::getForce2Value2(void)
{
	return 0.0;
}

bool UIWindowTest::checkRunning(void)
{
	return true;
}

bool UIWindowTest::checkMouse(int mouseLeft, int mouseX, int mouseY)
{
	return false;
}
