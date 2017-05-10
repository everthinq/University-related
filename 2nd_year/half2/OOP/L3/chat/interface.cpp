//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "interface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
IPAdresses List;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        PageControl->Top-=20;
        Form1->Height-=20;
        PageControl->ActivePage=Main;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Btn_AddClick(TObject *Sender)
{
        PageControl->ActivePage=Add;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_AddArrClick(TObject *Sender)
{
        PageControl->ActivePage=Add_Array;
        Memo_List->Lines->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_CheckClick(TObject *Sender)
{
        PageControl->ActivePage=Check;
        Edit_CheckIP->Text="";        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_AddBackClick(TObject *Sender)
{
        PageControl->ActivePage=Main;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_PrintClick(TObject *Sender)
{
        Memo_Print->Lines->Clear();
        String isEmpty=List.Print();
        if (!isEmpty.IsEmpty())
            {
             Memo_Print->Lines->Add(List.Print());
             PageControl->ActivePage=Print;
            }
        else Application->MessageBox("������ IP-������� ����   ","������",MB_ICONWARNING);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_ExitClick(TObject *Sender)
{
        if (
        Application->MessageBox("�� ������������� ������ �����?",
        "�����",MB_YESNO|MB_ICONQUESTION)==IDYES
            ) Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button_AddIPClick(TObject *Sender)
{
        String str=Edit_AddIP->Text;
        bool IsIPRight=List.Add(str);
        if (IsIPRight) Application->MessageBox("��� IP ��� ������� ��������   ","�����",MB_ICONASTERISK);
        else Application->MessageBox("������ ���������� IP   ","������",MB_ICONWARNING);
        PageControl->ActivePage=Main;
        Edit_AddIP->Text="";
}                                            
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_CheckIPClick(TObject *Sender)
{
        String Ip=Edit_CheckIP->Text;
        bool IsIPRight=List.IsAdress(Ip);
        if (IsIPRight) Application->MessageBox("��� IP ������ �����   ","�����",MB_ICONASTERISK);
        else Application->MessageBox("�������� IP-�����   ","������",MB_ICONWARNING);
        PageControl->ActivePage=Main;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_AddListClick(TObject *Sender)
{
        TStringList *IPArray=new TStringList;

        for (int i=0; i<Memo_List->Lines->Count; i++)
          IPArray->Add(Memo_List->Lines->Strings[i]);

        bool IsIPRight=List.Add_Array(IPArray);
        if (IsIPRight) Application->MessageBox("���������� ������ �������  ","�����",MB_ICONASTERISK);
        else Application->MessageBox("������ ����������   ","������",MB_ICONWARNING);
        delete IPArray;
        PageControl->ActivePage=Main;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_SaveClick(TObject *Sender)
{

        PageControl->ActivePage=Save;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_SaveIPClick(TObject *Sender)
{
        bool IsIPRight=List.Save();
        if (IsIPRight) Application->MessageBox("���������� ������ �������  ","�����",MB_ICONASTERISK);
        else Application->MessageBox("������ ����������   ","������",MB_ICONWARNING);
        PageControl->ActivePage=Main;
}
//---------------------------------------------------------------------------

