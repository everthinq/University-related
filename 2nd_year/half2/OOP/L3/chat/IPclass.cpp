//---------------------------------------------------------------------------
#pragma hdrstop
#include "IPclass.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
IPAdresses::IPAdresses():PathToFile("Adresses.txt"){list=new TStringList;}
//---------------------------------------------------------------------------
IPAdresses::IPAdresses(TStringList* IPs){Add_Array(IPs);}
//---------------------------------------------------------------------------
IPAdresses::~IPAdresses()
{
       delete list;
}
//---------------------------------------------------------------------------
bool IPAdresses::Add(String &Ip)
{
        if (!IsAdress(Ip)) return false;
        list->Add(Ip);
        return true;
}
//---------------------------------------------------------------------------
bool IPAdresses::IsAdress(String Ip) const
{
        if (Ip.IsEmpty()) return false;
        if (Ip.Length()<=0&&Ip.Length()>15) return false;

        int index=1, count=0;
        String SubString;
        int value;

        for (int i=0; i<4; i++)
         {
           if (i==3)
             {
               count=Ip.Length();
               SubString=Ip.SubString(index,count);
             }
           else
             {
                count=Ip.AnsiPos(".");
                SubString=Ip.SubString(index,count-1);
             }

           value=SubString.ToInt();
           if (value<0||value>255) return false;
           Ip.Delete(index,count);
         }

        return true;
}
//---------------------------------------------------------------------------
bool IPAdresses::Add_Array(TStringList* IPArray)
{
        if (IPArray->Text.IsEmpty()) return false;
        
        String temp;
        for (int i=0; i<IPArray->Count; i++)
           {
            temp=IPArray->Strings[i];
            if (!IsAdress(temp)) continue;
            list->Add(IPArray->Strings[i]);
           }

        return true;
}
//---------------------------------------------------------------------------
String IPAdresses::Print() const
{
        return list->Text;
}
//---------------------------------------------------------------------------
bool IPAdresses::Save() const
{
        if (list->Text.IsEmpty()) return false;
        list->SaveToFile(PathToFile);
        return true;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
