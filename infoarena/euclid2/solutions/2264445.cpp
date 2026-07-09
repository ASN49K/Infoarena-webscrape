#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int t, a, b, c;
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		cin >> a >> b;
		while (a != b)
		{
			if (a > b) a -= b;
			else b -= a;
			c = a;
		}
		cout << c;
	}

	system("pause");
	return 0;
}