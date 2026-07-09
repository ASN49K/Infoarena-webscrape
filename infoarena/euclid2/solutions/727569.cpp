#include <fstream>
using namespace std;
int cmmdc(int a, int b)
{
	int c=a%b;
	while(c)
	{
		a=b;
		b=c;
		c=a%b;
	}
	return b;
}
int main()
{
	int n, i, a, b;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>n;
	for(i=1; i<=n; i++)
	{
		f>>a>>b;
		g<<cmmdc(a, b)<<"\n";
	}
}