#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
	long long n;
	long long a;
	long long b;
	cin >> n;
	while (n)
	{
		cin >> a >> b;
		cout << __gcd(a,b) << endl;
		n--;
	}
	return 0;
}
