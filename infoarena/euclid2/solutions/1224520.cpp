#include <fstream>
#include <iostream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int	euclid(int a, int b)
{
	int aux;

	while (b != 0)
	{
		aux = a % b;
		a = b;
		b = aux;
	}
	return (a);
}

int	main(void)
{
	int i;
	int n;
	int a;
	int b;

	i = 1;
	f >> n;
	while (i <= n)
	{
		f >> a >> b;
		g << euclid(a, b) << '\n';
		i++;
	}
	return (0);
}
