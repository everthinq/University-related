#include "vect.h"
void g(int n)
{	try {
// ���� try - �������� ��� �������� ������� � ���, �����
// ����������� ���������� ��� �������������� ����������
	vect a(n);
	}
	catch (int n)	// ����������
	{
	cerr << "SIZE ERROR " << n << endl;
	g(10);
	}
	catch (const char* error)       // ����������
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

