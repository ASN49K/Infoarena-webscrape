#include<fstream.h>

int euclid (int a, int b )
{
	if (a==0)
		return b;
	else
		return euclid(b%a,a);
}

int main()
{
	int a,b,t;
	ifstream f("euclid2.in");
	f>>t;
	ofstream g("euclid2.out");
	while (t)
	{
		f>>a>>b;
		while(a!=0 && b!=0)
			if (a>b)
				a%=b;
			else
				b%=a;
		g<<a+b<<'\n';
		--t;
	}
	f.close();
	g.close();
	return 0;
}
		