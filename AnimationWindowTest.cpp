#include "GraphicsWindow.h"
#include "AnimationWindowTest.h"
#include "Mass.h"
#include "Spring.h"
#include "Damper.h"

void AnimationWindowTest::draw(Mass mass1, Mass mass2, Spring spring1, Spring spring2, Spring spring3, Damper damper1, Damper damper2, Damper damper3)
{
    drawBackground();
    drawBorder();
}
