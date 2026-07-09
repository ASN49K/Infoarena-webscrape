#include <fstream>

int main()
{
	int t, a, b;

	std::ifstream in("euclid2.in");
	std::ofstream out("euclid2.out");

	auto gcd = [](int a, int b) 
	{
		int r = 0;
		while (b)
		{
			r = a % b;
			a = b;
			b = r;
		}
		return a;
	};

	in >> t;
	for (int i = 0; i < t; i++)
	{
		in >> a >> b;
		out << gcd(a, b) << std::endl;
	}

	return 0;
}