#include <iostream.h>

class MyClass
{
   public:
        static int n;
        static int addn(int arg){return n+arg;}
};
// ������������� ������������ ����� ������
int MyClass::n=30;

int main() {
	// ��������� � ����������� ������ ����� ��� ������
	MyClass::n=3;
	cout<<MyClass::addn(2)<<endl;

	// ��������� � ����������� ������ ����� ������
	MyClass cls;
	cls.n=5;
	cout<<cls.addn(2)<<endl;
        
        system("pause");
	return 0;
}

