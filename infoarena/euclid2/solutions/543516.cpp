#include<fstream>
using namespace std;

int cmmdc(int a, int b)
{
	int c;
	while(b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main()
{
	int t, a, b, i;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f >> t;
	for(i = 1; i <= t; ++i)
	{
		f >> a >> b;
		g << cmmdc(a, b) << '\n';
	}
	g.close();
	return 0;
}