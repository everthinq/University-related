#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

//-------------Functions-----------------
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
	for(int i=0;i<dest.size;i++)
	{
		cout<<dest.setof[i]<<" ";
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

 
void print_w(set dest, int k, char *ch)
 {
  cout<<ch<<"["<<k<<"]= { ";
  for (int i=0; i<dest.size; i++)
  cout<<dest.setof[i]<<" ";
  cout<<"}\n";
 }
void create_ob (set obraz[8], int **matr, int count)
 {
  clear(obraz[0]);
  for (int i=0; i<count; i++)
    {
      clear(obraz[i+1]);
      for (int j=0; j<count; j++)
	 if (matr[i][j]==1) insert(obraz[i+1],j+1);
    }
 }
void create_pr (set praobraz[8], int **matr, int count)
 {
  clear(praobraz[0]);
  int j=0;
  for (int i=0; i<count; i++)
   {
    clear(praobraz[i+1]);
    for (j=0; j<count; j++)
      if (matr[j][i]==1) insert(praobraz[i+1], j+1);
   }
 }
void print_array(int **arr, int m)
 {
    for (int i=0; i<m; i++)
   {
    cout<<"            ";
    for(int j=0; j<m; j++)
      cout<<arr[i][j]<<" ";
    cout<<endl;
   }
 }
void turn_arr(int *arr, int count)
 {
   int *new_arr=new int [count];
   for (int i=0; i<=count; i++)
   new_arr[i]=arr[i];
   int j=0;

   for (i=0, j=count; i<=count; i++,j--)
   arr[i]=new_arr[j];

   delete [] new_arr;
 }
//----------------------MAIN-------------------
int main()
 {
  clrscr();
  //--------------ENTERIG VALUES---------------
  cout<<"Enter, please, the dimension of the matrix..[MxM]\n";
  int m=7;
  cin>>m;

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

  while (1)
   {
    cout<<"Enter, please, indexes of the elements\n";
    int index[2]={0,0};
    cout<<"Index[1] = "; cin>>index[0];
    cout<<"Index[2] = "; cin>>index[1];
    array[index[0]-1][index[1]-1]=1;
    cout<<"If you have finished entering, press Q...\nElse press any key...\n";
    int key=getch();
    if (key=='q') break;
  }
  clrscr();
  cout<<"Your matrix:\n";
  print_array(array,m);

//--  --  --  --  --  -- AFV --  --  --  --  --  --

/*Step 1*/
  int count=m;
  const int n=count;
  set obraz[8], praobraz[8];
  int k=1, xi=1, yi=7;

  create_ob(obraz,array,m);
  create_pr(praobraz,array,m);
  //--------
  cout<<"Enter, please starting and final vertexes...\n";
  cout<<"STARTING Xi = "; cin>>xi;
  cout<<"  FINAL  Yi = "; cin>>yi;
  cout<<"Need to find way from "<<xi<<" to "<<yi<<" vertex..."<<endl;
  //--------
  set w[8];
  set way;
  clear(way);

      for (i=0; i<8; i++)
      clear(w[i]);
  insert(w[0],xi);

/*Step 2*/       for (i=0;i<count;i++)
		   if (array[k-1][i]==1) insert(w[k],i+1);
	 while (1)
	     {
/*Step 3*/    if ( (w[k].size==0) || (k==n-1) && (!in(w[k],yi)) )
		    {
		     cout<<"Vetrex is not achieved...\n";
		     break;
		    }
/*Step 4*/    if (in(w[k],yi))
		    { /*Step 5*/
		     cout<<"The minimal way with length = "<<k<<" was found..."<<endl;
		     insert(way,yi);
		     for (k; k>=1; k--)
		      {
		       set temp;
		       intersection(temp,w[k-1],praobraz[way.setof[way.size-1]]);
		       if (temp.size>1) { int f=rand()%temp.size;
					  set temp2;
					  temp2.setof[0]=temp.setof[f];
					  temp2.size=1;
					  composition(way,way,temp2);
					}
		       else composition(way,way,temp);
		      }
		     turn_arr(way.setof,way.size-1);
		     print_w(way,k, "REZ-WAY");
		     break;
		    }
	      else { /*Step 6*/
		     set temp;
		     for (int q=0; q<=k; q++)
		     composition(temp,temp,w[q]);
		     //------------------------
		     for (q=0; q<w[k].size; q++)
		     {
		      composition(w[k+1],w[k+1],obraz[w[k].setof[q]]);
		     }
		     //print_w(temp,0,"TEMP");
		     substraction(w[k+1],w[k+1],temp);
		     //print_w(w[k+1],k+1,"W-res");
		     k++;
		   }
	     }
  getch();

  //----deleting array----
  for (i=0; i<m; i++)
   delete [] array[i];
  delete [] array;
  return 0;
 }