#include <iostream>
#include <fstream>

std :: ifstream f("../euclid2.in");
std :: ofstream g("../euclid2.out");


int gcd(int a, int b)
{
	int r;
	r = a % b;
	while(r)
	{
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}


int main()
{
	int n;
	f >> n;
	while(n)
	{
		int a, b;
		f >> a >> b;
		g << gcd(a, b) << '\n';
		n--;
	}
	f.close();
	g.close();
	return 0;
}
