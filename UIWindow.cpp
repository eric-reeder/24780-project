#include "UIWindow.h"



#include "GraphicsWindow.h"
#include "Slider.h"
#include "RadioButton.h"
#include "ysglfontdata.h"
#include "fssimplewindow.h"

bool UIWindow::checkRunning(void)
{
	if (On == 1)
	{
		return true;
	}
	if (On == 0)
	{
		return false;
	}
}
bool UIWindow::checkMouse(int mouseLeft, int &mouseX, int &mouseY)
{
	int mb,rb;
	FsGetMouseEvent(mouseLeft,mb,rb,mouseX,mouseY);
	if (1 == mouseLeft)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void UIWindow::returnOn(const int play)
{
	On = play;
}

const double UIWindow::returnStartHeight(void)
{
	return startHeight;
}

const double UIWindow::returnStartWidth(void)
{
	return startWidth;
}
const double UIWindow::returnStartX(void)
{
	return startX;
}
const double UIWindow::returnStartY(void)
{
	return startY;
}




const double UIWindow::getMass1Mass(void)
{
	return mass1.SliderOutput();
}
const double UIWindow::getMass2Mass(void)
{
	return mass2.SliderOutput();
}
const double UIWindow::getSpring1Stiffness(void)
{
	return Spring1.SliderOutput();
}
const double UIWindow::getSpring2Stiffness(void)
{
	return Spring2.SliderOutput();
}
const double UIWindow::getSpring3Stiffness(void)
{
	return Spring3.SliderOutput();
}
const double UIWindow::getDamper1Damping(void)
{
	return Dampener1.SliderOutput();
}
const double UIWindow::getDamper2Damping(void)
{
	return Dampener2.SliderOutput();
}
const double UIWindow::getDamper3Damping(void)
{
	return Dampener3.SliderOutput();
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
	return Amplitude1.SliderOutput();
}
const double UIWindow::getForce1Value2(void)
{
	return Frequency1.SliderOutput();
}
const double UIWindow::getForce2Value1(void)
{
	return Amplitude2.SliderOutput();
}
const double UIWindow::getForce2Value2(void)
{
	return Frequency2.SliderOutput();
}

void UIWindow::DrawStart(double sliderYCoord) 
{
	startX = width / 2;
	startY = sliderYCoord;
	startWidth = 50;
	startHeight = 50;
	double playHeight = 25;
	double playWidth = 25;


	glBegin(GL_QUADS);
	
		
	glColor3ub(255, 0, 0);
	glVertex2d(startX, startY);
	glVertex2d(startX + startWidth, startY);
	glVertex2d(startX + startWidth, startY + startHeight);
	glVertex2d(startX, startY + startHeight);
	
	glColor3ub(0, 255, 0);
	glVertex2d(startX, startY);
	glVertex2d(startX - startWidth, startY);
	glVertex2d(startX - startWidth, startY + startHeight);
	glVertex2d(startX, startY + startHeight);

	glColor3ub(0, 0, 0);
	glVertex2d(startX + startWidth / 2 - playWidth / 2, startY + startHeight / 2 - playHeight / 2);
	glVertex2d(startX + startWidth / 2 - playWidth / 2, startY + startHeight / 2 + playHeight / 2);
	glVertex2d(startX + startWidth / 2 + playWidth / 2, startY + startHeight / 2 + playHeight / 2);
	glVertex2d(startX + startWidth / 2 + playWidth / 2, startY + startHeight / 2 - playHeight / 2);


	
	glEnd();
	glColor3ub(0, 0, 0);

	glBegin(GL_TRIANGLES);
	glVertex2d(startX - startWidth / 2 - playWidth / 2, startY + startHeight / 2 + playHeight / 2);
	glVertex2d(startX - startWidth / 2 - playWidth / 2, startY + startHeight / 2 - playHeight / 2);
	glVertex2d(startX - startWidth / 2 + playWidth / 2, startY + startHeight / 2);
	glEnd();


}

void UIWindow::DrawUIWindow(void)
{
	const double leftMargin = width / 20;
	const int fontHeight = 12;
	const int fontWidth = 8;
	const double margin = 12;
	const double lineSpacing = (6.5 * height) / 150;
	double sliderYCoord = yPosition + ((4 * height / 150)) + leftMargin;
	const double startPosition = xPosition + leftMargin;
	const double radioLabelMargin = 15;
	const double radioSpaceMargin = (fontWidth * 14);
	
	mass1.Initialize(width, height, sliderYCoord);
	sliderYCoord += lineSpacing;

	mass2.Initialize(width, height, sliderYCoord);
	sliderYCoord += lineSpacing;

	Spring1.Initialize(width, height, sliderYCoord);
	sliderYCoord += lineSpacing;

	Spring2.Initialize(width, height, sliderYCoord);
	sliderYCoord += lineSpacing;

	Spring3.Initialize(width, height, sliderYCoord);
	sliderYCoord += lineSpacing;

	Dampener1.Initialize(width, height, sliderYCoord);
	sliderYCoord += lineSpacing;

	Dampener2.Initialize(width, height, sliderYCoord);
	sliderYCoord += lineSpacing;

	Dampener3.Initialize(width, height, sliderYCoord);
	sliderYCoord += lineSpacing;
	sliderYCoord += 2*lineSpacing;
	r1.Initialize(width, sliderYCoord);
	sliderYCoord += lineSpacing;

	Amplitude1.Initialize(width, height, sliderYCoord);
	sliderYCoord += lineSpacing;
	Frequency1.Initialize(width, height, sliderYCoord);

	sliderYCoord += 3 * lineSpacing;

	r2.Initialize(width, sliderYCoord);

	sliderYCoord += lineSpacing;

	Amplitude2.Initialize(width, height, sliderYCoord);
	sliderYCoord += lineSpacing;
	Frequency2.Initialize(width, height, sliderYCoord);

	

	//printf("%lf\n", sliderYCoord);
	auto terminate = 0;

	while (terminate != 1)
	{
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

		FsPollDevice();
		auto key = FsInkey();
		if (key == FSKEY_ESC)
		{
			terminate = 1;
		}

		mass1.DrawSlider();

		glRasterPos2d(mass1.returnXValue() - margin, mass1.returnYValue() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("0");
		glRasterPos2d(mass1.returnXValue() + mass1.returnWidthValue() + margin, mass1.returnYValue() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("100");
		glRasterPos2d(startPosition, mass1.returnYValue() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("Mass 1:");



		mass2.DrawSlider();

		glRasterPos2d(mass2.returnXValue() - margin, mass2.returnYValue() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("0");
		glRasterPos2d(mass2.returnXValue() + mass2.returnWidthValue() + margin, mass2.returnYValue() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("100");
		glRasterPos2d(startPosition, mass2.returnYValue() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("Mass 2:");

		Spring1.DrawSlider();

		glRasterPos2d(Spring1.returnXValue() - margin, Spring1.returnYValue() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("0");
		glRasterPos2d(Spring1.returnXValue() + Spring1.returnWidthValue() + margin, Spring1.returnYValue() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("100");
		glRasterPos2d(startPosition, Spring1.returnYValue() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("Spring1:");

		Spring2.DrawSlider();

		glRasterPos2d(Spring2.returnXValue() - margin, Spring2.returnYValue() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("0");
		glRasterPos2d(Spring2.returnXValue() + Spring2.returnWidthValue() + margin, Spring2.returnYValue() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("100");
		glRasterPos2d(startPosition, Spring2.returnYValue() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("Spring2:");

		Spring3.DrawSlider();

		glRasterPos2d(Spring3.returnXValue() - margin, Spring3.returnYValue() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("0");
		glRasterPos2d(Spring3.returnXValue() + Spring3.returnWidthValue() + margin, Spring3.returnYValue() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("100");
		glRasterPos2d(startPosition, Spring3.returnYValue() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("Spring1:");

		Dampener1.DrawSlider();

		glRasterPos2d(Dampener1.returnXValue() - margin, Dampener1.returnYValue() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("0");
		glRasterPos2d(Dampener1.returnXValue() + Dampener1.returnWidthValue() + margin, Dampener1.returnYValue() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("100");
		glRasterPos2d(startPosition, Dampener1.returnYValue() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("Dampener1:");

		Dampener2.DrawSlider();

		glRasterPos2d(Dampener2.returnXValue() - margin, Dampener2.returnYValue() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("0");
		glRasterPos2d(Dampener2.returnXValue() + Dampener2.returnWidthValue() + margin, Dampener2.returnYValue() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("100");
		glRasterPos2d(startPosition, Dampener2.returnYValue() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("Dampener2:");

		Dampener3.DrawSlider();

		glRasterPos2d(Dampener3.returnXValue() - margin, Dampener3.returnYValue() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("0");
		glRasterPos2d(Dampener3.returnXValue() + Dampener3.returnWidthValue() + margin, Dampener3.returnYValue() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("100");
		glRasterPos2d(startPosition, Dampener3.returnYValue() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("Dampener3:");




		glRasterPos2d(startPosition, r1.returnCentreY() - lineSpacing);
		YsGlDrawFontBitmap8x12("Force 1:");
		r1.DrawRadio();
		glRasterPos2d(startPosition + radioLabelMargin, r1.returnCentreY() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("Constant");
		glRasterPos2d(startPosition + radioLabelMargin + radioSpaceMargin, r1.returnCentreY() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("Exponential");
		glRasterPos2d(startPosition + radioLabelMargin + (2 * radioSpaceMargin), r1.returnCentreY() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("Sinosoidal");
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

		glRasterPos2d(startPosition, r2.returnCentreY() - lineSpacing);
		YsGlDrawFontBitmap8x12("Force 2:");

		r2.DrawRadio();
		glRasterPos2d(startPosition + radioLabelMargin, r2.returnCentreY() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("Constant");
		glRasterPos2d(startPosition + radioLabelMargin + radioSpaceMargin, r2.returnCentreY() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("Exponential");
		glRasterPos2d(startPosition + radioLabelMargin + (2 * radioSpaceMargin), r2.returnCentreY() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("Sinosoidal");

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

		

		DrawStart(Frequency2.returnYValue() + lineSpacing);

		int mx, my, lb;
		
		bool check;
		check = checkMouse(lb, mx, my);

		if (check == true)
		{
			
			if ((double)mx >= mass1.returnXValue() && (double)mx <= mass1.returnXValue() + mass1.returnWidthValue() && (double)my <= mass1.returnYValue() + mass1.returnHeightValue() && (double)my >= mass1.returnYValue() - mass1.returnHeightValue())
			{
				mass1.SetValue(mx);
			}
			if (mx >= mass2.returnXValue() && mx <= mass2.returnXValue() + mass2.returnWidthValue() && my <= mass2.returnYValue() + mass2.returnHeightValue() && my >= mass2.returnYValue() - mass2.returnHeightValue())
			{
				mass2.SetValue(mx);
			}
			if (mx >= Spring1.returnXValue() && mx <= Spring1.returnXValue() + Spring1.returnWidthValue() && my <= Spring1.returnYValue() + Spring1.returnHeightValue() && my >= Spring1.returnYValue() - Spring1.returnHeightValue())
			{
				Spring1.SetValue(mx);
			}
			if (mx >= Spring2.returnXValue() && mx <= Spring2.returnXValue() + Spring2.returnWidthValue() && my <= Spring2.returnYValue() + Spring2.returnHeightValue() && my >= Spring2.returnYValue() - Spring2.returnHeightValue())
			{
				Spring2.SetValue(mx);
			}

			if (mx >= Spring3.returnXValue() && mx <= Spring3.returnXValue() + Spring3.returnWidthValue() && my <= Spring3.returnYValue() + Spring3.returnHeightValue() && my >= Spring3.returnYValue() - Spring3.returnHeightValue())
			{
				Spring3.SetValue(mx);
			}

			if (mx >= Dampener1.returnXValue() && mx <= Dampener1.returnXValue() + Dampener1.returnWidthValue() && my <= Dampener1.returnYValue() + Dampener1.returnHeightValue() && my >= Dampener1.returnYValue() - Dampener1.returnHeightValue())
			{
				Dampener1.SetValue(mx);
			}

			if (mx >= Dampener2.returnXValue() && mx <= Dampener2.returnXValue() + Dampener2.returnWidthValue() && my <= Dampener2.returnYValue() + Dampener2.returnHeightValue() && my >= Dampener2.returnYValue() - Dampener2.returnHeightValue())
			{
				Dampener2.SetValue(mx);
			}
			if (mx >= Dampener3.returnXValue() && mx <= Dampener3.returnXValue() + Dampener3.returnWidthValue() && my <= Dampener3.returnYValue() + Dampener3.returnHeightValue() && my >= Dampener3.returnYValue() - Dampener3.returnHeightValue())
			{
				Dampener3.SetValue(mx);
			}

			if (mx >= Amplitude1.returnXValue() && mx <= Amplitude1.returnXValue() + Amplitude1.returnWidthValue() && my <= Amplitude1.returnYValue() + Amplitude1.returnHeightValue() && my >= Amplitude1.returnYValue() - Amplitude1.returnHeightValue())
			{
				Amplitude1.SetValue(mx);
			}
			if (mx >= Amplitude2.returnXValue() && mx <= Amplitude2.returnXValue() + Amplitude2.returnWidthValue() && my <= Amplitude2.returnYValue() + Amplitude2.returnHeightValue() && my >= Amplitude2.returnYValue() - Amplitude2.returnHeightValue())
			{
				Amplitude2.SetValue(mx);
			}
			if (mx >= Frequency1.returnXValue() && mx <= Frequency1.returnXValue() + Frequency1.returnWidthValue() && my <= Frequency1.returnYValue() + Frequency1.returnHeightValue() && my >= Frequency1.returnYValue() - Frequency1.returnHeightValue())
			{
				Frequency1.SetValue(mx);
			}

			if (mx >= Frequency2.returnXValue() && mx <= Frequency2.returnXValue() + Frequency2.returnWidthValue() && my <= Frequency2.returnYValue() + Frequency2.returnHeightValue() && my >= Frequency2.returnYValue() - Frequency2.returnHeightValue())
			{
				Frequency2.SetValue(mx);
			}
			if (mx <= r1.returnCentreX() + r1.returnRadius() && mx >= r1.returnCentreX() - r1.returnRadius() && my <= r1.returnCentreY() + r1.returnRadius() && my >= r1.returnCentreY() - r1.returnRadius())
			{
				DrawCircle(r1.returnCentreX(), r1.returnCentreY(), 4, 1);
				r1.SetValue(1);
			}

			if (mx <= r1.returnCentreX() + radioSpaceMargin + r1.returnRadius() && mx >= r1.returnCentreX() + radioSpaceMargin - r1.returnRadius() && my <= r1.returnCentreY() + r1.returnRadius() && my >= r1.returnCentreY() - r1.returnRadius())
			{
				DrawCircle(r1.returnCentreX() + radioSpaceMargin, r1.returnCentreY(), 4, 1);
				r1.SetValue(2);
			}
			if (mx <= r1.returnCentreX() + (2 * radioSpaceMargin) + r1.returnRadius() && mx >= r1.returnCentreX() + (2 * radioSpaceMargin) - r1.returnRadius() && my <= r1.returnCentreY() + r1.returnRadius() && my >= r1.returnCentreY() - r1.returnRadius())
			{
				DrawCircle(r1.returnCentreX() + (2 * radioSpaceMargin), r1.returnCentreY(), 4, 1);
				r1.SetValue(3);
			}
			if (r1.RadioOutput() != 3)
			{
				Frequency1.SetValue(Frequency1.returnXValue());
			}
			if (mx <= r2.returnCentreX() + r2.returnRadius() && mx >= r2.returnCentreX() - r2.returnRadius() && my <= r2.returnCentreY() + r2.returnRadius() && my >= r2.returnCentreY() - r2.returnRadius())
			{
				//DrawCircle(r2.returnCentreX(), r2.returnCentreY(), 4, 1);
				r2.SetValue(1);
			}

			if (mx <= r2.returnCentreX() + radioSpaceMargin + r2.returnRadius() && mx >= r2.returnCentreX() + radioSpaceMargin - r2.returnRadius() && my <= r2.returnCentreY() + r2.returnRadius() && my >= r2.returnCentreY() - r2.returnRadius())
			{
				//DrawCircle(r2.returnCentreX() + radioSpaceMargin, r2.returnCentreY(), 4, 1);
				r2.SetValue(2);
			}
			if (mx <= r2.returnCentreX() + (2 * radioSpaceMargin) + r2.returnRadius() && mx >= r2.returnCentreX() + (2 * radioSpaceMargin) - r2.returnRadius() && my <= r2.returnCentreY() + r2.returnRadius() && my >= r2.returnCentreY() - r2.returnRadius())
			{
				//DrawCircle(r2.returnCentreX() + (2 * radioSpaceMargin), r2.returnCentreY(), 4, 1);
				r2.SetValue(3);
			}
			if (r2.RadioOutput() != 3)
			{
				Frequency2.SetValue(Frequency2.returnXValue());
			}
			if (mx <= returnStartX() && mx >= returnStartX() - returnStartWidth() && my >= returnStartY() && my <= returnStartY() + returnStartHeight())
			{
				returnOn(1);
			}
			if (mx >= returnStartX() && mx <= returnStartX() + returnStartWidth() && my >= returnStartY() && my <= returnStartY() + returnStartHeight())
			{
				returnOn(0);
			}

			
		}
		FsSwapBuffers();
		FsSleep(50);
	}

}
