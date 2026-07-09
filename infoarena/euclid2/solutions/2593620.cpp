#include <iostream>
#include <fstream>

using namespace std;

int	euclid(int a, int b)
{
	int	c;

	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int	main()
{
	int 	n;
	int 	a, b;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");

	f >> n;
	while (n)
	{
		f >> a >> b;
		g << euclid(a, b) << '\n';
		n--;
	}
	return 0;
}
