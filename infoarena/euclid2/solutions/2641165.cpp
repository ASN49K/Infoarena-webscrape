#include <iostream>
using namespace std;


int main()
{
	long long k, n, m, i;
	for (cin >> k; k > 0; k--) {
		cin >> n >> m;
		for (i = n; i > 0; i--) {
			if (n % i == 0 && m % i == 0) break;
		}
		cout << i << endl;
	}
}