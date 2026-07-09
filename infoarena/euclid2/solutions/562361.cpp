#include<fstream.h>
int main()
{
	int n,a,b,i,r;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>n;
	for (i=1;i<=n;i++)
	{
		f>>a>>b;
		r=a%b;
		while (r)
		{
			a=b;
			b=r;
			r=a%b;
		}
		g<<a<<'\n';
	}
	return 0;
}
