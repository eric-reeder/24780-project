#include "UIWindow.h"
#include "fssimplewindow.h"
#include <math.h>


void DrawCircle(double cx, double cy, double radius, int fill)
{
	double x,y,angle;
	if(fill!=0)
	{
		glBegin(GL_TRIANGLE_FAN);
	}
	else
	{
		glBegin(GL_LINE_LOOP);
	}
	for(int i=0;i<64;++i)
	{
		angle = ((double)i*YS_PI)/32.0;	
		x = cx + (radius*cos(angle));
		y = cy + (radius*sin(angle));
		glVertex2d(x,y);

	}
	glEnd();
}

void DrawLine(double x0, double y0, double width)
{
	glBegin(GL_LINES);
	glVertex2d(x0, y0);
	glVertex2d(x0 + width, y0);
	glEnd();	

} 

void DrawRect(double x, double y, double height, double width)
{
	glBegin(GL_QUADS);
	glVertex2d(x0, y0 - height);
	glVertex2d(x0 + width, y0 - height);
	glVertex2d(x0 + width, y0 + height);
	glVertex2d(x0, y0 + height);
	glEnd();
}

void Slider::Initialize(double winWidth, double winHeight, double sliderCoordY)
{
	dialStartX = winWidth/20 + (8*14);
	dialStartY = sliderCoordY;
	
	sliderX = dialStartX;
	width = (2*winWidth)/3;
	height = (2*winHeight)/70;
	output = 0;
}
void Slider::DrawSlider(double sliderYCoord)
{
	DrawLine(dialStartX,sliderYCoord,width);
	DrawRect(sliderX,sliderYCoord,height,width);
	//code for glRasterPos and font
}
void Slider::SliderOutput(void)
{
	
	
	output = (SliderX - dialStartX)/100;		
	
}

void RadioButton::Initialize(double winWidth, double startY)
{
	radius = 6;
	centreX = winWidth/20;
	centreY = startY;
	state = 0;

}

void RadioButton::DrawRadio(void)
{
	int fill = 0;
	DrawCircle(centreX,centreY,radius,fill);
	DrawCircle(centreX + (8*14), centreY, radius, fill);
	DrawCircle(centreX + (2*8*14), centreY, radius, fill);
		

}


void UIWindow::DrawUIWindow(double winWidth, double winHeight)
{
	double startPos = (winWidth/20);
	double margin = 12;
	double sliderYCoord = ((4*winHeight)/150) + 6 + (winHeight/20);

	auto key = FSKEY_NULL;
	while(FSKEY_NULL == key)
	{
		FsPollDevice();
		for(int i=0;i<N_MASSES;++i)
		{
			mslider[i].Initialize(winWidth, winHeight, sliderCoordY);
			mslider[i].DrawSlider(sliderYCoord);
			glRasterPos2d(mslider[i].dialStartX - margin,sliderYCoord);
			YsGlDrawFontBitmap8x12("0");
			glRasterPos2d(mslider[i].dialStartX + mslider[i].width + margin,sliderYCoord);
			YsGlDrawFontBitmap8x12("100");
			sliderYCoord+= (9*winHeight)/150;
		}
		for(int i=0;i<N_SPRINGS;++i)
		{
			k[i].Initialize(winWidth, winHeight, sliderCoordY);
			k[i].DrawSlider(sliderYCoord);
			glRasterPos2d(k[i].dialStartX - margin,sliderYCoord);
			YsGlDrawFontBitmap8x12("0");
			glRasterPos2d(k[i].dialStartX + k[i].width + margin,sliderYCoord);
			YsGlDrawFontBitmap8x12("100");
			sliderYCoord+= (9*winHeight)/150;
		}
		for(int i=0;i<N_DAMPENERS;++i)
		{
			c[i].Initialize(winWidth, winHeight, sliderCoordY);
			c[i].DrawSlider(sliderYCoord);
			glRasterPos2d(c[i].dialStartX - margin,sliderYCoord);
			YsGlDrawFontBitmap8x12("0");
			glRasterPos2d(c[i].dialStartX + c[i].width + margin,sliderYCoord);
			YsGlDrawFontBitmap8x12("100");
			sliderYCoord+= (9*winHeight)/150;	
	
		}
	
	
		glRasterPos2d(startPos,mslider[0].dialStartY);
		YsGlDrawFontBitmap8x12("Mass 1:");

		glRasterPos2d(startPos,mslider[1].dialStartY);
		YsGlDrawFontBitmap8x12("Mass 2:");

		glRasterPos2d(startPos,k[0].dialStartY);
		YsGlDrawFontBitmap8x12("k1:");
	
		glRasterPos2d(startPos,k[1].dialStartY);
		YsGlDrawFontBitmap8x12("k2:");
	
		glRasterPos2d(startPos,mslider[2].dialStartY);
		YsGlDrawFontBitmap8x12("k3:");

		glRasterPos2d(startPos,c[0].dialStartY);
		YsGlDrawFontBitmap8x12("c1:");

		glRasterPos2d(startPos,c[1].dialStartY);
		YsGlDrawFontBitmap8x12("c2:");

		glRasterPos2d(startPos,c[2].dialStartY);
		YsGlDrawFontBitmap8x12("c3:");

	
		glRasterPos2d(startPos,sliderYCoord);
		YsGlDrawFontBitmap8x12("Force 1:");
		sliderYCoord+= (9*winHeight)/150;
		r[0].Initialize(winWidth,sliderYCoord);
		r[0].DrawRadio();
		glRasterPos2d(startPos + 15,sliderYCoord);
		YsGlDrawFontBitmap8x12("Constant");
		glRasterPos2d(startPos + 15 + (8*14),sliderYCoord);
		YsGlDrawFontBitmap8x12("Exponential");
		glRasterPos2d(startPos + 15 + (2*8*14),sliderYCoord);
		YsGlDrawFontBitmap8x12("Sinosoidal");
		sliderYCoord+= (9*winHeight)/150;
	
		A[0].Initialize(winWidth, winHeight, sliderYCoord);
		glRasterPos2d(startPos, sliderYCoord);
		YsGlDrawFontBitmap8x12("Amplitude:");
		A[0].DrawSlider(sliderYCoord);
		glRasterPos2d(A[0].dialStartX - margin,sliderYCoord);
		YsGlDrawFontBitmap8x12("0");
		glRasterPos2d(A[0].dialStartX + A[0].width + margin, sliderYCoord);
		YsGlDrawFontBitmap8x12("100");
	
		sliderYCoord+= (9*winHeight)/150;
	
		f[0].Initialize(winWidth, win Height, sliderYCoord);
		glRasterPos2d(startPos, sliderYCoord);
		YsGlDrawFontBitmap8x12("Frequency:");
		f[0].DrawSlider(sliderYCoord);
		glRasterPos2d(f[0].dialStartX - margin,sliderYCoord);
		YsGlDrawFontBitmap8x12("0");
		glRasterPos2d(f[0].dialStartX + f[0].width + margin,sliderYCoord);
		YsGlDrawFont Bitmap("100");

		sliderYCoord+=(9*winHeight)/150;

		glRasterPos2d(startPos,sliderYCoord);
		YsGlDrawFontBitmap8x12("Force 2:");
		sliderYCoord+= (9*winHeight)/150;
		r[1].Initialize(winWidth,sliderYCoord);
		r[1].DrawRadio();
		glRasterPos2d(startPos + 15,sliderYCoord);
		YsGlDrawFontBitmap8x12("Constant");
		glRasterPos2d(startPos + 15 + (8*14),sliderYCoord);
		YsGlDrawFontBitmap8x12("Exponential");
		glRasterPos2d(startPos + 15 + (2*8*14),sliderYCoord);
		YsGlDrawFontBitmap8x12("Sinosoidal");
		sliderYCoord+= (9*winHeight)/150;

		A[1].Initialize(winWidth, winHeight, sliderYCoord);	
		glRasterPos2d(startPos, sliderYCoord);
		YsGlDrawFontBitmap8x12("Amplitude:");
		A[1].DrawSlider(sliderYCoord);
		glRasterPos2d(A[1].dialStartX - margin,sliderYCoord);
		YsGlDrawFontBitmap8x12("0");
		glRasterPos2d(A[1].dialStartX + A[1].width + margin, sliderYCoord);
		YsGlDrawFontBitmap8x12("100");
	
		sliderYCoord+= (9*winHeight)/150;
	
		f[1].Initialize(winWidth,winHeight,sliderYCoord);
		glRasterPos2d(startPos, sliderYCoord);
		YsGlDrawFontBitmap8x12("Frequency:");
		f[1].DrawSlider(sliderYCoord);
		glRasterPos2d(f[1].dialStartX - margin,sliderYCoord);
		YsGlDrawFontBitmap8x12("0");
		glRasterPos2d(f[1].dialStartX + f[1].width + margin,sliderYCoord);
		YsGlDrawFont Bitmap("100");

		double mx, my,lb,rb,mb;

		FsGetMouseState(lb,mb,rb,mx,my);
		if(0!=lb)
		{
			for(int i=0;i<N_MASSES;++i)
			{
				if(mx>=mslider[i].dialStartX && mx<=mslider[i].dialStartX + mslider[i].width && my<= mslider[i].dialStartY + mslider[i].height && my>= mslider[i].dialStartY - mslider[i].height)
				{
					mslider[i].sliderX = mx;
					mslider[i].SliderOutput();
				}		
		
			}

			for(int i=0;i<N_SPRINGS;++i)
			{
				if(mx>=k[i].dialStartX && mx<=k[i].dialStartX + k[i].width && my<= k[i].dialStartY + k[i].height && my>= k[i].dialStartY - k[i].height)
				{
					k[i].sliderX = mx;
					k[i].SliderOutput();
				}		
		
			}

			for(int i=0;i<N_DAMPENERS;++i)
			{
				if(mx>=c[i].dialStartX && mx<=c[i].dialStartX + c[i].width && my<= c[i].dialStartY + c[i].height && my>= c[i].dialStartY - c[i].height)
				{
					c[i].sliderX = mx;
					c[i].SliderOutput();
				}		
		
			}

			for(int i=0;i<N_FORCES;++i)
			{
				if(mx>=A[i].dialStartX && mx<=A[i].dialStartX + A[i].width && my<= A[i].dialStartY + A[i].height && my>= A[i].dialStartY - A[i].height)
				{
					A[i].sliderX = mx;
					A[i].SliderOutput();
				}		
		
			}
			for(int i=0;i<N_FORCES;++i)
			{
				if(mx>=f[i].dialStartX && mx<=f[i].dialStartX + f[i].width && my<= f[i].dialStartY + f[i].height && my>= f[i].dialStartY - f[i].height)
				{
					f[i].sliderX = mx;
					f[i].SliderOutput;
				}		
		
			}
			
				


		}

		FsGetMouseEvent(lb,mb,rb,mx,my)
		if(lb==1)
		{
			for(int i=0;i<N_FORCES;++i)
			{
				if(mx<= r[i].centreX + r[i].radius && mx>= r[i].centreX - r[i].radius && my<= r[i].centreY + r[i].radius && my>= r[i].centreY - r[i].radius)
				{
					DrawCircle(r[i].centreX,r[i].centreY,4,1);
					r[i].state = 1;
				}
				if(mx<= r[i].centreX + (8*14) + r[i].radius && mx>= r[i].centreX + (8*14) - r[i].radius && my<= r[i].centreY + r[i].radius && my>= r[i].centreY - r[i].radius)
				{
					DrawCircle(r[i].centreX + (8*14),r[i].centreY,4,1);
					r[i].state = 2;
				}
				if(mx<= r[i].centreX + (2*8*14) + r[i].radius && mx>= r[i].centreX + (2*8*14) - r[i].radius && my<= r[i].centreY + r[i].radius && my>= r[i].centreY - r[i].radius)
				{
					DrawCircle(r[i].centreX + (2*8*14),r[i].centreY,4,1);
					r[i].state = 3;
				}
				if(r[i].state != 3)
				{
					
					f[i].SliderX = f[i].dialStartX;
					
					f[i].SliderOutput();
				}


			}
			
		}
		FsSwapBuffers();
		FsSleep(50);
	
	}	
}


