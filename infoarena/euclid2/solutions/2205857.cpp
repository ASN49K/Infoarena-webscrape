#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");

	int x, y,n, min, maxc;
	fin >> n;
	for (int j = 1; j <= n; j++) {
		fin >> x >> y;
		if (y > x) {
			min= x;
		}
		else {
			min = y;
		}
		//cout << max;

		for (int i = 1; i <= min; i = i + 1) {
			if (x % i == 0) {
				if (y % i == 0) {
					maxc = i;
				}

			}
		}
		fout << "" << maxc << endl;
	}

    return 0;
}

