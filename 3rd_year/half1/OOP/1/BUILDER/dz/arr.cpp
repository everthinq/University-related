//---------------------------------------------------------------------------

#pragma hdrstop

#include "arr.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
A::A():a(0), l(0) {}

A::A(int n, int FillNumber)
{
        a=new int[n];

        if (!a)
                throw ("FREE STORE EXHAUSTED");

        for (int i=0; i<n; i++)
                a[i]=FillNumber;
        l=n;
}

void A::Print () const
{
        for (int i=0; i<l; i++)
                cout<<a[i]<<" ";

        cout<<endl;        
}

A& A::operator ++ (int n)
{
        for (int i=0; i<l; i++)
                this->a[i]+=1;

        return *this;
}
