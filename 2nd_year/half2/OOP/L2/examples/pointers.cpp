#include <stdlib.h>
#include <iostream.h>
#include <string.h>
#include <stdarg.h>
void OK(char *format, ...)  //������� OK � ������������ ������  ����������
{
   void *start = &format;
   start = (char*) start + sizeof(int);

 for(char *p = format; *p; p++)
 {
  if (*p == '%')  //���� ���������� ������ %
   {
      switch (*++p) //�� ����������� ��������� �� ���� �������� ������
     {
       case 'd'://���� ��� ������ d, �� ������ �������� int
       {
         cout << *(int*)start << " ";  //������� �������� ���� int �� �����
         start = (char*) start + sizeof(int); break;
       }

      case 'f': //���� ��� ������ f ������ �������� double
       {
         cout << *(double*)start << " ";   //������� �������� ���� double �� �����
         start = (char*) start + sizeof(double); break;
       }
     }
   }
   else cout << *p <<" ";
 }
}

void main()
{
 system("CLS");
 OK("%d%f%d%d%f", 1, 12.3, 123, 346, 123.52);    //����� ���� ����� � ������� ������
 system("PAUSE");
 return;
}

