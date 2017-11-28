#include "DynamicSystemApp.h"

int main(void)
{
	const int appWidth = 1400;
	const int appHeight = 700;
	DynamicSystemApp app(appWidth, appHeight);
	app.run();
	return 0;
}
