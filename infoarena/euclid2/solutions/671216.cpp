#include <stdio.h>

#include <fstream>

int euclid(int a, int b)
{
	int n1 = (a > b) ? a : b;
	int n2 = (a > b) ? b : a;

	if (n2 == 0)
		return n1;

	return euclid(n2, n1 % n2);
}

int main()
{
	int n, a, b;

	std::ifstream f("euclid2.in");
	std::ofstream g("euclid2.out");

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> a;
		f >> b;
		g << euclid(a, b) << "\n";
	}

	return 0;
}
