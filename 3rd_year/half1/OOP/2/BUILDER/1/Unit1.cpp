#include <iostream.h>
#include <string.h>
int main()
{
   system("chcp 1251");
   string in_string;
   // ������� ������� �� �������� ������������
   cout << "������� ���� ���, ����������: ";
   // ��������� ����� ������������ � in_string
   cin >>  in_string;
   if ( in_string.empty() )
      // ������� ��������� �� ������ �� �������� ������������
      cerr << "������: ��������� ������ �����!\n";
   else cout << "������, " << in_string << "!\n";
   system("pause");
}

