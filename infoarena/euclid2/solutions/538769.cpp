#include"fstream.h"
long a,b,d,i,aux;
int T,j;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
 main(void)
{
	f>>T;
	for(j=1;j<=T;j++)
	{
		f>>a>>b;
		if(a>b)
		{
			aux=a;
			a=b;
			b=aux;
		}
		for(i=1;i<=a;i++)
			if(a%i==0 && b%i==0)
				d=i;
			if(d!=1)
				g<<d<<'\n';
			else
				return 0;
			
	}
	
f.close();
g.close();
}