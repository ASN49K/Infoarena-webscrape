#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

main()
{
	int t;
	fin >> t;
	
	for(; t; --t)
	{
		int x, y;
		fin >> x >> y;
		
		fout << __gcd(x, y) << '\n';
	}
}