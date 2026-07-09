#include<fstream>
#include<iostream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
	int a, b, t, r;
	f >> t;
	for (int i = 0; i < t; ++i)
	{
		f >> a >> b;
		r = a % b;
		while (r != 0)
		{
			a = b;
			b = r;
			r = a % b;
		}
		g << b << '\n';
	}
}