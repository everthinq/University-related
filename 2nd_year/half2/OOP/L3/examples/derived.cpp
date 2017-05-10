#pragma hdrstop
#pragma argsused
//---------------------------------------------------------------------------
class CBase
{
  private:
          int privateBase;
  protected:
          int protBase;
  public:
          int pubBase;

          void SetPrivateBase(int value);
};

void CBase::SetPrivateBase(int value)
{
	if(value>0) privateBase=value;
	else privateBase=0;
}
//----------------------------------------------------------------------------

class CDerived : public CBase
{
	public:
	        void SetProtBase(int value);
                int GetProtBase();
};

void CDerived::SetProtBase(int value)
{
	if(value%3) protBase=value;
	else protBase=0;
}

int CDerived:: GetProtBase()
{
	return protBase*2;
}
//------------------------------------------------------------------

int main()
{
 CBase obj1,*obj2=new CBase();
 obj1.pubBase=10;
 obj2->pubBase=11;
 //obj1.privateBase=10; //ошибка - данное поле доступно только методам класса CBase
 //obj1.protBase =10;   //ошибка - данное поле доступно только методам класса CBase и классам
 obj1.SetPrivateBase(5);


 return 0;
}

