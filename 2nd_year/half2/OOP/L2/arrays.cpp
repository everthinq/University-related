#include <stdlib.h>
#include <iostream.h>
#include <stdarg.h>
#include <conio.h>
#pragma hdrstop
#pragma argsused

 int *array;
 int amount, i;

 void InputOutputBaseArray(int amount)
 {
   array = new int[amount];
  for(i = 0; i < amount; i++)
  {
   cout << "enter " << i <<" element: ";
   cin >> array[i];
  }cout << "\n";            //input base array

    cout << "   array = ";
    for(i = 0; i < amount; i++)
     cout << array[i] << " ";
    cout << "\n";           //output base array
 }

void DeleteAndMove(int* array, int amount)
{
    int temp, j;

    for(i = 0; i < amount; i++)
    {
     if(array[i] < 0)
     array[i] = 0;
    }

    for(i = 0; i < amount - 1; i++) // i - номер прохода
    {
        for(j = 0; j < amount - 1; j++) // внутренний цикл прохода
        {
            if (array[j] == 0)
            {
                temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

void OutputNewArray()
{
   cout << "NEWarray = ";
       for(i = 0; i < amount; i++)
        cout << array[i] << " ";
       cout << "\n";           //output NEW array
    delete []array;
}

int main(int argc, char* argv[])
{
 cout << "enter amount of elements" << endl;
 cin >> amount; cout<<"\n";
 InputOutputBaseArray(amount);
 DeleteAndMove(array, amount);
 OutputNewArray();
 getch();
}

