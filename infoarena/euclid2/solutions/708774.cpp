#include <iostream>
#include <fstream>
#define NL '\n'

using namespace std;

unsigned T, i=0;
long a, b, r;

int main()
{
	ifstream cin("euclid2.in");
	ofstream cout("euclid2.out");
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
