#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{
	ifstream in("euclid2.in");
	int k, n, m, a;
	ofstream out("euclid2.out");
	for (in >> k; k > 0; k--)
	{
		in >> n >> m;
		while (m != 0) {
			a = m;
			m = n % m;
			n = a;
		}
		out << n << endl;
	}
	return 0;
}
