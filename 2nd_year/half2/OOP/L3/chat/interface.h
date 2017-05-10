//---------------------------------------------------------------------------

#ifndef interfaceH
#define interfaceH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>

#include "IPclass.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPageControl *PageControl;
        TTabSheet *Main;
        TTabSheet *Add;
        TTabSheet *Check;
        TTabSheet *Add_Array;
        TButton *Btn_Check;
        TButton *Btn_Add;
        TButton *Btn_AddArr;
        TMemo *MemoMain;
        TButton *Btn_Save;
        TButton *Btn_AddBack;
        TButton *Button4;
        TButton *Button12;
        TLabel *Label_AddIP;
        TEdit *Edit_AddIP;
        TButton *Button_AddIP;
        TLabel *Label_Check;
        TButton *Btn_CheckIP;
        TLabel *Label_List;
        TMemo *Memo_List;
        TButton *Btn_AddList;
        TButton *Btn_Print;
        TTabSheet *Print;
        TButton *Button7;
        TMemo *Memo_Print;
        TButton *Btn_Exit;
        TLabel *Label_Print;
        TTabSheet *Save;
        TButton *Button1;
        TLabel *Label_Save;
        TButton *Btn_SaveIP;
        TEdit *Edit_CheckIP;
        void __fastcall Btn_AddClick(TObject *Sender);
        void __fastcall Btn_AddArrClick(TObject *Sender);
        void __fastcall Btn_CheckClick(TObject *Sender);
        void __fastcall Btn_AddBackClick(TObject *Sender);
        void __fastcall Btn_PrintClick(TObject *Sender);
        void __fastcall Btn_ExitClick(TObject *Sender);
        void __fastcall Button_AddIPClick(TObject *Sender);
        void __fastcall Btn_CheckIPClick(TObject *Sender);
        void __fastcall Btn_AddListClick(TObject *Sender);
        void __fastcall Btn_SaveClick(TObject *Sender);
        void __fastcall Btn_SaveIPClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
