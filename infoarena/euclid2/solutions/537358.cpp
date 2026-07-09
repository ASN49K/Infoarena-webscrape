#include <fstream.h>
ifstream f("fisier.in");
ofstream g("fisier.out");
int n,a,b;
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
	for(int i=1;i<=n;i++)
	{
		f>>a>>b;
		g<<euclid(a,b)<<"\n";
	}
	f.close();
	g.close();
	return 0;
}