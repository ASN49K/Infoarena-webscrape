#include<fstream>
using namespace std;

long cmmdc(long a, long b)
{
	while (a != b)
	{
		if (a == 0) return b;
		if (b == 0) return a;
		if (a > b)
		{
			a=a%b;
		}
		else b=b%a;
	}
	return a;
}

int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	long a,b,T,i;
	f>>T;
	for(i=1; i<=T; i++)
	{
		f>>a>>b;
		g<<cmmdc(a,b)<<endl;
	}
	f.close();
	g.close();
	return 0;
}