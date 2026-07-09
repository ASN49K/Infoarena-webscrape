#include"fstream.h"
#define minim(a,b) ((a>b)? b:a)
long a,b,d=0,i;
int T;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
 int main(void)
{
	f>>T;
	for(;T;T--)
	{
		f>>a>>b;
		if(a!=0 && b!=0)
		for(i=1;i<=minim(a,b);i++)
			if(a%i==0 && b%i==0)
				d=i;
				g<<d<<'\n';
				
			
	}
return 0;	
f.close();
g.close();
}