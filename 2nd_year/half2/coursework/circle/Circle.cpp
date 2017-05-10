#include "Circle.h"
#pragma hdrstop
//---------------------------------------------------------------------------
void Circle::Move(TObject *Sender, int X, int Y, int X1, int Y1, TShiftState Shift)
{
        TImage *moveImage = ((TImage*)Sender);
        if (Shift.Contains(ssLeft))
        {
          moveImage->Left += X - X1;
          moveImage->Top += Y - Y1;
        }
}
//---------------------------------------------------------------------------
void Circle::Draw(TImage* img, int X1, int Y1, int X2, int Y2, TColor Color, int Size)
{
  if (X2 - X1 > 0)
        img->Left = X1;
      else
        img->Left = X2;

  if (Y2 - Y1 > 0)
         img->Top = Y1;
       else
         img->Top = Y2;

   img->Width  = abs(X2 - X1);
   img->Height = abs(Y2 - Y1);
   img->Transparent = true;
   img->Canvas->Pen->Color = Color;
   img->Canvas->Pen->Width =  Size;
   img->Canvas->Ellipse(0, 0, abs(X2 - X1), abs(Y2 - Y1));
}

#pragma package(smart_init)

