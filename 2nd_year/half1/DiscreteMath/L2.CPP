#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<iomanip.h>

typedef int Set[25];
typedef int Relation[25][2];

//vvod mnojestva
void read_mas (Set dest, int size_of_set)
{
 for(int i = 0; i < size_of_set; i++)
 {
  cout << "Enter " << i + 1 << " element:" << endl;
  cin >> dest[i];
 }
}

//vvod otnosheniya
void read_alfa (Relation dest, int size_of_relation)
{
 for (int i = 0;i < size_of_relation; i++)
 {
 cout << "Enter " << i + 1 << " relation" << endl;
 cin >> dest[i][0] >> dest[i][1];
 }
}

//vivod mnojestva
void print_mas (Set dest, int size_of_set)
{
 cout << "{";
 for (int i = 0; i < size_of_set; i++)
 cout << dest[i] << " ";
 cout << "}" << endl;
} 

//vivod otnosheniya
void print_alfa (Relation dest, int size_of_relation)
{
 cout << "{";
 for (int i = 0; i < size_of_relation; i++)
 {
  cout << "{" << dest[i][0] << " " << dest[i][1] << "}";
 }
 cout << "}" << endl;
}

//proverka na refleksivnost`
int Refleks (Relation R, int size_of_relation, Set set, int size_of_set)
{
 int Refl = 0;
 for (int i = 0; i < size_of_set; i++)
 for (int j = 0; j < size_of_relation; j++)
 {
  if (set[i] == R[j][0] && set[i] == R[j][1])
  {
  Refl++;
  break;
  }
 }
 if (Refl == size_of_set) return 1;
 return 0;
}

int main()
{
 clrscr();
 while (1)
 {
 int l = 0;
 cout << endl << "1 - TASK 2.1(c)";   //1(c)
 cout << endl << "2 - TASK 5     ";   //2.1(b)
 cout << endl << "3 - TASK 10(a) ";   //5
 cout << endl << "4 - TASK 11(a) ";   //11(b)
 cout << endl << "Enter number: ";
 cin >> l;
 switch(l)
 {
 case 1: { clrscr();
	   int dest[5] = {1, 0};
	   int x = 0, y = 0, number = 5;
	   int relation[2][2];
	   int p = 0;

	   for (int i = 0; i < number; i++)
	   {
	    x = dest[i];
	    for (int j = 0; j < number; j++)
	    {
	     y = dest[j];
	     if (x * y > 1)
	     {
	      relation[p][0] = x;
	      relation[p][1] = y;
	      p++;
	     }
	    }
	   }

	  if (Refleks (relation, p, dest, number)) cout << "Refl" << endl;
	   else cout << "Ne Refl" << endl;

	  int s = 0, t = 0;
	  for (i = 0;  i < number; i++)
	  {
	   if (relation[i][0] == relation[i][1]) s++;
	   if (relation[i][0] == relation[i - 1][0]) t++;
	  }

	  if (!s) cout << "Ne simm" << endl;
	  else cout << "Simm" << endl;
	  if (!t) cout << "Tranz" << endl;
	  else cout << "Netranz" << endl;
	  break;
	 }

 case 2: { clrscr();
	   int dest[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	   int number = 11;
	   int relation[50][2];
	   int a = 0, b = 0, p = 0;

	   for (int i = 0; i < number; i++)
	   {
	    a = dest[i];
	    for (int j = 0; j < number; j++)
	    {
	     b = dest[j];
	     if ((a + b) % 2 == 0)
	     {
	      relation[p][0] = a;
	      relation[p][1] = b;
	      p++;
	     }
	    }
	   }
           cout<<"R: ";print_alfa (relation, p); cout<<endl;
                   
	   for (i = 0; i < number; i++)
	   {
	    for (int j = 0; j < number; j++)
	    {
	     if ((dest[i] + dest[j]) % 2 == 0) cout << "1 ";
	     else cout << "0 ";
	    }
	   cout << endl;
	   }
           break;
	  }
         

 case 3: { clrscr();
	   int dest[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	   int number = 9;
	   int relation[50][2];
	   int a = 0, b = 0, p = 0;

	   for (int i = 0; i < number; i++)
	   {
	    a = dest[i];
	    for (int j = 0; j < number; j++)
	    {
	     b = dest[j];
	     if ((a - b) % 2 == 0)
	     {
	      relation[p][0] = a;
	      relation[p][1] = b;
	      p++;
	     }
	    }
	   }
	   cout<<"R: ";print_alfa (relation, p); cout<<endl;
           p=0;

	if (Refleks (relation, p, dest, number)) cout << "Refl" << endl;
	   else cout << "Ne Refl" << endl;

	  int s = 0, t = 0;
	  for (i = 0;  i < number; i++)
	  {
	   if (relation[i][0] == relation[i][1]) s++;
	   if (relation[i][0] == relation[i - 1][0]) t++;
	  }

	  if (!s) cout << "Ne simm" << endl;
	  else cout << "Simm" << endl;
	  if (!t) cout << "Tranz" << endl;
	  else cout << "Netranz" << endl;
	  break;
	 }

 case 4: { clrscr();
	   int dest[] = {1, 3, 5, 7};
	   int relation[25][2];
	   int number = 4;
	   int a = 0, b = 0, p = 0;

	   for (int i = 0; i < number; i++)
	   {
	    a = dest[i];
	    for (int j = 0; j < number; j++)
	    {
	     b = dest[j];
	     if (a <= b)
	     {
	      relation[p][0] = a;
	      relation[p][1] = b;
	      p++;
	     }
	    }
	   }
	   cout<<"R: ";print_alfa (relation, p); cout<<endl;
	   p = 0;
  
	   for (i = 0; i < number; i++)
	   {
	    a = dest[i];
	    for (int j = 0; j < number; j++)
	    {
	     b = dest[j];
	     if (a >= b)
	     {
	      relation[p][0] = a;
	      relation[p][1] = b;
	      p++;
	     }
	    }
	   }
	   cout<<"R^-1: "; print_alfa (relation, p); cout<<endl;
           p = 0;

	   break;
         }

 default: exit(1);
  }
 }
 getch();
 return 0;
}