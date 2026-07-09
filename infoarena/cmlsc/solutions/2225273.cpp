#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {

	ifstream inFile;
	inFile.open("cmlsc.in");
	ofstream outf("cmlsc.out");

	int nums, x, y;
	vector<int> v1, v2, sol;
	inFile >> x >> y;

	for (int i = 0; i < x; ++i) {
		inFile >> nums;
		v1.push_back(nums);
	}

	for (int i = 0; i < y; ++i) {
		inFile >> nums;
		v2.push_back(nums);
	}

	int aprs[x+1][y+1];

	for (int i = 0; i <= x; ++i) {
		for (int j = 0; j <= y; ++j) {
			if (i == 0 || j == 0)
				aprs[i][j] = 0;
			else {
				if (v1[i-1] == v2[j-1] )
					aprs[i][j] = aprs[i-1][j-1] + 1;
				else
					aprs[i][j] = max(aprs[i][j-1], aprs[i-1][j]);
			}
		}
	}
	int i = x, j = y;

	while (i >= 0 && j >= 0) {
		if (i > 1 && j > 1 && v1[i - 1] == v2[j - 1]) {
			sol.push_back(v1[i - 1]); 
			i--;
			j--;
		} else {
			if (i > 0 && j == 0)
				i--;
			else {
				if (j > 0 && i == 0)
					j--;
				else {
					if (aprs[i - 1][j] < aprs[i][j - 1])
						j--;
					else 
						i--;
				}
			}
		}
	}

	outf << sol.size() << "\n";
	for (int i = sol.size() - 1; i >= 0; --i) {
		outf << sol[i] << " ";
	}

	outf.close();
	inFile.close();
	return 0;
}