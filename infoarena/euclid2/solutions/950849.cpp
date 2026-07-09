#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n, a, b, i, d;
int main()
{
	f>>n;
	for(i=1;i<=n;i++)
	{
		f>>a>>b;
		while(a!=b)
		{
			if(a>b)a-=b;
			else b-=a;
		}
		g<<a<<'\n';
	}
	f.close();
	g.close();
	return 0;
}
