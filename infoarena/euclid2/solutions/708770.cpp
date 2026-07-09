#include <iostream>
#define NL '\n'

using namespace std;

unsigned T, i=0;
long a, b, r;

int main()
{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	cin >> T;
	for(i; i<T; i++)
	{
		cin >> a;
		cin >> b;
		while(b)
		{
			r = a % b;
			a = b;
			b = r;
		}
		cout << a << NL;
	}
	return 0;
}
