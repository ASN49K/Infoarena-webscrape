#include<conio.h>
#include<iostream.h>
void main()
{ int a,b,r;
 clrscr();
cin>>a>>b;
while(a%b) { r=a%b; a=b; b=r;} cout<<b; getch();}