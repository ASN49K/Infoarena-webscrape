#include <bits/stdc++.h>
using namespace std;

ifstream file_in("euclid2.in");
ofstream file_out("euclid2.out");

int GCD(int a, int b)
{
	int r;
	while (b)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	int T, a, b; file_in >> T;
	while (T--)
	{
		file_in >> a >> b;
		file_out << GCD(a, b) << '\n';
	}
	return 0;
}