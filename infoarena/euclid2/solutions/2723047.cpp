#include <bits/stdc++.h>

using namespace std;

int euclid(int a, int b)
{
	while(b)
	{
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{
	int t, a, b;
	in >> t;

	while(t--)
	{
		in >> a >> b;
		out << euclid(a, b) << '\n';
	}

	return 0;
}
