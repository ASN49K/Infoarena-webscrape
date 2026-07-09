#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

void cmmdc(int x,int y)
{
	int z;
	while (y)
	{
		z=x%y;
		x=y;
		y=z;
	}
	out<<x<<"\n";
}

int main()
{
	int t,a,b;
	in>>t;
	while (t--)
	{
		in>>a>>b;
		cmmdc(a,b);
	}
	return 0;
}
