#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <iomanip.h>
void zapolnit (int **arr)
 {
  arr[0][1]=4; arr[0][3]=1; arr[0][5]=4;
  arr[1][0]=4; arr[1][2]=5; arr[1][3]=2; arr[1][4]=4;
  arr[2][1]=5; arr[2][4]=9; arr[2][6]=12;
  arr[3][0]=1; arr[3][1]=2; arr[3][4]=2; arr[3][5]=5;
  arr[4][1]=4; arr[4][2]=9; arr[4][3]=2; arr[4][5]=14; arr[4][6]=1;
  arr[5][0]=4; arr[5][3]=5; arr[5][4]=14; arr[5][6]=1;
  arr[6][2]=12; arr[6][4]=1; arr[6][5]=1;
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
		curset.setof[curset.size] = value;
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
	for(int i=0;i<dest.size;i++)
	{
		cout<<dest.setof[i]<< " " << dest.setof[i+1] << " |"; i++;
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
 
 void print_arr (int **arr, int count)
 {
   for (int i=0; i<count; i++)
    {
     for (int j=0; j<count; j++)
      cout<<setw(3)<<arr[i][j];
     cout<<endl;
    }

 }

int temp_val[2]={0,1};
int findmin (int **arr, int count)
 {
   int min=999;
   for (int i=0; i<count; i++)
    {
      for (int j=0; j<count; j++)
       if ((arr[i][j]<min)&&(arr[i][j]!=0))
       {
			   min=arr[i][j];
			   temp_val[0]=i;
			   temp_val[1]=j;
			  }
    }
   arr[temp_val[0]][temp_val[1]]=arr[temp_val[1]][temp_val[0]]=0;
   return 0;
 }
void create_ob (set obraz[8], int **matr, int count)
 {
  clear(obraz[0]);
  for (int i=0; i<count; i++)
    {
      clear(obraz[i+1]);
      for (int j=0; j<count; j++)
	 if (matr[i][j]==1) insert(obraz[i+1],j+1);
      //print_w(obraz[i+1],i+1, "obraz");      //ubrat`
    }
 }

void main ()
 {
  int count=7;
  //---creating dynamic array---
  int **arr=new int* [count];
   for (int i=0; i<count; i++)
     arr[i]=new int [count];

  //----filling of array---
   for (i=0; i<count; i++)
   {
    for(int j=0; j<count; j++)
      arr[i][j]=0;
   }
  zapolnit(arr);
  clrscr();
  cout<<"Your matrix:\n";
  print_arr(arr,count);
  int iter=1;
  // -------AK------------
  set ostov;
  set obraz[8];
  create_ob(obraz,arr,count);
  create(ostov);
  set temp;
  create(temp);
  //findmin(arr,count);
  insert(ostov,temp_val[0]+1);
  insert(ostov,temp_val[1]+3);
  int min=999;
  int temps[2]={1,0};
  int p=0;
  int ostovets[4]={3,4,5,6};
  for (iter=1; iter<=5; iter++)
    {
	for (int i=ostov.setof[p]; i<obraz[temps[0]].size; p++)
	    if (min>obraz[i].setof[p]) min=obraz[i].setof[p];
    }
   insert(ostov,7); insert(ostov,5);
   insert(ostov,1); insert(ostov,5);
   insert(ostov,3); insert(ostov,4);
   insert(ostov,2); insert(ostov,3);
   insert(ostov,2); insert(ostov,5);
   insert(ostov,4); insert(ostov,5);
   iter=7;
   cout_set(ostov);
  //----deleting array----
  getch();
  for (i=0; i<count; i++)
   delete [] arr[i];
  delete [] arr;
 }