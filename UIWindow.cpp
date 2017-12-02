#include "UIWindow.h"



#include "GraphicsWindow.h"
#include "Slider.h"
#include "RadioButton.h"
#include "ysglfontdata.h"
#include "fssimplewindow.h"

void UIWindow::Initialize(void) 
{
	mass1.Initialize(width, height, yPosition + ((1.5*height) / 26));
	mass2.Initialize(width, height, yPosition + ((3.5*height) / 26));
	Spring1.Initialize(width, height, yPosition + ((5.5*height) / 26));
	Spring2.Initialize(width, height, yPosition + ((7.5*height) / 26));
	Spring3.Initialize(width, height, yPosition + ((9.5*height) / 26));
	Dampener1.Initialize(width, height, yPosition + ((11.5*height) / 26));
	Dampener2.Initialize(width, height, yPosition + ((13.5*height) / 26));
	Dampener3.Initialize(width, height, yPosition + ((15.5*height) / 26));
	r1.Initialize(width, yPosition + ((17.5*height) / 26));
	Amplitude1.Initialize(width, height, yPosition + ((18.5*height) / 26));
	Frequency1.Initialize(width, height, yPosition + ((19.5*height) / 26));
	r2.Initialize(width, yPosition + ((21.5*height) / 26));
	Amplitude2.Initialize(width, height, yPosition + ((22.5*height) / 26));
	Frequency2.Initialize(width, height, yPosition + ((23.5*height) / 26));
	Mass1Check.Initialize(width, yPosition + ((1.5*height) / 26));
	Mass2Check.Initialize(width, yPosition + ((3.5*height) / 26));
	Spring1Check.Initialize(width, yPosition + ((5.5*height) / 26));
	Spring2Check.Initialize(width, yPosition + ((7.5*height) / 26));
	Spring3Check.Initialize(width, yPosition + ((9.5*height) / 26));
	Dampener1Check.Initialize(width, yPosition + ((11.5*height) / 26));
	Dampener2Check.Initialize(width, yPosition + ((13.5*height) / 26));
	Dampener3Check.Initialize(width, yPosition + ((15.5*height) / 26));
	

}


const double UIWindow::getMass1Mass(void)
{
	return mass1.SliderOutput(10,0);
}
const double UIWindow::getMass2Mass(void)
{
	return mass2.SliderOutput(10,0);
}
const double UIWindow::getSpring1Stiffness(void)
{
	return Spring1.SliderOutput(400,100);
}
const double UIWindow::getSpring2Stiffness(void)
{
	return Spring2.SliderOutput(400,100);
}
const double UIWindow::getSpring3Stiffness(void)
{
	return Spring3.SliderOutput(400,100);
}
const double UIWindow::getDamper1Damping(void)
{
	return Dampener1.SliderOutput(10,0);
}
const double UIWindow::getDamper2Damping(void)
{
	return Dampener2.SliderOutput(10,0);
}
const double UIWindow::getDamper3Damping(void)
{
	return Dampener3.SliderOutput(10,0);
}
const int UIWindow::getForce1Type(void)
{
	return r1.RadioOutput();
}
const int UIWindow::getForce2Type(void)
{
	return r2.RadioOutput();
}
const double UIWindow::getForce1Value1(void)
{
	return Amplitude1.SliderOutput(100,0);
}
const double UIWindow::getForce1Value2(void)
{
	return Frequency1.SliderOutput(100,0);
}
const double UIWindow::getForce2Value1(void)
{
	return Amplitude2.SliderOutput(100,0);
}
const double UIWindow::getForce2Value2(void)
{
	return Frequency2.SliderOutput(100,0);
}

void UIWindow::draw(void)
{
	const double leftMargin = width / 20;
	const int fontHeight = 12;
	const int fontWidth = 8;
	const double margin = 12;
	const double radioLabelMargin = 15;
	const double startPosition = xPosition + leftMargin;

	drawBackground();
	drawBorder();
	
	mass1.DrawSlider();
	glRasterPos2d(mass1.returnXValue() - margin, mass1.returnYValue() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("0");
	glRasterPos2d(mass1.returnXValue() + mass1.returnWidthValue() + margin, mass1.returnYValue() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("10");
	glRasterPos2d(startPosition, ((1*height)/26) + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("Mass 1:");

	Mass1Check.DrawRadio(2);
	glRasterPos2d(startPosition + (1*radioLabelMargin/3), Mass1Check.returnCentreY() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("In");
	glRasterPos2d(startPosition + (2*radioLabelMargin/3) + Mass1Check.returnRadioSpaceMargin2(), Mass1Check.returnCentreY() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("Not In");


	mass2.DrawSlider();

	glRasterPos2d(mass2.returnXValue() - margin, mass2.returnYValue() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("0");
	glRasterPos2d(mass2.returnXValue() + mass2.returnWidthValue() + margin, mass2.returnYValue() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("10");
	glRasterPos2d(startPosition, ((3*height)/26) + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("Mass 2:");

	Mass2Check.DrawRadio(2);
	glRasterPos2d(startPosition + (2*radioLabelMargin/3), Mass2Check.returnCentreY() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("In");
	glRasterPos2d(startPosition + (2*radioLabelMargin/3) + Mass2Check.returnRadioSpaceMargin2(), Mass2Check.returnCentreY() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("Not In");

	Spring1.DrawSlider();

	glRasterPos2d(Spring1.returnXValue() - 2*margin, Spring1.returnYValue() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("100");
	glRasterPos2d(Spring1.returnXValue() + Spring1.returnWidthValue() + margin, Spring1.returnYValue() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("500");
	glRasterPos2d(startPosition, ((5*height)/26) + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("Spring1:");


	Spring1Check.DrawRadio(2);
	glRasterPos2d(startPosition + (2*radioLabelMargin/3), Spring1Check.returnCentreY() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("In");
	glRasterPos2d(startPosition + (2*radioLabelMargin/3) + Spring1Check.returnRadioSpaceMargin2(), Spring1Check.returnCentreY() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("Not In");

	Spring2.DrawSlider();

	glRasterPos2d(Spring2.returnXValue() - 2*margin, Spring2.returnYValue() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("100");
	glRasterPos2d(Spring2.returnXValue() + Spring2.returnWidthValue() + margin, Spring2.returnYValue() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("500");
	glRasterPos2d(startPosition, ((7*height)/26) + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("Spring2:");

	Spring2Check.DrawRadio(2);
	glRasterPos2d(startPosition + (2*radioLabelMargin/3), Spring2Check.returnCentreY() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("In");
	glRasterPos2d(startPosition + (2*radioLabelMargin/3) + Spring2Check.returnRadioSpaceMargin2(), Spring2Check.returnCentreY() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("Not In");

	Spring3.DrawSlider();

	glRasterPos2d(Spring3.returnXValue() - 2*margin, Spring3.returnYValue() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("100");
	glRasterPos2d(Spring3.returnXValue() + Spring3.returnWidthValue() + margin, Spring3.returnYValue() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("500");
	glRasterPos2d(startPosition, ((9*height) / 26) + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("Spring3:");

	Spring3Check.DrawRadio(2);
	glRasterPos2d(startPosition + (2*radioLabelMargin/3), Spring3Check.returnCentreY() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("In");
	glRasterPos2d(startPosition + (2*radioLabelMargin/3) + Spring3Check.returnRadioSpaceMargin2(), Spring3Check.returnCentreY() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("Not In");

	Dampener1.DrawSlider();

	glRasterPos2d(Dampener1.returnXValue() - margin, Dampener1.returnYValue() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("0");
	glRasterPos2d(Dampener1.returnXValue() + Dampener1.returnWidthValue() + margin, Dampener1.returnYValue() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("10");
	glRasterPos2d(startPosition, ((11*height)/26) + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("Dampener1:");

	Dampener1Check.DrawRadio(2);
	glRasterPos2d(startPosition + (2*radioLabelMargin/3), Dampener1Check.returnCentreY() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("In");
	glRasterPos2d(startPosition + (2*radioLabelMargin/3) + Dampener1Check.returnRadioSpaceMargin2(), Dampener1Check.returnCentreY() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("Not In");

	Dampener2.DrawSlider();

	glRasterPos2d(Dampener2.returnXValue() - margin, Dampener2.returnYValue() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("0");
	glRasterPos2d(Dampener2.returnXValue() + Dampener2.returnWidthValue() + margin, Dampener2.returnYValue() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("10");
	glRasterPos2d(startPosition, ((13*height) / 26) + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("Dampener2:");

	Dampener2Check.DrawRadio(2);
	glRasterPos2d(startPosition + (2*radioLabelMargin/3), Dampener2Check.returnCentreY() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("In");
	glRasterPos2d(startPosition + (2*radioLabelMargin/3) + Dampener2Check.returnRadioSpaceMargin2(), Dampener2Check.returnCentreY() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("Not In");

	Dampener3.DrawSlider();

	glRasterPos2d(Dampener3.returnXValue() - margin, Dampener3.returnYValue() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("0");
	glRasterPos2d(Dampener3.returnXValue() + Dampener3.returnWidthValue() + margin, Dampener3.returnYValue() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("10");
	glRasterPos2d(startPosition, ((15*height) / 26) + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("Dampener3:");

	Dampener3Check.DrawRadio(2);
	glRasterPos2d(startPosition + (2*radioLabelMargin/3), Dampener3Check.returnCentreY() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("In");
	glRasterPos2d(startPosition + (2*radioLabelMargin/3) + Dampener3Check.returnRadioSpaceMargin2(), Dampener3Check.returnCentreY() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("Not In");

	glRasterPos2d(startPosition, ((17*height)/26) + (double)fontHeight/2 );
	YsGlDrawFontBitmap8x12("Force 1:");
	r1.DrawRadio(3);
	glRasterPos2d(startPosition + (2*radioLabelMargin/3), r1.returnCentreY() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("Constant");
	glRasterPos2d(startPosition + (2*radioLabelMargin/3) + r1.returnRadioSpaceMargin1(), r1.returnCentreY() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("Exponential");
	glRasterPos2d(startPosition + (2*radioLabelMargin/3) + (2 * r1.returnRadioSpaceMargin1()), r1.returnCentreY() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("Sinusoidal");
	Amplitude1.DrawSlider();
	glRasterPos2d(Amplitude1.returnXValue() - margin, Amplitude1.returnYValue() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("0");
	glRasterPos2d(Amplitude1.returnXValue() + Amplitude1.returnWidthValue() + margin, Amplitude1.returnYValue() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("100");
	glRasterPos2d(startPosition, Amplitude1.returnYValue() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("Amplitude:");
	Frequency1.DrawSlider();
	glRasterPos2d(Frequency1.returnXValue() - margin, Frequency1.returnYValue() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("0");
	glRasterPos2d(Frequency1.returnXValue() + Frequency1.returnWidthValue() + margin, Frequency1.returnYValue() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("100");

	glRasterPos2d(startPosition, Frequency1.returnYValue() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("Frequency:");

	glRasterPos2d(startPosition, ((21*height) / 26) + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("Force 2:");

	r2.DrawRadio(3);
	glRasterPos2d(startPosition + (2*radioLabelMargin/3), r2.returnCentreY() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("Constant");
	glRasterPos2d(startPosition + (2*radioLabelMargin/3) + r2.returnRadioSpaceMargin1(), r2.returnCentreY() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("Exponential");
	glRasterPos2d(startPosition + (2*radioLabelMargin/3) + (2 * r2.returnRadioSpaceMargin1()), r2.returnCentreY() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("Sinusoidal");

	Amplitude2.DrawSlider();
	glRasterPos2d(Amplitude2.returnXValue() - margin, Amplitude2.returnYValue() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("0");
	glRasterPos2d(Amplitude2.returnXValue() + Amplitude2.returnWidthValue() + margin, Amplitude2.returnYValue() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("100");
	glRasterPos2d(startPosition, Amplitude2.returnYValue() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("Amplitude:");

	Frequency2.DrawSlider();
	glRasterPos2d(Frequency2.returnXValue() - margin, Frequency2.returnYValue() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("0");
	glRasterPos2d(Frequency2.returnXValue() + Frequency2.returnWidthValue() + margin, Frequency2.returnYValue() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("100");

	glRasterPos2d(startPosition, Frequency2.returnYValue() + (double)fontHeight / 2);
	YsGlDrawFontBitmap8x12("Frequency:");

	DrawStart(((24.5*height)/26));

	


}
void UIWindow::DrawStart(double sliderYCoord)
{
	startX = width / 2;
	startY = sliderYCoord;
	startWidth = 40;
	startHeight = 40;
	double playHeight = 20;
	double playWidth = 20;


	glBegin(GL_QUADS);


	glColor3ub(255, 255, 0);
	glVertex2d(startX + startWidth / 2, startY);
	glVertex2d(startX - startWidth / 2, startY);
	glVertex2d(startX - startWidth, startY + startHeight);
	glVertex2d(startX + startWidth / 2, startY + startHeight);

	glColor3ub(0, 255, 0);
	glVertex2d(startX - startWidth / 2, startY);
	glVertex2d(startX - startWidth / 2 - startWidth, startY);
	glVertex2d(startX - startWidth / 2 - startWidth, startY + startHeight);
	glVertex2d(startX - startWidth / 2, startY + startHeight);

	glColor3ub(255, 0, 0);
	glVertex2d(startX + startWidth / 2, startY);
	glVertex2d(startX + startWidth / 2 + startWidth, startY);
	glVertex2d(startX + startWidth / 2 + startWidth, startY + startHeight);
	glVertex2d(startX + startWidth / 2, startY + startHeight);

	glColor3ub(0, 0, 0);
	glVertex2d(startX - startWidth / 6 + playWidth / 6, startY + startHeight / 2 - playHeight / 2);
	glVertex2d(startX - startWidth / 6 + playWidth / 6, startY + startHeight / 2 + playHeight / 2);
	glVertex2d(startX - startWidth / 6 - playWidth / 6, startY + startHeight / 2 + playHeight / 2);
	glVertex2d(startX - startWidth / 6 - playWidth / 6, startY + startHeight / 2 - playHeight / 2);


	glVertex2d(startX + startWidth / 6 + playWidth / 6, startY + startHeight / 2 - playHeight / 2);
	glVertex2d(startX + startWidth / 6 + playWidth / 6, startY + startHeight / 2 + playHeight / 2);
	glVertex2d(startX + startWidth / 6 - playWidth / 6, startY + startHeight / 2 + playHeight / 2);
	glVertex2d(startX + startWidth / 6 - playWidth / 6, startY + startHeight / 2 - playHeight / 2);


	glColor3ub(0, 0, 0);
	glVertex2d(startX + startWidth - playWidth/2, startY + startHeight / 2 - playHeight / 2);
	glVertex2d(startX + startWidth - playWidth / 2, startY + startHeight / 2 + playHeight / 2);
	glVertex2d(startX + startWidth + playWidth / 2, startY + startHeight / 2 + playHeight / 2);
	glVertex2d(startX + startWidth + playWidth / 2, startY + startHeight / 2 - playHeight / 2);



	glEnd();
	glColor3ub(0, 0, 0);

	glBegin(GL_TRIANGLES);
	glVertex2d(startX - startWidth  - playWidth / 2, startY + startHeight / 2 + playHeight / 2);
	glVertex2d(startX - startWidth  - playWidth / 2, startY + startHeight / 2 - playHeight / 2);
	glVertex2d(startX - startWidth  + playWidth / 2, startY + startHeight / 2);
	glEnd();


}

const double UIWindow::returnStartX(void)
{
	return startX;
}
const double UIWindow::returnStartY(void)
{
	return startY;
}

const double UIWindow::returnStartHeight(void)
{
	return startHeight;
}

const double UIWindow::returnStartWidth(void)
{
	return startWidth;
}
void UIWindow::returnOn(const int play)
{
	On = play;
	
}


const int UIWindow::onval(void) const
{
	return On;
}
const bool UIWindow::checkMouse()
{
	int lb, mb, rb, mx, my;
	FsGetMouseEvent(lb, mb, rb, mx, my);
	if (1 == lb)
	{
		if ((double)mx >= mass1.returnXValue() && (double)mx <= mass1.returnXValue() + mass1.returnWidthValue() && (double)my <= mass1.returnYValue() + mass1.returnHeightValue() && (double)my >= mass1.returnYValue() - mass1.returnHeightValue())
		{
			mass1.SetValue((int)mx);

			
		}
		if ((double)mx >= mass2.returnXValue() && (double)mx <= mass2.returnXValue() + mass2.returnWidthValue() && (double)my <= mass2.returnYValue() + mass2.returnHeightValue() && (double)my >= mass2.returnYValue() - mass2.returnHeightValue())
		{
			mass2.SetValue(mx);
		}
		if ((double)mx >= Spring1.returnXValue() && (double)mx <= Spring1.returnXValue() + Spring1.returnWidthValue() && (double)my <= Spring1.returnYValue() + Spring1.returnHeightValue() && (double)my >= Spring1.returnYValue() - Spring1.returnHeightValue())
		{
			Spring1.SetValue(mx);
		}
		if ((double)mx >= Spring2.returnXValue() && (double)mx <= Spring2.returnXValue() + Spring2.returnWidthValue() && (double)my <= Spring2.returnYValue() + Spring2.returnHeightValue() && (double)my >= Spring2.returnYValue() - Spring2.returnHeightValue())
		{
			Spring2.SetValue(mx);
		}

		if ((double)mx >= Spring3.returnXValue() && (double)mx <= Spring3.returnXValue() + Spring3.returnWidthValue() && (double)my <= Spring3.returnYValue() + Spring3.returnHeightValue() && (double)my >= Spring3.returnYValue() - Spring3.returnHeightValue())
		{
			Spring3.SetValue(mx);
		}

		if ((double)mx >= Dampener1.returnXValue() && (double)mx <= Dampener1.returnXValue() + Dampener1.returnWidthValue() && (double)my <= Dampener1.returnYValue() + Dampener1.returnHeightValue() && (double)my >= Dampener1.returnYValue() - Dampener1.returnHeightValue())
		{
			Dampener1.SetValue(mx);
		}

		if ((double)mx >= Dampener2.returnXValue() && (double)mx <= Dampener2.returnXValue() + Dampener2.returnWidthValue() && (double)my <= Dampener2.returnYValue() + Dampener2.returnHeightValue() && (double)my >= Dampener2.returnYValue() - Dampener2.returnHeightValue())
		{
			Dampener2.SetValue(mx);
		}
		if ((double)mx >= Dampener3.returnXValue() && (double)mx <= Dampener3.returnXValue() + Dampener3.returnWidthValue() && (double)my <= Dampener3.returnYValue() + Dampener3.returnHeightValue() && (double)my >= Dampener3.returnYValue() - Dampener3.returnHeightValue())
		{
			Dampener3.SetValue(mx);
		}

		if ((double)mx >= Amplitude1.returnXValue() && (double)mx <= Amplitude1.returnXValue() + Amplitude1.returnWidthValue() && (double)my <= Amplitude1.returnYValue() + Amplitude1.returnHeightValue() && (double)my >= Amplitude1.returnYValue() - Amplitude1.returnHeightValue())
		{
			Amplitude1.SetValue(mx);
		}
		if ((double)mx >= Amplitude2.returnXValue() && (double)mx <= Amplitude2.returnXValue() + Amplitude2.returnWidthValue() && (double)my <= Amplitude2.returnYValue() + Amplitude2.returnHeightValue() && (double)my >= Amplitude2.returnYValue() - Amplitude2.returnHeightValue())
		{
			Amplitude2.SetValue(mx);
		}
		if ((double)mx >= Frequency1.returnXValue() && (double)mx <= Frequency1.returnXValue() + Frequency1.returnWidthValue() && (double)my <= Frequency1.returnYValue() + Frequency1.returnHeightValue() && (double)my >= Frequency1.returnYValue() - Frequency1.returnHeightValue())
		{
			Frequency1.SetValue(mx);
		}

		if ((double)mx >= Frequency2.returnXValue() && (double)mx <= Frequency2.returnXValue() + Frequency2.returnWidthValue() && (double)my <= Frequency2.returnYValue() + Frequency2.returnHeightValue() && (double)my >= Frequency2.returnYValue() - Frequency2.returnHeightValue())
		{
			Frequency2.SetValue(mx);
		}
		if ((double)mx <= r1.returnCentreX() + r1.returnRadius() && (double)mx >= r1.returnCentreX() - r1.returnRadius() && (double)my <= r1.returnCentreY() + r1.returnRadius() && (double)my >= r1.returnCentreY() - r1.returnRadius())
		{
			//DrawCircle(r1.returnCentreX(), r1.returnCentreY(), 4, 1);
			r1.SetValue(2);
		}

		if ((double)mx <= r1.returnCentreX() + r1.returnRadioSpaceMargin1() + r1.returnRadius() && (double)mx >= r1.returnCentreX() + r1.returnRadioSpaceMargin1() - r1.returnRadius() && (double)my <= r1.returnCentreY() + r1.returnRadius() && (double)my >= r1.returnCentreY() - r1.returnRadius())
		{
			//DrawCircle(r1.returnCentreX() + r1.returnRadioSpaceMargin1(), r1.returnCentreY(), 4, 1);
			r1.SetValue(1);
		}
		if ((double)mx <= r1.returnCentreX() + (2 * r1.returnRadioSpaceMargin1()) + r1.returnRadius() && (double)mx >= r1.returnCentreX() + (2 * r1.returnRadioSpaceMargin1()) - r1.returnRadius() && (double)my <= r1.returnCentreY() + r1.returnRadius() && (double)my >= r1.returnCentreY() - r1.returnRadius())
		{
			//DrawCircle(r1.returnCentreX() + (2 * r1.returnRadioSpaceMargin1()), r1.returnCentreY(), 4, 1);
			r1.SetValue(0);
		}
		if (r1.RadioOutput() == 2)
		{
			Frequency1.SetValue(Frequency1.returnXValue());
		}
		if ((double)mx <= r2.returnCentreX() + r2.returnRadius() && (double)mx >= r2.returnCentreX() - r2.returnRadius() && (double)my <= r2.returnCentreY() + r2.returnRadius() && (double)my >= r2.returnCentreY() - r2.returnRadius())
		{
			//DrawCircle(r2.returnCentreX(), r2.returnCentreY(), 4, 1);
			r2.SetValue(2);
		}

		if ((double)mx <= r2.returnCentreX() + r2.returnRadioSpaceMargin1() + r2.returnRadius() && (double)mx >= r2.returnCentreX() + r2.returnRadioSpaceMargin1() - r2.returnRadius() && (double)my <= r2.returnCentreY() + r2.returnRadius() && (double)my >= r2.returnCentreY() - r2.returnRadius())
		{
			//DrawCircle(r2.returnCentreX() + radioSpaceMargin, r2.returnCentreY(), 4, 1);
			r2.SetValue(1);
		}
		if ((double)mx <= r2.returnCentreX() + (2 * r2.returnRadioSpaceMargin1()) + r2.returnRadius() && (double)mx >= r2.returnCentreX() + (2 * r2.returnRadioSpaceMargin1()) - r2.returnRadius() && (double)my <= r2.returnCentreY() + r2.returnRadius() && (double)my >= r2.returnCentreY() - r2.returnRadius())
		{
			//DrawCircle(r2.returnCentreX() + (2 * radioSpaceMargin), r2.returnCentreY(), 4, 1);
			r2.SetValue(0);
		}
		if (r2.RadioOutput() == 2)
		{
			Frequency2.SetValue(Frequency2.returnXValue());
		}
		if ((double)mx <= Mass1Check.returnCentreX() + Mass1Check.returnRadius() && (double)mx >= Mass1Check.returnCentreX() - Mass1Check.returnRadius() && (double)my <= Mass1Check.returnCentreY() + Mass1Check.returnRadius() && (double)my >= Mass1Check.returnCentreY() - Mass1Check.returnRadius())
		{
			//DrawCircle(r2.returnCentreX(), r2.returnCentreY(), 4, 1);
			Mass1Check.SetValue(1);
		}

		if ((double)mx <= Mass1Check.returnCentreX() + Mass1Check.returnRadioSpaceMargin2() + Mass1Check.returnRadius() && (double)mx >= Mass1Check.returnCentreX() + Mass1Check.returnRadioSpaceMargin2() - Mass1Check.returnRadius() && (double)my <= Mass1Check.returnCentreY() + Mass1Check.returnRadius() && (double)my >= Mass1Check.returnCentreY() - Mass1Check.returnRadius())
		{
			//DrawCircle(r2.returnCentreX() + radioSpaceMargin, r2.returnCentreY(), 4, 1);
			Mass1Check.SetValue(2);
		}
		
		if (Mass1Check.RadioOutput() != 1)
		{
			mass1.SetValue(mass1.returnXValue());
		}
		if ((double)mx <= Mass2Check.returnCentreX() + Mass2Check.returnRadius() && (double)mx >= Mass2Check.returnCentreX() - Mass2Check.returnRadius() && (double)my <= Mass2Check.returnCentreY() + Mass2Check.returnRadius() && (double)my >= Mass2Check.returnCentreY() - Mass2Check.returnRadius())
		{
			//DrawCircle(r2.returnCentreX(), r2.returnCentreY(), 4, 1);
			Mass2Check.SetValue(1);
		}

		if ((double)mx <= Mass2Check.returnCentreX() + Mass2Check.returnRadioSpaceMargin2() + Mass2Check.returnRadius() && (double)mx >= Mass2Check.returnCentreX() + Mass2Check.returnRadioSpaceMargin2() - Mass2Check.returnRadius() && (double)my <= Mass2Check.returnCentreY() + Mass2Check.returnRadius() && (double)my >= Mass2Check.returnCentreY() - Mass2Check.returnRadius())
		{
			//DrawCircle(r2.returnCentreX() + radioSpaceMargin, r2.returnCentreY(), 4, 1);
			Mass2Check.SetValue(2);
		}

		if (Mass2Check.RadioOutput() != 1)
		{
			mass2.SetValue(mass2.returnXValue());
		}
		if ((double)mx <= Spring1Check.returnCentreX() + Spring1Check.returnRadius() && (double)mx >= Spring1Check.returnCentreX() - Spring1Check.returnRadius() && (double)my <= Spring1Check.returnCentreY() + Spring1Check.returnRadius() && (double)my >= Spring1Check.returnCentreY() - Spring1Check.returnRadius())
		{
			//DrawCircle(r2.returnCentreX(), r2.returnCentreY(), 4, 1);
			Spring1Check.SetValue(1);
		}

		if ((double)mx <= Spring1Check.returnCentreX() + Spring1Check.returnRadioSpaceMargin2() + Spring1Check.returnRadius() && (double)mx >= Spring1Check.returnCentreX() + Spring1Check.returnRadioSpaceMargin2() - Spring1Check.returnRadius() && (double)my <= Spring1Check.returnCentreY() + Spring1Check.returnRadius() && (double)my >= Spring1Check.returnCentreY() - Spring1Check.returnRadius())
		{
			//DrawCircle(r2.returnCentreX() + radioSpaceMargin, r2.returnCentreY(), 4, 1);
			Spring1Check.SetValue(2);
		}

		if (Spring1Check.RadioOutput() != 1)
		{
			Spring1.SetValue(Spring1.returnXValue());
		}
		if ((double)mx <= Spring2Check.returnCentreX() + Spring2Check.returnRadius() && (double)mx >= Spring2Check.returnCentreX() - Spring2Check.returnRadius() && (double)my <= Spring2Check.returnCentreY() + Spring2Check.returnRadius() && (double)my >= Spring2Check.returnCentreY() - Spring2Check.returnRadius())
		{
			//DrawCircle(r2.returnCentreX(), r2.returnCentreY(), 4, 1);
			Spring2Check.SetValue(1);
		}

		if ((double)mx <= Spring2Check.returnCentreX() + Spring2Check.returnRadioSpaceMargin2() + Spring2Check.returnRadius() && (double)mx >= Spring2Check.returnCentreX() + Spring2Check.returnRadioSpaceMargin2() - Spring2Check.returnRadius() && (double)my <= Spring2Check.returnCentreY() + Spring2Check.returnRadius() && (double)my >= Spring2Check.returnCentreY() - Spring2Check.returnRadius())
		{
			//DrawCircle(r2.returnCentreX() + radioSpaceMargin, r2.returnCentreY(), 4, 1);
			Spring2Check.SetValue(2);
		}

		if (Spring2Check.RadioOutput() != 1)
		{
			Spring2.SetValue(Spring2.returnXValue());
		}
		if ((double)mx <= Spring3Check.returnCentreX() + Spring3Check.returnRadius() && (double)mx >= Spring3Check.returnCentreX() - Spring3Check.returnRadius() && (double)my <= Spring3Check.returnCentreY() + Spring3Check.returnRadius() && (double)my >= Spring3Check.returnCentreY() - Spring3Check.returnRadius())
		{
			//DrawCircle(r2.returnCentreX(), r2.returnCentreY(), 4, 1);
			Spring3Check.SetValue(1);
		}

		if ((double)mx <= Spring3Check.returnCentreX() + Spring3Check.returnRadioSpaceMargin2() + Spring3Check.returnRadius() && (double)mx >= Spring3Check.returnCentreX() + Spring3Check.returnRadioSpaceMargin2() - Spring3Check.returnRadius() && (double)my <= Spring3Check.returnCentreY() + Spring3Check.returnRadius() && (double)my >= Spring3Check.returnCentreY() - Spring3Check.returnRadius())
		{
			//DrawCircle(r2.returnCentreX() + radioSpaceMargin, r2.returnCentreY(), 4, 1);
			Spring3Check.SetValue(2);
		}

		if (Spring3Check.RadioOutput() != 1)
		{
			Spring3.SetValue(Spring3.returnXValue());
		}

		if ((double)mx <= Dampener1Check.returnCentreX() + Dampener1Check.returnRadius() && (double)mx >= Dampener1Check.returnCentreX() - Dampener1Check.returnRadius() && (double)my <= Dampener1Check.returnCentreY() + Dampener1Check.returnRadius() && (double)my >= Dampener1Check.returnCentreY() - Dampener1Check.returnRadius())
		{
			//DrawCircle(r2.returnCentreX(), r2.returnCentreY(), 4, 1);
			Dampener1Check.SetValue(1);
		}

		if ((double)mx <= Dampener1Check.returnCentreX() + Dampener1Check.returnRadioSpaceMargin2() + Dampener1Check.returnRadius() && (double)mx >= Dampener1Check.returnCentreX() + Dampener1Check.returnRadioSpaceMargin2() - Dampener1Check.returnRadius() && (double)my <= Dampener1Check.returnCentreY() + Dampener1Check.returnRadius() && (double)my >= Dampener1Check.returnCentreY() - Dampener1Check.returnRadius())
		{
			//DrawCircle(r2.returnCentreX() + radioSpaceMargin, r2.returnCentreY(), 4, 1);
			Dampener1Check.SetValue(2);
		}

		if (Dampener1Check.RadioOutput() != 1)
		{
			Dampener1.SetValue(Dampener1.returnXValue());
		}
		if ((double)mx <= Dampener2Check.returnCentreX() + Dampener2Check.returnRadius() && (double)mx >= Dampener2Check.returnCentreX() - Dampener2Check.returnRadius() && (double)my <= Dampener2Check.returnCentreY() + Dampener2Check.returnRadius() && (double)my >= Dampener2Check.returnCentreY() - Dampener2Check.returnRadius())
		{
			//DrawCircle(r2.returnCentreX(), r2.returnCentreY(), 4, 1);
			Dampener2Check.SetValue(1);
		}

		if ((double)mx <= Dampener2Check.returnCentreX() + Dampener2Check.returnRadioSpaceMargin2() + Dampener2Check.returnRadius() && (double)mx >= Dampener2Check.returnCentreX() + Dampener2Check.returnRadioSpaceMargin2() - Dampener2Check.returnRadius() && (double)my <= Dampener2Check.returnCentreY() + Dampener2Check.returnRadius() && (double)my >= Dampener2Check.returnCentreY() - Dampener2Check.returnRadius())
		{
			//DrawCircle(r2.returnCentreX() + radioSpaceMargin, r2.returnCentreY(), 4, 1);
			Dampener2Check.SetValue(2);
		}

		if (Dampener2Check.RadioOutput() != 1)
		{
			Dampener2.SetValue(Dampener2.returnXValue());
		}
		if ((double)mx <= Dampener3Check.returnCentreX() + Dampener3Check.returnRadius() && (double)mx >= Dampener3Check.returnCentreX() - Dampener3Check.returnRadius() && (double)my <= Dampener3Check.returnCentreY() + Dampener3Check.returnRadius() && (double)my >= Dampener3Check.returnCentreY() - Dampener3Check.returnRadius())
		{
			//DrawCircle(r2.returnCentreX(), r2.returnCentreY(), 4, 1);
			Dampener3Check.SetValue(1);
		}

		if ((double)mx <= Dampener3Check.returnCentreX() + Dampener3Check.returnRadioSpaceMargin2() + Dampener3Check.returnRadius() && (double)mx >= Dampener3Check.returnCentreX() + Dampener3Check.returnRadioSpaceMargin2() - Dampener3Check.returnRadius() && (double)my <= Dampener3Check.returnCentreY() + Dampener3Check.returnRadius() && (double)my >= Dampener3Check.returnCentreY() - Dampener3Check.returnRadius())
		{
			//DrawCircle(r2.returnCentreX() + radioSpaceMargin, r2.returnCentreY(), 4, 1);
			Dampener3Check.SetValue(2);
		}

		if (Dampener3Check.RadioOutput() != 1)
		{
			Dampener3.SetValue(Dampener3.returnXValue());
		}
		if ((double)mx <= returnStartX() + returnStartWidth()/2 && (double)mx >= returnStartX() - returnStartWidth()/2 && (double)my >= returnStartY() && (double)my <= returnStartY() + returnStartHeight())
		{
			//pause
			returnOn(1);

		}
		if ((double)mx >= returnStartX() + returnStartWidth()/2 && (double)mx <= returnStartX() + returnStartWidth()/2 + returnStartWidth() && (double)my >= returnStartY() && (double)my <= returnStartY() + returnStartHeight())
		{
			//stop
			returnOn(0);

		}
		if ((double)mx >= returnStartX() - returnStartWidth() / 2  - returnStartWidth() && (double)mx <= returnStartX() - returnStartWidth() / 2 + returnStartWidth() && (double)my >= returnStartY() && (double)my <= returnStartY() + returnStartHeight())
		{
			//play
			returnOn(2);

		}

		return true;
	}
	else
	{
		return false;
	}
}
const bool UIWindow::checkRunning(void) const
{
	if (On == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

const bool UIWindow::getMass1State(void) const
{
	if (Mass1Check.RadioOutput() == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
const bool UIWindow::getMass2State(void) const
{
	if (Mass2Check.RadioOutput() == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
const bool UIWindow::getSpring1State(void) const
{
	if (Spring1Check.RadioOutput() == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
const bool UIWindow::getSpring2State(void) const
{
	if (Spring2Check.RadioOutput() == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
const bool UIWindow::getSpring3State(void) const
{
	if (Spring3Check.RadioOutput() == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
const bool UIWindow::getDampener1State(void) const
{
	if (Dampener1Check.RadioOutput() == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
const bool UIWindow::getDampener2State(void) const
{
	if (Dampener2Check.RadioOutput() == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
const bool UIWindow::getDampener3State(void) const
{
	if (Dampener3Check.RadioOutput() == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
