#include <fstream>
#include <cstdio>

using namespace std;

int T,x,y;

int cmmdc(int a, int b)
{
	if(!b)
		return a;
	else
		cmmdc(b,a%b);
}

int main()
{

	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
    f>>T;
    for(;T>0;T--)
	{
		f>>x>>y;
		g<<cmmdc(x,y)<<'\n';
	}
	f.close();
	g.close();
    return 0;
}
