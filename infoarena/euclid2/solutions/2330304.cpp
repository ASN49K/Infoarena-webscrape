#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int a, int b)
{
	if(!a)return b;
	if(!b)return a;
	return  cmmdc(b, a % b);
}
int n, a, b;

int main()
{
	fin >> n;
	for(int i = 1; i <= n; ++i)
	{
		fin >> a >> b;
		if(a < b)swap(a, b);
		fout << cmmdc(a, b) << '\n';
	}
	return 0;
}
