#ifndef CircleH
#define CircleH
#include <vcl.h>
#include <math.h>
#include "Figure.h"
//---------------------------------------------------------------------------
class Circle : public Figure
{
   public:

int X1, Y1, X2, Y2, R;
void Move(TObject *Sender, int X, int Y, int X1, int Y1, TShiftState Shift);
void Draw(TImage* img, int X1, int Y1, int X2, int Y2, TColor Color, int Size);

/*void CircleRadius();
void ResizeUP(int R){R++;}
void ResizeDOWN(int R){R--;}*/

};
//---------------------------------------------------------------------------
#endif
