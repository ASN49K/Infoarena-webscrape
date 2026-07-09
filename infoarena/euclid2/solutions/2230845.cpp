#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
#define cout g

void solve(int a, int b)
{

	while (a != b && a != 0 && b != 0)
	{
		if (a > b)
		{
			a = a % b;
		}
		else
			if (b > a)
			{
				b = b % a;
			}
	}
	cout << max(a, b) << '\n';
}

int main()
{
	int t;
	f >> t;
	while (t) {
		t--;
		int a, b;
		f >> a >> b;
		solve(a, b);
	}
	
	return 0;
}

