#include <bits/stdc++.h>
using namespace std;
long long t,n,m;
long long gcd(long long a,long long b)
{
	if (b==0)return a;
	else return gcd(b,a%b);
}

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{
	in >> t ;
	while (t--)
	{
		in >> n >> m ;
		out << gcd(n,m)<<"\n";
	}
    return 0;
}
