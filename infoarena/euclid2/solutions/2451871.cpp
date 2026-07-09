#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

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
    f>>T;
    for(;T>0;T--)
	{
		f>>x>>y;
		g<<cmmdc(x,y)<<endl;
	}
    return 0;
}
