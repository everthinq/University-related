//---------------------------------------------------------------------------
#include <iostream.h>

void vect(int n)
{	if (n < 1)
	        throw(n);

	int *p = new int[n];

	if (p == 0)
                throw("FREE STORE EXHAUSTED");
}

void g()
{
        try
        {
            vect(0);
	}

 catch(int n) //отслеживает все неправильные размеры
 {
        cerr<<"exception\n";
 }
 catch(char* err) {   } //отслеживает превышение свободной памяти
}

int main(int argc, char* argv[])
{
        g();
        system("pause");
        return 0;
}
//---------------------------------------------------------------------------
 