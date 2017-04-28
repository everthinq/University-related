#include<iostream.h>
#include<conio.h>
int lc(char ch)
{
return (ch>='a' && ch<='z');
}
void ctup (char & ch)
{
ch+='A'-'a';
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
char *k;
int n;
cout<<"Vvedite razmer"<<endl;
cin>>n;
k=new char[n];
cout<<"Vvedite tekst"<<endl;
cin>>k;
ctup(k);
for(int i=0;i<n;i++){
cout<<k[i];}
delete[] k;
getch();
return 0;
}