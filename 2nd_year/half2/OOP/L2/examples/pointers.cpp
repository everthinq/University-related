#include <stdlib.h>
#include <iostream.h>
#include <string.h>
#include <stdarg.h>
void OK(char *format, ...)  //Функция OK с произвольным числом  параметров
{
   void *start = &format;
   start = (char*) start + sizeof(int);

 for(char *p = format; *p; p++)
 {
  if (*p == '%')  //Если встретится символ %
   {
      switch (*++p) //То анализируем следующий за этим символом символ
     {
       case 'd'://Если это символ d, то значит параметр int
       {
         cout << *(int*)start << " ";  //Выводим параметр типа int на экран
         start = (char*) start + sizeof(int); break;
       }

      case 'f': //Если это символ f значит параметр double
       {
         cout << *(double*)start << " ";   //Выводим параметр типа double на экран
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
 OK("%d%f%d%d%f", 1, 12.3, 123, 346, 123.52);    //Вывод двух чисел с разными типами
 system("PAUSE");
 return;
}

