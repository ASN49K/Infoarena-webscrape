#include<iostream.h>
#include<fstream.h>
int main ()
/* Algoritmul lui Euclid.
Cel mai mare divizor comun dintre doua numere naturale a si b
este cel mai mare numar natural pozitiv d care divide ambele numere. */
{unsigned long t, a, b;
int i;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>t;
for(i=1;i<=t;i++)
{f>>a>>b;
do
{if(a>b)
a=a-b;
else
b=b-a;}
while(a!=b);
g<<a<<"\n";}
f.close();
g.close();
return 0;}
