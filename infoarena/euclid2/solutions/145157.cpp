#include<fstream.h>
int a, b;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{       f>>a>>b;
	while(a!=b)
	{	if(a>b)
		{	a=a-b;
		}
		else
		{	b=b-a;
		}
	}
	if(a==1)
	{	g<<0<<'\n';
	}
	else
	{	g<<a<<'\n';
	}
	g.close();
	return 0;
}