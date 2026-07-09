#include <iostream>
using namespace std;

int main()
{
	int T, a, b;
	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		cin >> a >> b;
		while (a != b)
		{
			if (a > b) a -= b;
			else b -= a;
		}
		cout << a;
	}

	return 0;
}