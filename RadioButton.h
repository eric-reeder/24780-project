#ifndef RADIOBUTTON_H
  #define RADIOBUTTON_H

  class RadioButton
  {
  protected:
    int state;
    double centreX, centreY, radius;
  public:
    void Initialize(const double winWidth,const double startY);
    void DrawRadio(void) const;

  };

  void DrawCircle(const double cx,const double cy,const double radius,const int fill);

  #endif
