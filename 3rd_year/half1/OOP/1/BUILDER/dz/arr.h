//---------------------------------------------------------------------------

#ifndef arrH
#define arrH

#include<iostream.h>

class A
{
        public: A();
                A(int, int);    //��������� ������

                ~A()            //����������
                        { if (a) delete [] a; a=NULL; }


                int& operator [] (int n) const //���������� ���������
                        { if ((n>=l)||(n<0)) throw ("INCORRECT INDEX"); return a[n]; }


                A& operator ++ (int);

                int GetLength () const { return l;}
                void Print () const;

        private:
                int *a;       //��������� �� ������
                int l;        //�����
};
//---------------------------------------------------------------------------
#endif
