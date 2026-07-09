#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;
int gcd(long long a,long long b)
{
	if(!b) return a;
	return gcd(b,a%b);
}
int main()
{
	long long n;
	long long a;
	long long b;
	cin >> n;
	while (n)
	{
		cin >> a >> b;
		cout << gcd(a,b) << endl;
		n--;
	}
	return 0;
}
