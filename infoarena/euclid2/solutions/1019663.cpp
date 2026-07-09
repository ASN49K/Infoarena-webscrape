#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,a,b,i;
int cmmdc(int x, int y)
{
	int r;
	while(y>0)
	{
		r=x%y;
		x=y;
		y=r;
	}
	return x;
}
int main()
{
	f>>t;
	for(i=1; i<=t; i++)
	{
		f>>a>>b;
		g<<cmmdc(a,b)<<"\n";
	}
	g.close();
	return 0;
}
