
#include <iostream>
#include <fstream>

using namespace std;

int sol(int &a, int &b)
{
	do
	{
		if (a > b)
		{
			if (a % b == 0)
				return b;
			a %= b;
		}
		else
		{
			if (b % a == 0)
				return b;
			b %= a;
		}
	} while (a != b);
	return a;
}
int main()
{
	ifstream be("euclid2.in");
	ofstream ki("euclid2.out");
	int n;
	int a, b;
	be >> n;

	for (int i = 0; i < n; i++)
	{
		be >> a >> b;
		if (a == b)
			ki << a;
		else
			ki << sol(a, b)<<endl;
	}

	return 0;
}
