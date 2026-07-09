#include"fstream.h"
#define minim(a,b) ((a>b)? b:a)
long a,b;
int T;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
	long i,d;
		f>>T;
	for(;T;T--)
	{
		f>>a>>b;
		for(i=1;i<minim(a,b);i++)
			if(a%i==0 && b%i==0)
				d=i;
		g<<d<<'\n';
	}		
f.close();
g.close();
return 0;
}