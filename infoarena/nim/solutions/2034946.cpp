#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ifstream fin ("nim.in");
	ofstream fout ("nim.out");
	int t;
	fin >> t;
	while (t--)
	{
		int xr = 0;
		int n;
		fin >> n;
		for (int i = 1; i<=n; ++i)
		{
			int x;
			fin >> x;
			xr ^= x;
		}
		if (xr) fout << "DA";
		else fout << "NU";
	}
	return 0;
}