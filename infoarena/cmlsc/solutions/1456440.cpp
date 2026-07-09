#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
	ifstream indata("cmlsc.in");
	
	int m, n;
	indata >> m >> n;
	int cmlsc_mat[m + 2][n + 2];
	
	// read the data and initialize the
	// 0 suffix as empty
	cmlsc_mat[0][0] = cmlsc_mat[1][1] = 0;
	for (int i = 2; i < m + 2; i++) {
		indata >> cmlsc_mat[i][0];
		cmlsc_mat[i][1] = 0;
	}
	for (int i = 2; i < n + 2; i++) {
		indata >> cmlsc_mat[0][i];
		cmlsc_mat[1][i] = 0;
	}
	indata.close();
	
	// create the length matrix
	for (int i = 2; i < m + 2; i++) {
		for (int j = 2; j < n + 2; j++) {
			// this determines the length of the maximal
			// common subsequence at each point
			if(cmlsc_mat[i][0] == cmlsc_mat[0][j]) {
				cmlsc_mat[i][j] = cmlsc_mat[i-1][j-1] + 1;
			} else {
				cmlsc_mat[i][j] = max(cmlsc_mat[i][j-1], cmlsc_mat[i-1][j]);
			}
		}
	}
	
	// read the subsequence from the matrix
	vector<int> subsequence;
	for (int i = m + 1, j = n + 1; i > 1;) {
		if (cmlsc_mat[i][0] == cmlsc_mat[0][j]) {
			subsequence.push_back(cmlsc_mat[i][0]);
			i--; j--;
		} else if (cmlsc_mat[i-1][j] < cmlsc_mat[i][j-1]) {
			j--;
		} else {
			i--;
		}
	}
	
	// output the data
	ofstream outdata("cmlsc.out");
	outdata << subsequence.size() << endl;
	for (int i = subsequence.size() - 1; i >= 0; i--) {
		outdata << subsequence[i] << " ";
	}
	outdata.close();
	return 0;
}
