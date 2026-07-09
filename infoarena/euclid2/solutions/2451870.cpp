#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

long T,x,y;

long cmmdc(int a, int b)
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
		x=cmmdc(x,y);
		g<<x<<endl;
	}
    return 0;
}
