#include<iostream.h>
#include<fstream.h>
unsigned long x,a,b,i,d,div;
int main ()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>x;
for (i=0;i<x;i++)
	{g>>a>>b;
	 d=2;div=1;
	 while (d<a && d<b)
		{if (a%d==0 && b%d==0) {div*=d;a/=div;b/=div;}
		 d++;}
	 g<<div<<'\n';
	}
return 0;
}