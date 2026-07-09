#include<fstream.h>
#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
unsigned long a,b,T,i;
ifstream f("euclid2.in");
f>>T;
ofstream g("euclid2.out");
for(i=1;i<=T;i++)
{f>>a>>b;
while(a!=b)if(a>b)a=a-b;else b=b-a;

g<<a<<endl;
}
g.close();
f.close();
}