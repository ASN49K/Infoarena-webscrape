#include <iostream>
using namespace std;
#include <fstream>
using namespace std;

int gcd(int a, int b)
{
	int c = b;
	while(a % b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return c;
}

int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int n, a, b;

	f >> n;
	for(; n > 0; n--)
	{
		f >> a >> b;
		g << gcd (a, b) << endl;
	}
}