#include<fstream>
using namespace std;

int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	long x,y,n,i,r;
	f>>n;
	for(i=1; i<=n; i++)
	{
		f>>x>>y;
		r=x%y;
		while(r)
		{
			x=y;
			y=r;
			r=x%y;
		}
		g<<y<<endl;
	}
	f.close();
	g.close();
}