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
		if (a<b)
			g<<euclid(a,b);
		else
			g<<euclid(b,a);
		g<<'\n';
		--t;
	}
	f.close();
	g.close();
	return 0;
}
		