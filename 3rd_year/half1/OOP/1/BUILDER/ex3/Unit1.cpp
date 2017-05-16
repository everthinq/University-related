#include "vect.h"
void g(int n)
{	try {
// блок try - контекст для принятия решения о том, какие
// обработчики вызываются для установленного исключения
	vect a(n);
	}
	catch (int n)	// обработчик
	{
	cerr << "SIZE ERROR " << n << endl;
	g(10);
	}
	catch (const char* error)       // обработчик
	{
	cerr << error << endl;
	abort();
	}
        catch (...)
        {
                cerr<<"ANY TYPE ERROR\n";
        }
}
void main()
{
	extern void g(int n);
	g(21);
        vect a;
        a.element(-1);

        system("pause");
}

