#include <vector>
#include <fstream>

std::ifstream infile("euclid2.in");
std::ofstream outfile("euclid2.out");

int gcd(int a, int b) {
	int c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

void solve()
{
	int a, b;
	infile >> a >> b;

	outfile << gcd(a, b) << std::endl;
}

int main()
{
	int t;
	infile >> t;

	while (t--)
		solve();
}