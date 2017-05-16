//---------------------------------------------------------------------------

#ifndef vectH
#define vectH

#include <iostream.h>
class vect
{	private:
	int*	p;
	int	size;
	public:
	vect() { size = 11; p = new int[size]; }
	vect(int n);
~vect() { delete [] p; }
	int& element(int i);
	int ub() const { return (size - 1); }
};

//---------------------------------------------------------------------------
#endif
