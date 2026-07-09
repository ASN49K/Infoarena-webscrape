#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define ll long long 
#define ull unsigned long long 
#define nmax 20006
#define MOD 9901 
#define INF 2123456789
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