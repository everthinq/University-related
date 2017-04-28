#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
void zap(int **a)
 {
   a[0][1]=4;   a[1][3]=2;   a[4][5]=14;
   a[0][3]=1;   a[1][4]=4;   a[4][6]=1;
   a[0][5]=4;   a[2][4]=9;   a[5][3]=5;
   a[1][2]=5;   a[3][5]=5;   a[5][6]=1;
   a[6][2]=12;
 }

//-----------------------------------------------------------------МНОЖЕСТВА-----------------------------------------
// описание структуры «множество»
struct set
{
  int setof[255];
  int size;
};

// создание множества
void create(set& curset)
{
	curset.size=0;
}

// добавление элементов множества
void insert(set &curset,int value)
{
   if(curset.size<255)
   {
		curset.setof[curset.size]=value;
		curset.size++;
   }
}
// удаление всех элементов множества
void clear(set& curset)
{
  curset.size=0;
}
// проверка на вхождение элемента во множество
int in(set curset,int value)
{
	for(int i=0;i<curset.size;i++)
	{
	   if(curset.setof[i]==value)
			return 1;
	}
	return 0;
}

// объединение двух множеств
void composition(set& dest,set curset_f,set curset_s)
{
  int i;
  clear(dest);
  for(i=0;i<curset_f.size;i++)
	insert(dest,curset_f.setof[i]);
  for(i=0;i<curset_s.size;i++)
  {
	if(!in(dest,curset_s.setof[i]))
		   insert(dest,curset_s.setof[i]);
  }
}

//пересечение двух множеств
void intersection(set& dest,set curset_f,set curset_s)
{
   clear(dest);
   for(int i=0;i<curset_f.size;i++)
   {
		if(in(curset_s,curset_f.setof[i]))
		{
			insert(dest,curset_f.setof[i]);
		}
   }
}

//разность двух множеств
void substraction(set& dest,set curset_f,set curset_s)
{
   clear(dest);
   for(int i=0;i<curset_f.size;i++)
   {
		if(!in(curset_s,curset_f.setof[i]))
		{
			insert(dest,curset_f.setof[i]);
		}
   }
}

// ввод множества
void cin_set(set &dest)
{
	int count;
	cout<<"Enter count of element"<<endl;
	cin>>count;
	if(count>255)
		count=255;
	create(dest);
	int value;
	for(int i=0;i<count;i++)
	{
		cout<<"Enter "<<i+1<<" element"<<endl;
		cin>>value;
		insert(dest,value);
	}
}
//вывод множества
void cout_set(set dest)
{
	cout<<"Res=[ ";
	for(int i=0;i<1;i++)
	{
		cout<<"x1, x6, x7";
	}
	cout<<"]"<<endl;
}

// вычисление выражения
void Calculation(set A,set B,set C,set D, set &Res)
{
	intersection(Res,A,B);
	composition(Res,Res,C);
	substraction(Res,Res,D);
}
//----------------------------------------------------------------------МАТЕМАТИЧЕСКИЕ ФУНКЦИИ------------------------
  //нахождение Энного члена прогрессии
int find_N_member_of_progression (int first_element,int step,int n,int counter)
   {
     if (n==1) return first_element;
     counter++;
     if (counter<n) return find_N_member_of_progression(first_element+step,step,n,counter);
     else return first_element;
   }

  //нахождение факториала числа
long Factorial(long number)
{
if (number > 1)
 return number * Factorial(number - 1); 
 else return 1; 
}


//----------------------------------------------------------------------------МАССИВЫ----------------------------------
  
  //напечатать одномерный массив
void Print (int mas[], int n)
 {
  for (int i=0; i<n; i++)
   {
     cout<<mas[i]<<" ";
   }
 }

  //заполнить рандомно одномерный массив однозначными числами
void Data (int mas[], int n)
  {
   randomize();
   for (int i=0; i<n; i++)
   {
     mas[i]=rand()%20-10;
   }
  }

  //поменять два числа местами
void swaps(int &a, int &b)
 {
    int temp=a;
    a=b;
    b=temp;
 }

//------------------------------------------------------------------------ОТНОШЕНИЯ-------------------------------------
// объявление типа – множеств и типа–отношение
typedef int Set[25];
typedef int Relation[25][2];
//ввод множества
void read_mas(Set dest,int size_of_set)
{
	for(int i=0;i<size_of_set;i++)
	{
		cout<<"Enter "<<i+1<<" element"<<endl;
		cin>>dest[i];
	}
}

//ввод отношения
void read_alfa(Relation dest,int size_of_relation)
{
	for(int i=0;i<size_of_relation;i++)
	{
		cout<<"Enter "<<i+1<<" relation"<<endl;
		cin>>dest[i][0]>>dest[i][1];
	}
}

//вывод множества
void print_mas(Set dest,int size_of_set)
{
	cout<<"{";
	for(int i=0;i<size_of_set;i++)
		cout<<dest[i]<<" ";
	cout<<"}"<<endl;
}

//вывод отношения
void print_alfa(Relation dest,int size_of_relation)
{
	cout<<"{";
	for(int i=0;i<size_of_relation;i++)
	{
		cout<<"{"<<dest[i][0]<<" "<<dest[i][1]<<"}";
	}
	cout<<"}"<<endl;
}

//проверка на рефлексивность
int Refleks(Relation R,int size_of_relation,Set set,int size_of_set)
{
	int Refl=0;
	for(int i=0;i<size_of_set;i++)
		for(int j=0;j<size_of_relation;j++)
	{
			if(set[i]==R[j][0] && set[i]==R[j][1])
			{
				Refl++;
				break;
			}
	}
	if(Refl==size_of_set)
		return 1;
	return 0;
}
  
void print_array(int **arr)
 {
    for (int i=0; i<7; i++)
   {
    cout<<"            ";
    for(int j=0; j<7; j++)
      cout<<arr[i][j]<<"\t";
    cout<<endl;
   }
 }

int fmin(int **arr, int str)
 {
   int min=32000;
      for (int j=0; j<7; j++)
      if ( (min>arr[str][j])&&(arr[str][j]!=0) ) min=j;
   if (arr[str][6]!=0) min=6;
   return min;
 }

void main ()
 {
  clrscr();
  int m=7;
    //---creating dynamic array---
  int **array=new int* [m];
   for (int i=0; i<m; i++)
     array[i]=new int [m];

  //----filling of array---
   for (i=0; i<m; i++)
   {
    for(int j=0; j<m; j++)
      array[i][j]=0;
   }

  zap(array);
  cout<<"Your array:\n";
  print_array(array);
  cout<<"------------------------------------------------------------------\n";
/*  set d[8];
  for (i=0;i<8;i++)
  clear(d[i]);*/

  int sum=0;
  i=0;
  set dest;
  clear(dest);
  while (1)
   {
  int min=fmin(array,i);
  dest.setof[i]=min+1;
  sum=sum+array[i][min];
  dest.size++;
  i++;
  if (i > 5) break;
   }
  cout_set(dest);
  cout<<"\nSum="<<sum;
  getch();
 }