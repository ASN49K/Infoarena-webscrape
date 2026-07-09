#include <fstream>

inline int Gcd (int a, int b)
{
	int r (a % b);
	while (r)
	{
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int main (void)
{
	int t, a, b;
	std::ifstream input("euclid2.in");
	std::ofstream output("euclid2.out");
	input >> t;
	while (t)
	{
		input >> a >> b;
		output << Gcd(a,b) << '\n';
		--t;
	}
	input.close();
	output.close();
	return 0;
}

