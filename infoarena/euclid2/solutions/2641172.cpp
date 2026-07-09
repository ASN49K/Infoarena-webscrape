#include <iostream>
using namespace std;




int main(void)
{
	int k, n, m;
	for (cin >> k; k > 0; k--)
	{
		cin >> n >> m;
		while (m != 0) {
			int a = m;
			m = n % m;
			n = a;
		}
		cout << n << endl;
	}
	return 0;
}