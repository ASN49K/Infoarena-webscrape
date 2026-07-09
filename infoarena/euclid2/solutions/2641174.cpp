#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{
	int k, n, m;
	ofstream out("euclid2.out");
	for (cin >> k; k > 0; k--)
	{
		cin >> n >> m;
		while (m != 0) {
			int a = m;
			m = n % m;
			n = a;
		}
		out << n << endl;
	}
	return 0;
}
