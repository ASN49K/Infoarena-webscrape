#include"fstream.h"
#define minim(a,b) ((a>b)? b:a)
long a,b,r,i;
int T;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
 int main(void)
{
	f>>T;
	for(i=1;i<=T;i++)
	{
		f>>a>>b;
		do
		{
			r=a%b;
			a=b;
			b=r;
		}while(r!=0);
		g<<a<<"\n";
				
			
	}
return 0;	
f.close();
g.close();
}