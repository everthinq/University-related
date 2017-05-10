//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        Form1->DoubleBuffered = true;
        TImage* img = NULL;
        Moving = false; CirclePainting = false; Selecting = false;
}

//---------------------------------------------------------------------------


void __fastcall TForm1::ToolButton1Click(TObject *Sender)
{

        Moving = true;
        CirclePainting = false;
        Selecting = false;

}

//---------------------------------------------------------------------------

void __fastcall TForm1::ToolButton2Click(TObject *Sender)
{

        Moving = false;
        CirclePainting = true;
        Selecting = false;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::ToolButton3Click(TObject *Sender)
{

        Moving = false;
        CirclePainting = false;
        Selecting = true;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
   X1 = X; rectX1 = X;
   Y1 = Y; rectY1 = X;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
   if (Moving == true)
        Circle1->Move(Sender, X, Y, X1, Y1, Shift);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
      X2 = X; rectX2 = X;
      Y2 = Y; rectY2 = X;
  if (CirclePainting == true)
  {
    img = new TImage(this);
    int Size = ComboBox1->ItemIndex;
    Circle1->Draw(img, X1, Y1, X2, Y2, ColorBox1->Selected, Size);
    AllCircles.push_back(img);
    img->Parent = Form1;
    img->OnMouseDown = FormMouseDown;
    img->OnMouseMove = FormMouseMove;
    img->OnClick = Image1Click;
    Memo1->Lines->Add(IntToStr(AllCircles.size()));
  }
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Image1Click(TObject *Sender)
{
   if (Selecting == true)
   {
     if (img = dynamic_cast <TImage*> (Sender))
     {
         SelectedCircles.push_back(img);

        for (unsigned int i = 0; i < AllCircles.size(); i++)
        {
          for (unsigned int j = 0; j < SelectedCircles.size(); j++)
          {
              if (AllCircles[i] == SelectedCircles[j]) // pointer values compare
              {
                  delete AllCircles[i];
                  AllCircles.erase(AllCircles.begin() + i);
              }
          }
        } Memo2->Lines->Add(IntToStr(SelectedCircles.size()));
      }
   }
}

//---------------------------------------------------------------------------

void __fastcall TForm1::DeleteALL1Click(TObject *Sender)
{
  for(unsigned int i = 0; i < AllCircles.size(); i++)
      delete AllCircles[i];
        AllCircles.clear();
}

//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
  for(unsigned int i = 0; i < AllCircles.size(); i++)
      delete AllCircles[i];
        AllCircles.clear();
}

//---------------------------------------------------------------------------

void __fastcall TForm1::DeleteLAST1Click(TObject *Sender)
{
 if(AllCircles.empty() == false)
 {
  delete this->img;
  AllCircles.pop_back();
  this->img = AllCircles.back();
 }
}

//---------------------------------------------------------------------------

