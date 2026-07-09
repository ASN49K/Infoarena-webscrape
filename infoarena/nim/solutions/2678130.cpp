#include <fstream>

std::ifstream cin("nim.in");
std::ofstream cout("nim.out");


int main()
{
	int n, x, y;
	cin >> n;
	while (n--)
	{
		cin >> x;
		int a = 0;
		while (x--)
		{
			cin >> y;
			a ^= y;
		}
		if (a == 0)
			cout << "NU" << '\n';
		else cout << "DA" << '\n';
	}
}

