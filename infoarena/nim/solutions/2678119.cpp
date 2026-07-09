#include <fstream>

std::ifstream f("nim.in");
std::ofstream g("nim.out");


int main()
{
	int n, x, y;
	f >> n;
	while (n--)
	{
		f >> x;
		int a = 0;
		while (x--)
		{
			f >> y;
			a ^= y;
		}
		if (a == 0)
			g << "NU" << '\n';
		else g << "Da" << '\n';
	}
}

