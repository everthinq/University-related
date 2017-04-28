#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
int main()
{clrscr();


cout << setw(10) << "#";
char cc = 'f',*p;    	//opredelnie simvolnoy peremennoy cc i neinicializirovannogo ukazatelya na obiekt tipa char
//cout<<(int *)p<<endl;
*p='a';
//cout<<(int *)p;
int *p1, *p2;	//opredelenie 2h neinicializirovannih ukazatelei p1 i p2 na obiekti tipa int

char *pc = &cc;    	//inicializirovannii ukazatel na obiekt tipa char
//cout<<(int *)pc<<" "<<cc;
char *ptr = (NULL);	//nulevoi ukazatel na obiekt tipa char

/*cout<<(int*)ptr<<" "<<*ptr<<endl;
ptr=&cc;
cout<<(int*)ptr<<" "<<*ptr<<endl;
*ptr = (NULL);
cout<<(int*)ptr<<" "<<*ptr;
*/
int *mas [10];
cout<<sizeof(mas)<<endl;      	//massiv iz 10 ukazatelei na obiekti tipa int
int (*point) [10];   	//?ukazatel na massiv iz 10 elementov tipa int
cout<<sizeof(point)<<endl;

struct list *n, *pr;	//dva ukazatelya n i pr na obiekti inenovannogo strukturnogo tipa list.

struct list     //opredelenie peremennoi line strukturnogo tipa list
{               //odin iz elementov kotoroi tipa ukazatel
char b;
int *k; //
} line;   	//?na obiekt tipa int

int **pp = &p1;   	//ukazatel pp - eto ukazatel na ukazatel. on iniciirovan znacheniem adresa
cout<<pp<<endl;
cout<<&p1;
//ukazatelya p1 na obiekt celogo tipa.
//Eto dopustimo tak kak ukazatel - eto toje obiekt v pamyati
getch(); }