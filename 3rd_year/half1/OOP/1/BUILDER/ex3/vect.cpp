//---------------------------------------------------------------------------

#pragma hdrstop

#include "vect.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

vect::vect(int n)
{	if(n < 1)	// ����������� �����������
	        throw (n);	// ��������������� ����������

	p = new int[n];
	if(p == 0)	// ����������� �����������
	        throw ("FREE STORE EXHAUSTED");	// ���������������
		// ����������
}
int& vect::element(int n)
{	if(n < 0 || n > size-1)
        	throw ("ILLEGAL NUMBER OF ELEMENT");
                // ��������������� ����������
	return (p[n]);
}
