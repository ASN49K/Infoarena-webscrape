#include <bits/stdc++.h>
using namespace std;
long long a,b,t;

long long gcd(long long c,long long d)
{
	if (d==0) return c;
	else return gcd(d,c%d);
}

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	cin >> t ;
	while (t--)
	{
	cin >> a >> b ;
	cout << gcd(a,b) << "\n";	
	}
    return 0;
}
