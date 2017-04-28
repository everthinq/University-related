#include<iostream.h>
#include<conio.h>

int lc(char ch)
{
return (ch>='a' && ch<='z');
}

void ctup (char & ch)
{
//ch+='A'-'a';
ch-=32;
}

void ctup (char *ph)
{
int k;

while (*ph !='\0')
 {
  if (lc (*ph))
   ctup (*ph);
    ph++;
  }
}

int main()
{
clrscr();
char k[]="dksjgkldfjglkjsdgjkSDFJLKSJDKLFSsdfds";
cout<<k<<endl;
ctup(k);
cout<<k;
getch();
return 0;
}