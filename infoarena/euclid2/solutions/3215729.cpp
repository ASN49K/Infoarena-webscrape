#include <bits/stdc++.h>
#include <unordered_map>
#define nmax 100006
#define MOD 1999999973
#define INF 2012345678
#define ll long long
using namespace std;
//#define fin cin
//#define fout cout

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n;

int Euclid(int a, int b)
{
	int r;
	while (b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	int x, y;
	fin >> n;
	while (n--)
	{
		fin >> x >> y;
		fout << Euclid(x, y) << "\n";
	}
	fin.close();
	fout.close();
	return 0;
}