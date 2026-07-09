#include <fstream>

int main()
{
	int t, a, b;

	std::ifstream in("euclid2.in");
	std::ofstream out("euclid2.out");

	in >> t;
	for (int i = 0; i < t; i++)
	{
		in >> a >> b;
		int r = 0;
		while (b)
		{
			r = a % b;
			a = b;
			b = r;
		}
		out << a << std::endl;
	}

	in.close();
	out.close();

	return 0;
}