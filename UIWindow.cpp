#include "UIWindow.h"

const double UIWindow::getMass1Mass(void)
{
	return mslider[0].SliderOutput();
}
const double UIWindow::getMass2Mass(void)
{
	return mslider[1].SliderOutput();
}
const double UIWindow::getSpring1Stiffness(void)
{
	return k[0].SliderOutput();
}
const double UIWindow::getSpring2Stiffness(void)
{
	return k[1].SliderOutput();
}
const double UIWindow::getSpring3Stiffness(void)
{
	return k[2].SliderOutput();
}
const double UIWindow::getDamper1Damping(void)
{
	return c[0].SliderOutput();
}
const double UIWindow::getDamper2Damping(void)
{
	return c[1].SliderOutput();
}
const double UIWindow::getDamper3Damping(void)
{
	return c[2].SliderOutput();
}
const int UIWindow::getForce1Type(void) 
{
	return r[0].RadioOutput();
}
const int UIWindow::getForce2Type(void)
{
	return r[1].RadioOutput();
}
const double UIWindow::getForce1Value1(void)
{
	return A[0].SliderOutput();
}
const double UIWindow::getForce1Value2(void)
{
	return f[0].SliderOutput();
}
const double UIWindow::getForce2Value1(void)
{
	return A[1].SliderOutput();
}
const double UIWindow::getForce2Value2(void)
{
	return f[1].SliderOutput();
}

void UIWindow::DrawUIWindow(void)
{
	const double leftMargin = width / 20;
	const int fontHeight = 12;
	const int fontWidth = 8;
	const double margin = 12;
	const double lineSpacing = (9 * height) / 150;
	double sliderYCoord = yPosition + ((4 * height / 150)) + leftMargin;
	const double startPosition = xPosition + leftMargin;
	const double radioLabelMargin = 15;
	const double radioSpaceMargin = (fontWidth * 14);
	for (int i = 0; i<N_MASSES; ++i)
	{
		mslider[i].Initialize(width, height, sliderYCoord);
		//printf("%lf\n", mslider[i].returnHeightValue());
		sliderYCoord += lineSpacing;
	}
	for (int i = 0; i<N_SPRINGS; ++i)
	{
		k[i].Initialize(width, height, sliderYCoord);
		printf("%lf %lf %lf %lf \n", k[i].returnHeightValue(), k[i].returnWidthValue(), k[i].returnXValue(), k[i].returnYValue());
		sliderYCoord += lineSpacing;
	}
	for (int i = 0; i<N_SPRINGS; ++i)
	{
		c[i].Initialize(width, height, sliderYCoord);
		sliderYCoord += lineSpacing;
	}
	printf("%lf\n", sliderYCoord);
	auto terminate = 0;
	
	while (terminate!=1)
	{

		
		FsPollDevice();
		auto key = FsInkey();
		if (key == FSKEY_ESC)
		{
			terminate = 1;
		}

		for (int i = 0; i<N_MASSES; ++i)
		{
			mslider[i].DrawSlider();
			
			double x = mslider[i].returnXValue();
			double y = mslider[i].returnYValue();
			double setWidth = mslider[i].returnWidthValue();
			double setHeight = mslider[i].returnHeightValue();



			glRasterPos2d(x - margin, y + (double)fontHeight / 2);
			YsGlDrawFontBitmap8x12("0");
			glRasterPos2d(x + setWidth + margin, y + (double)fontHeight / 2);
			YsGlDrawFontBitmap8x12("100");
		}
		for (int i = 0; i<N_SPRINGS; ++i)
		{
			k[i].DrawSlider();
			double x = k[i].returnXValue();
			double y = k[i].returnYValue();
			double setWidth = k[i].returnWidthValue();
			double setHeight = k[i].returnHeightValue();

			glRasterPos2d(x - margin, y + (double)fontHeight / 2);
			YsGlDrawFontBitmap8x12("0");
			glRasterPos2d(x + setWidth + margin, y + (double)fontHeight / 2);
			YsGlDrawFontBitmap8x12("100");
		}
		for (int i = 0; i<N_SPRINGS; ++i)
		{
			c[i].DrawSlider();
			double x = c[i].returnXValue();
			double y = c[i].returnYValue();
			double setWidth = c[i].returnWidthValue();
			double setHeight = c[i].returnHeightValue();

			glRasterPos2d(x - margin, y + (double)fontHeight / 2);
			YsGlDrawFontBitmap8x12("0");
			glRasterPos2d(x + setWidth + margin, y + (double)fontHeight / 2);
			YsGlDrawFontBitmap8x12("100");
		}
		glRasterPos2d(startPosition, mslider[0].returnYValue() + (double)fontHeight/2);
		YsGlDrawFontBitmap8x12("Mass 1:");

		glRasterPos2d(startPosition, mslider[1].returnYValue() + (double)fontHeight/2);
		YsGlDrawFontBitmap8x12("Mass 2:");

		glRasterPos2d(startPosition, k[0].returnYValue() + (double)fontHeight/2);
		YsGlDrawFontBitmap8x12("k1:");

		glRasterPos2d(startPosition, k[1].returnYValue() + (double)fontHeight/2);
		YsGlDrawFontBitmap8x12("k2:");

		glRasterPos2d(startPosition, k[2].returnYValue() + (double)fontHeight/2);
		YsGlDrawFontBitmap8x12("k3:");

		glRasterPos2d(startPosition, c[0].returnYValue() + (double)fontHeight/2);
		YsGlDrawFontBitmap8x12("c1:");

		glRasterPos2d(startPosition, c[1].returnYValue() + (double)fontHeight/2);
		YsGlDrawFontBitmap8x12("c2:");

		glRasterPos2d(startPosition, c[2].returnYValue() + (double)fontHeight/2);
		YsGlDrawFontBitmap8x12("c3:");

		glRasterPos2d(startPosition, sliderYCoord);
		YsGlDrawFontBitmap8x12("Force 1:");
		sliderYCoord += lineSpacing;
		r[0].Initialize(width, sliderYCoord);
		r[0].DrawRadio();
		glRasterPos2d(startPosition + radioLabelMargin, sliderYCoord);
		YsGlDrawFontBitmap8x12("Constant");
		glRasterPos2d(startPosition + radioLabelMargin + radioSpaceMargin, sliderYCoord);
		YsGlDrawFontBitmap8x12("Exponential");
		glRasterPos2d(startPosition + radioLabelMargin + (2 * radioSpaceMargin), sliderYCoord);
		YsGlDrawFontBitmap8x12("Sinosoidal");
		sliderYCoord += lineSpacing;

		A[0].Initialize(width, height, sliderYCoord);
		A[0].DrawSlider();
		glRasterPos2d(A[0].returnXValue() - margin, A[0].returnYValue() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("0");
		glRasterPos2d(A[0].returnXValue() + A[0].returnWidthValue() + margin, A[0].returnYValue() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("100");


		sliderYCoord += lineSpacing;

		f[0].Initialize(width, height, sliderYCoord);
		f[0].DrawSlider();
		glRasterPos2d(f[0].returnXValue() - margin, f[0].returnYValue() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("0");
		glRasterPos2d(f[0].returnXValue() + f[0].returnWidthValue() + margin, f[0].returnYValue() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("100");

		sliderYCoord += lineSpacing;

		glRasterPos2d(startPosition, sliderYCoord);
		YsGlDrawFontBitmap8x12("Force 2:");
		sliderYCoord += lineSpacing;
		r[1].Initialize(width, sliderYCoord);
		r[1].DrawRadio();
		glRasterPos2d(startPosition + radioLabelMargin, sliderYCoord);
		YsGlDrawFontBitmap8x12("Constant");
		glRasterPos2d(startPosition + radioLabelMargin + radioSpaceMargin, sliderYCoord);
		YsGlDrawFontBitmap8x12("Exponential");
		glRasterPos2d(startPosition + radioLabelMargin + (2 * radioSpaceMargin), sliderYCoord);
		YsGlDrawFontBitmap8x12("Sinosoidal");

		sliderYCoord += lineSpacing;

		A[1].Initialize(width, height, sliderYCoord);
		A[1].DrawSlider();
		glRasterPos2d(A[1].returnXValue() - margin, A[1].returnYValue() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("0");
		glRasterPos2d(A[1].returnXValue() + A[1].returnWidthValue() + margin, A[1].returnYValue() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("100");


		sliderYCoord += lineSpacing;

		f[1].Initialize(width, height, sliderYCoord);
		f[1].DrawSlider();
		glRasterPos2d(f[1].returnXValue() - margin, f[1].returnYValue() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("0");
		glRasterPos2d(f[1].returnXValue() + f[1].returnWidthValue() + margin, f[1].returnYValue() + (double)fontHeight / 2);
		YsGlDrawFontBitmap8x12("100");

		int mx, my, lb, rb, mb;

	

		FsGetMouseState(lb, mb, rb, mx, my);
		if (0 != lb)
		{
			for (int i = 0; i<N_MASSES; ++i)
			{
				if (mx >= mslider[i].returnXValue() && mx <= mslider[i].returnXValue() + mslider[i].returnWidthValue() && my <= mslider[i].returnYValue() + mslider[i].returnHeightValue() && my >= mslider[i].returnYValue() - mslider[i].returnHeightValue())
				{
					mslider[i].SetValue(mx);
				}
			}
			for (int i = 0; i<N_SPRINGS; ++i)
			{
				if (mx >= k[i].returnXValue() && mx <= k[i].returnXValue() + k[i].returnWidthValue() && my <= k[i].returnYValue() + k[i].returnHeightValue() && my >= k[i].returnYValue() - k[i].returnHeightValue())
				{
					k[i].SetValue(mx);
				}
			}
			for (int i = 0; i<N_SPRINGS; ++i)
			{
				if (mx >= c[i].returnXValue() && mx <= c[i].returnXValue() + c[i].returnWidthValue() && my <= c[i].returnYValue() + c[i].returnHeightValue() && my >= c[i].returnYValue() - c[i].returnHeightValue())
				{
					c[i].SetValue(mx);
				}
			}
			for (int i = 0; i<N_FORCES; ++i)
			{
				if (mx >= A[i].returnXValue() && mx <= A[i].returnXValue() + A[i].returnWidthValue() && my <= A[i].returnYValue() + A[i].returnHeightValue() && my >= A[i].returnYValue() - A[i].returnHeightValue())
				{
					A[i].SetValue(mx);
				}
			}
			for (int i = 0; i<N_FORCES; ++i)
			{
				if (mx >= f[i].returnXValue() && mx <= f[i].returnXValue() + f[i].returnWidthValue() && my <= f[i].returnYValue() + f[i].returnHeightValue() && my >= f[i].returnYValue() - f[i].returnHeightValue())
				{
					f[i].SetValue(mx);
				}
			}

			for (int i = 0; i<N_FORCES; ++i)
			{
				if (mx <= r[i].returnCentreX() + r[i].returnRadius() && mx >= r[i].returnCentreX() - r[i].returnRadius() && my <= r[i].returnCentreY() + r[i].returnRadius() && my >= r[i].returnCentreY() - r[i].returnRadius())
				{
					DrawCircle(r[i].returnCentreX(), r[i].returnCentreY(), 4, 1);
					r[i].SetValue(1);
				}
				if (mx <= r[i].returnCentreX() + radioSpaceMargin + r[i].returnRadius() && mx >= r[i].returnCentreX() + radioSpaceMargin - r[i].returnRadius() && my <= r[i].returnCentreY() + r[i].returnRadius() && my >= r[i].returnCentreY() - r[i].returnRadius())
				{
					DrawCircle(r[i].returnCentreX() + radioSpaceMargin, r[i].returnCentreY(), 4, 1);
					r[i].SetValue(2);
				}
				if (mx <= r[i].returnCentreX() + (2 * radioSpaceMargin) + r[i].returnRadius() && mx >= r[i].returnCentreX() + (2 * radioSpaceMargin) - r[i].returnRadius() && my <= r[i].returnCentreY() + r[i].returnRadius() && my >= r[i].returnCentreY() - r[i].returnRadius())
				{
					DrawCircle(r[i].returnCentreX() + (2 * radioSpaceMargin), r[i].returnCentreY(), 4, 1);
					r[i].SetValue(3);
				}
				if (r[i].RadioOutput() != 3)
				{
					f[i].SetValue(f[i].returnXValue());

				}
			}




		}
		
	}

}
