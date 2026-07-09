#include <bits/stdc++.h>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int gcd(int a, int b)
{
	if (b)
		return gcd(b, a % b);
	else 
		return a;
}

int main()
{
    int a, b, t;

    cin >> t;
    while (t--)
    {
    	cin >> a >> b;
    	cout << gcd(a, b) << '\n';
    }

	return 0;
}