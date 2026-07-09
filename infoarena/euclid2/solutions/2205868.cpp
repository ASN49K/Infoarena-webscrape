#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");

	int x, y,n, min, max;
	fin >> n;
	for (int j = 1; j <= n; j++) {
		fin >> x >> y;
		if (y > x) {
			max = y;
			min= x;
		}
		else {
			max = x;
			min = y;
		}

		//cout << max;
		y = min;
		while (y != 0) {
			x = min;
			y = max % min;
			max = x;
			min = y;
		}
		fout << x << "\n";
	}

    return 0;
}

