#include <iostream>
using namespace std;
#include <fstream>
using namespace std;

int gcd(int a, int b)
{
	if(!b)
		return a;
	else
		return gcd(b, a%b);
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
		g << gcd (a, b) << "\n";
	}
}