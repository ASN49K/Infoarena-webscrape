#include"fstream.h"
#define minim(a,b) ((a>b)? b:a)
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
		if(a!=0 && b!=0)
		{
		for(i=1;i<=minim(a,b);i++)
			if(a%i==0 && b%i==0)
				d=i;
			if(d!=1)
				g<<d<<'\n';
		}
				
			
	}
return 0;	
f.close();
g.close();
}