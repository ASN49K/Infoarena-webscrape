#include<bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n, a, b, i;
int gcd(int a, int b)
{
	if (!b) return a;
	return gcd( b, a % b );
}
int main()
{
	fin >> n;
	for (i = 1; i <= n; i++) {
		fin >> a >> b;
		fout << gcd(a, b) << endl;
	}
	return 0;
}
