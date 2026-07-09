#include <iostream>
using namespace std;


int main()
{
	int k, n, m, i;
	for (cin >> k; k > 0; k--) {
		cin >> n >> m;
		if (n < m) i = n;
		else i = m;
		for (; i > 0; i--) {
			if (n % i == 0 && m % i == 0) break;
		}
		cout << i << endl;
	}
}