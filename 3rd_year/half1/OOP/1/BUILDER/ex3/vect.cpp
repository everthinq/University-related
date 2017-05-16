//---------------------------------------------------------------------------

#pragma hdrstop

#include "vect.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

vect::vect(int n)
{	if(n < 1)	// оговоренное предусловие
	        throw (n);	// устанавливается исключение

	p = new int[n];
	if(p == 0)	// оговоренное постусловие
	        throw ("FREE STORE EXHAUSTED");	// устанавливается
		// исключение
}
int& vect::element(int n)
{	if(n < 0 || n > size-1)
        	throw ("ILLEGAL NUMBER OF ELEMENT");
                // устанавливается исключение
	return (p[n]);
}
