#include<fstream.h>
ifstream f("euclid.in");
ofstream g("euclid.out");
int a,b,c,n,i;
int euclid(int a,int b)
{
	int c;
	while(b)
	{
		c=a%b;
		a=b;
		b=c;
	
	}
 return a;
}
int main()
{
 f>>n;
 for(i=1;i<=n;i++)
	{ f>>a>>b; g<<euclid(a,b)<<'\n'; }

 return 0;
}