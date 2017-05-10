#include <iostream.h>

class MyClass
{
   public:
        static int n;
        static int addn(int arg){return n+arg;}
};
// инициализация статического члена данных
int MyClass::n=30;

int main() {
	// обращение к статическим членам через имя класса
	MyClass::n=3;
	cout<<MyClass::addn(2)<<endl;

	// обращение к статическим членам через объект
	MyClass cls;
	cls.n=5;
	cout<<cls.addn(2)<<endl;
        
        system("pause");
	return 0;
}

