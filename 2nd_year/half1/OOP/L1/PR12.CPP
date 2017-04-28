#include<iostream.h>
#include<conio.h>

struct list     //opredelenie peremennoi line strukturnogo tipa list
{               //odin iz elementov kotoroi tipa ukazatel
char b; 
int *k; 
} line;   	//na obiekt tipa int

void main()
{clrscr();
char cc = 'f',*p;    	//opredelnie simvolnoy peremennoy cc i neinicializirovannogo ukazatelya na obiekt tipa char
int *p1, *p2;	//opredelenie 2h neinicializirovannih ukazatelei p1 i p2 na obiekti tipa int
char *pc = &cc;    	//inicializirovannii ukazatel na obiekt tipa
char *ptr;
int *mas [10];       	//massiv iz 10 ukazatelei na obiekti tipa
int (*point) [10];   	//ukazatel na massiv iz 10 elementov tipa
struct list *n, *pr;	//dva ukazatelya n i pr na obiekti inenovannogo strukturnogo tipa list.

int **pp = &p1;   	//ukazatel pp - eto ukazatel na ukazatel. on iniciirovan znacheniem adresa
//ukazatelya p1 na obiekt celogo tipa.

int a=10,b=20;
int x[3][10];
ptr=pc;
//cout<<*ptr;
*ptr='+';
p1=&a;
//cout<<*p1;
p2=&b;
mas[0]=p1;
mas[1]=&b;
*mas[0]=15;
cout<<a<<endl;
*p2=25;
point=&x[0];//? - point=znachenie adresa nulevogo elementa (x[0][0])
point[0]=a;//? - 0vomu elementu massiva=znachenit a
*(point+1)=b; //? - x[0][1]=b
n=&line;     //? - ukazatelu n=adres strukturi line
pr=n;        //? - ukazateli n i pr ssilautsia na odnu peremennyu
(*n).b=*ptr; //? - elementu line.b='+'
(*pr).k=p1;       //? - line.k = a
getch();       
}

