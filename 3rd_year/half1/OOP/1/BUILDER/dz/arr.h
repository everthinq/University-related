//---------------------------------------------------------------------------

#ifndef arrH
#define arrH

#include<iostream.h>

class A
{
        public: A();
                A(int, int);    //заполняем числом

                ~A()            //деструктор
                        { if (a) delete [] a; a=NULL; }


                int& operator [] (int n) const //перегрузка оператора
                        { if ((n>=l)||(n<0)) throw ("INCORRECT INDEX"); return a[n]; }


                A& operator ++ (int);

                int GetLength () const { return l;}
                void Print () const;

        private:
                int *a;       //указатель на массив
                int l;        //длина
};
//---------------------------------------------------------------------------
#endif
