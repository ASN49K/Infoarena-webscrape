#include<iostream.h>
#include<fstream.h>
ifstream f("euclid.in");
ofstream g("euclid.out");
int main()
{
	int i,T,a,b,r;
	f>>T;
	for(i=1;i<=T;i++)
	{
		f>>a>>b;
		r=a%b;
		while(a%b)
		{
			r=a%b;
			a=b;
			b=r;
		}
		g<<b<<endl;
	}
	return 0;
}