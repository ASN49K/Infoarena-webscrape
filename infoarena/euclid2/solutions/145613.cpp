#include<fstream.h>
int euclid(int a, int b)
	{
	int r;
	r=a%b;
	while(r)
		{
		a=b;b=r;r=a%b;
		}
	return b;
	}
int main()
	{
	int a,b;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>a>>b;
	g<<euclid(a,b);
	f.close();
	g.close();
	return 0;
	}
