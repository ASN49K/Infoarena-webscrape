#include <vector>
#include <fstream>

std::ifstream infile("euclid2.in");
std::ofstream outfile("euclid2.out");

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

void solve()
{
	int a, b;
	infile >> a >> b;

	for (int i = max(a, b) / 2; i > 0; --i)
	{
		if (a % i == 0 && b % i == 0)
		{
			outfile << i << "\n";
			break;
		}
	}
}

int main()
{
	int t;
	infile >> t;

	while (t--)
		solve();
}