#include "UIWindow.h"

void UIWindow::setPosition(const int uiWindowXPosition,const int uiWindowYPosition)
{
  windowX = uiWindowXPosition;
  windowY = uiWindowYPosition;

}

void UIWindow::setSize(const int uiWindowWidth,const int uiWindowHeight)
{
  windowWidth = uiWindowWidth;
  windowHeight = uiWindowHeight;
}

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
  return r[0].state;
}
const int UIWindow::getForce2Type(void)
{
  return r[1].state;
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
  const double leftMargin = windowWidth/20;
  const int fontHeight = 12;
  const int fontWidth = 8;
  const double margin = 12;
  const double lineSpacing = (9*windowHeight)/150;
  double sliderYCoord = ((4*windowHeight/150)) + leftMargin;
  const double startPosition = windowX + leftMargin;
  const double radioLabelMargin = 15;
  const double radioSpaceMargin = (fontWidth*14);
  for(int i=0;i<N_MASSES;++i)
  {
    mslider[i].Initialize(windowWidth, windowHeight, sliderYCoord);
    sliderYCoord+= lineSpacing;
  }
  for(int i=0;i<N_SPRINGS;++i)
  {
    k[i].Initialize(windowWidth, windowHeight, sliderYCoord);
    sliderYCoord+= lineSpacing;
  }
  for(int i=0;i<N_SPRINGS;++i)
  {
    c[i].Initialize(windowWidth, windowHeight, sliderYCoord);
    sliderYCoord+= lineSpacing;
  }

  auto key = FSKEY_NULL;
  while(FSKEY_ESC!=key)
  {

    FsPollDevice();
    for(int i=0;i<N_MASSES;++i)
    {
      mslider[i].DrawSlider();
      glRasterPos2d(mslider[i].dialStartX - margin,mslider[i].dialStartY + (double)fontHeight/2);
      YsGlDrawFontBitmap8x12("0");
      glRasterPos2d(mslider[i].dialStartX + mslider[i].width + margin,mslider[i].dialStartY + (double)fontHeight/2);
      YsGlDrawFontBitmap8x12("100");
    }
    for(int i=0;i<N_SPRINGS;++i)
    {
      k[i].DrawSlider();
      glRasterPos2d(k[i].dialStartX - margin,k[i].dialStartY + (double)fontHeight/2);
      YsGlDrawFontBitmap8x12("0");
      glRasterPos2d(k[i].dialStartX + k[i].width + margin,k[i].dialStartY + (double)fontHeight/2);
      YsGlDrawFontBitmap8x12("100");
    }
    for(int i=0;i<N_SPRINGS;++i)
    {
      c[i].DrawSlider();
      glRasterPos2d(c[i].dialStartX - margin,c[i].dialStartY + (double)fontHeight/2);
      YsGlDrawFontBitmap8x12("0");
      glRasterPos2d(c[i].dialStartX + c[i].width + margin,c[i].dialStartY + (double)fontHeight/2);
      YsGlDrawFontBitmap8x12("100");
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
    sliderYCoord+= lineSpacing;
    r[0].Initialize(winWidth,sliderYCoord);
    r[0].DrawRadio();
    glRasterPos2d(startPos + radioLabelMargin,sliderYCoord);
    YsGlDrawFontBitmap8x12("Constant");
    glRasterPos2d(startPos + radioLabelMargin + radioSpaceMargin,sliderYCoord);
    YsGlDrawFontBitmap8x12("Exponential");
    glRasterPos2d(startPos + radioLabelMargin + (2*radioSpaceMargin),sliderYCoord);
    YsGlDrawFontBitmap8x12("Sinosoidal");
    sliderYCoord+= lineSpacing;

    A[0].Initialize(windowWidth, windowHeight, sliderYCoord);
    A[0].DrawSlider();
    glRasterPos2d(A[0].dialStartX - margin,A[0].dialStartY + (double)fontHeight/2);
    YsGlDrawFontBitmap8x12("0");
    glRasterPos2d(A[0].dialStartX + A[0].width + margin,A[0].dialStartY + (double)fontHeight/2);
    YsGlDrawFontBitmap8x12("100");


    sliderYCoord+= lineSpacing;

    f[0].Initialize(windowWidth, windowHeight, sliderYCoord);
    f[0].DrawSlider();
    glRasterPos2d(f[0].dialStartX - margin,f[0].dialStartY + (double)fontHeight/2);
    YsGlDrawFontBitmap8x12("0");
    glRasterPos2d(f[0].dialStartX + f[0].width + margin,f[0].dialStartY + (double)fontHeight/2);
    YsGlDrawFontBitmap8x12("100");

    sliderYCoord+= lineSpacing;

    glRasterPos2d(startPos,sliderYCoord);
		YsGlDrawFontBitmap8x12("Force 2:");
		sliderYCoord+= lineSpacing;
		r[1].Initialize(winWidth,sliderYCoord);
		r[1].DrawRadio();
		glRasterPos2d(startPos + radioLabelMargin,sliderYCoord);
		YsGlDrawFontBitmap8x12("Constant");
		glRasterPos2d(startPos + radioLabelMargin + radioSpaceMargin,sliderYCoord);
		YsGlDrawFontBitmap8x12("Exponential");
		glRasterPos2d(startPos + radioLabelMargin + (2*radioSpaceMargin),sliderYCoord);
		YsGlDrawFontBitmap8x12("Sinosoidal");

    sliderYCoord+= lineSpacing;

    A[1].Initialize(windowWidth, windowHeight, sliderYCoord);
    A[1].DrawSlider();
    glRasterPos2d(A[1].dialStartX - margin,A[1].dialStartY + (double)fontHeight/2);
    YsGlDrawFontBitmap8x12("0");
    glRasterPos2d(A[1].dialStartX + A[1].width + margin,A[1].dialStartY + (double)fontHeight/2);
    YsGlDrawFontBitmap8x12("100");


    sliderYCoord+= lineSpacing;

    f[1].Initialize(windowWidth, windowHeight, sliderYCoord);
    f[1].DrawSlider();
    glRasterPos2d(f[1].dialStartX - margin,f[1].dialStartY + (double)fontHeight/2);
    YsGlDrawFontBitmap8x12("0");
    glRasterPos2d(f[1].dialStartX + f[1].width + margin,f[1].dialStartY + (double)fontHeight/2);
    YsGlDrawFontBitmap8x12("100");

    double mx,my,lb,rb,mb;

    FsGetMouseState(lb,mb,rb,mx,my);
    if(0!=lb)
    {
      for(int i=0;i<N_MASSES;++i)
      {
        if(mx>=mslider[i].dialStartX && mx<=mslider[i].dialStartX + mslider[i].width && my<=mslider[i].dialStartY + mslider[i].height && my>=mslider[i].dialStartY - mslider[i].height)
        {
          mslider[i].sliderX = mx;
        }
      }
      for(int i=0;i<N_SPRINGS;++i)
      {
        if(mx>=k[i].dialStartX && mx<=k[i].dialStartX + k[i].width && my<=k[i].dialStartY + k[i].height && my>=k[i].dialStartY - k[i].height)
        {
          k[i].sliderX = mx;
        }
      }
      for(int i=0;i<N_SPRINGS;++i)
      {
        if(mx>=c[i].dialStartX && mx<=c[i].dialStartX + c[i].width && my<=c[i].dialStartY + c[i].height && my>=c[i].dialStartY - c[i].height)
        {
          c[i].sliderX = mx;
        }
      }
      for(int i=0;i<N_FORCES;++i)
      {
        if(mx>=A[i].dialStartX && mx<=A[i].dialStartX + A[i].width && my<=A[i].dialStartY + A[i].height && my>=A[i].dialStartY - A[i].height)
        {
          A[i].sliderX = mx;
        }
      }
      for(int i=0;i<N_FORCES;++i)
      {
        if(mx>=f[i].dialStartX && mx<=f[i].dialStartX + f[i].width && my<=f[i].dialStartY + f[i].height && my>=f[i].dialStartY - f[i].height)
        {
          f[i].sliderX = mx;
        }
      }

      for(int i=0;i<N_FORCES;++i)
      {
        if(mx<= r[i].centreX + r[i].radius && mx>= r[i].centreX - r[i].radius && my<= r[i].centreY + r[i].radius && my>= r[i].centreY - r[i].radius)
        {
          DrawCircle(r[i].centreX,r[i].centreY,4,1);
          r[i].state = 1;
        }
        if(mx<= r[i].centreX + radioSpaceMargin + r[i].radius && mx>= r[i].centreX + radioSpaceMargin - r[i].radius && my<= r[i].centreY + r[i].radius && my>= r[i].centreY - r[i].radius)
        {
          DrawCircle(r[i].centreX + radioSpaceMargin,r[i].centreY,4,1);
          r[i].state = 2;
        }
        if(mx<= r[i].centreX + (2*radioSpaceMargin) + r[i].radius && mx>= r[i].centreX + (2*radioSpaceMargin) - r[i].radius && my<= r[i].centreY + r[i].radius && my>= r[i].centreY - r[i].radius)
        {
          DrawCircle(r[i].centreX + (2*radioSpaceMargin),r[i].centreY,4,1);
          r[i].state = 3;
        }
        if(r[i].state != 3)
        {
          f[i].SliderX = f[i].dialStartX;

        }
      }




      }
    }

  }
