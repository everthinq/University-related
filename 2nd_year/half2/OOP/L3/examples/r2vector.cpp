#include <iostream.h>
#pragma hdrstop
#pragma argsused

 class R2Vector
    {
      public:
              R2Vector(double number):len(number){}
              double length() {return len;}
              int length() const {return len+10;}
     private:
              double len;
    };

int main(int argc, char* argv[])
 {
        /*
        const int *p;
        int x=4;
        int * const d = &x;
          */
        R2Vector v(5);
        const R2Vector v2=v;

        cout<<"v.length="<<v.length()<<endl;
        cout<<"---------------------\n";
        cout<<"v2.length="<<v2.length()<<endl;
        

        system("pause");
        return 0;
 }
//---------------------------------------------------------------------------
 