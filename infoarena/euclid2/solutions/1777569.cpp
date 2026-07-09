#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int a;
	int b;
	cin >> n;
	while (n)
	{
		cin >> a >> b;
		cout << __gcd(a,b) << endl;
		n--;
	}
	return 0;
}
