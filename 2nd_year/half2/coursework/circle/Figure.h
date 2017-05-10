//---------------------------------------------------------------------------
#include <vcl.h>
#ifndef FigureH
#define FigureH

class Figure : public TImage
{
 virtual void Draw() = 0;
 virtual void Move() = 0;
};
//---------------------------------------------------------------------------
#endif
