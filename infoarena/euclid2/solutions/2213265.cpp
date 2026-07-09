#include <fstream>
#include <iostream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid(int a, int b)
{
	while (a != b)
	{
		if (a>b)
			a = a-b;
		else
			b=b-a;
	}
	return a;
}

int main()
{
	int nr_lines;
	int a, b;
	f>>nr_lines;
	while (nr_lines--)
	{
		f>>a>>b;
		g<<euclid(a, b)<<"\n";
	}
	return (0);
}
