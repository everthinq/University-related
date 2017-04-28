#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<iomanip.h>
#include<math.h>



int fact (int n)
//factorial
{
 if (n < 0) return 0;
 if (n == 0) return 1;
  else return n * fact (n - 1);
}

int Razm (int n, int k)
//razmesheniya bez povtorenii
{
 int A = n;
 for (int i = 1; i < k; i++)
 {
  A *= n - i;
 }
 return A;
}
long int R0 = 1441440;
long Pass (int n, int k)
//razmesheniya bez povtorenii
{
 long A = n;
 for (int i = 1; i < k; i++)
  A *= n;
 return A;
}


long Combination (int n, int k)
//sochitaniya bez povtorenii
{
 long A = n;
 for (int i = 1; i < k; i++)
 {
  A *= (n - i) / (i + 1);
 }
 return A;
}

long CombinationNotUnic (int n, int k)
//sochitaniya s povtoreniyami
{
 long A = 1;
 long m = 1;
 for (int i = 0; i < k; i++)
 {
  A *= (n + k - i - 1);
  m *= i + 1;
 }
 return A / m;
}

int main()
{
 clrscr();
 while (1)
 {
  int l = 0;
  cout << endl << "1 - TASK 4";  //1   
  cout << endl << "2 - TASK 10"; //9 
  cout << endl << "3 - TASK 16"; //15 
  cout << endl << "4 - TASK 22"; //23  
  cout << endl << "Enter number: ";
  cin >> l;
  switch(l)
  {
  case 1: { clrscr(); //480, 437
	    unsigned long int n = 20, k = 24, R, R2;
            R = n * k;
	    R2 = (n - 1) * (k - 1);
	    cout << "Result1: " << R << endl;
            cout << "Result2: " << R2;
	    break;
	  }
  case 2: { clrscr();
	    unsigned long int n = 20, k = 6, nn = 14, R1, R2;
	    R1 = Combination(n, k); R2 = Combination(nn, k);
            R1*=R2;
            cout << "Result: " << R0;
	    break;
	  }
  case 3: { clrscr();
	    int n = 5, k = 3, m = 4, R, R1, R2, R3;
	    R = Razm(n,k); R1 = Razm(n,m);
            R2 = Razm(n,n); R3 = R+R1+R2;
	    cout << "Result: " << R3;
	    break;
	  }
  case 4: { clrscr();
	    int n = 6, k = 4, R;
	    R = Razm(n,k); 
            cout << "Result: " << R;
	    break;
	  }
  default: exit(1);
  }
 }
 getch();
 return 0;
}