#include <bits/stdc++.h>

using namespace std;

ifstream fi  ("euclid2.in");
ofstream fo ("euclid2.out");

long long n,a,b;

int main ()

{
	fi >> n;
	for (int i = 1; i <= n; ++i)
	{
		fi >> a >> b;
		fo <<__gcd(a,b) << '\n';
	}
	return 0;
}
