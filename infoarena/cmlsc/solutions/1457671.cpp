#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

///// DESCRIPTION
// THIS PROGRAM EMPLOYS A RECURSIVE FORMULA
// TO DETERMINE THE LONGEST COMMON SUBSEQUENCE
// OF TWO STRINGS:
// https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
// LCS(Xi, Yj) = 1. empty string                      if i = 0 or j = 0/
//				   2. LCS(Xi-1, Yj-1) ^ Xi              if Xi = Yj
//				   3. max(LCS(Xi-1, Yj), LCS(Xi, Yj-1)) if Xi != Yj
// NOTE: Xi is the prefix of length i of string X
/////

int main(int argc, char **argv)
{
	// INPUT
	ifstream indata("cmlsc.in");
	
	int m, n;
	indata >> m >> n;
	int cmlsc_mat[m + 2][n + 2];
	
	cmlsc_mat[0][0] = cmlsc_mat[1][1] = 0;
	for (int i = 2; i < m + 2; i++) {
		// read the data of string 1
		indata >> cmlsc_mat[i][0];
		// initialize the 0 length suffix with 0
		cmlsc_mat[i][1] = 0;
	}
	for (int i = 2; i < n + 2; i++) {
		// read the data of string 2
		indata >> cmlsc_mat[0][i];
		// initialize the 0 length suffix with 0
		cmlsc_mat[1][i] = 0;
	}
	indata.close();
	
	// DETERMINE THE LONGEST SUBSEQUENCE
	
	// create the length matrix
	// NOTE: position 0 is occupied by the strings
	// and position 1 is occupied by the empty prefix
	for (int i = 2; i < m + 2; i++) {
		for (int j = 2; j < n + 2; j++) {
			// this determines the length of the maximal
			// common subsequence at each point (according
			// to the formula in the description)
			if(cmlsc_mat[i][0] == cmlsc_mat[0][j]) {
				cmlsc_mat[i][j] = cmlsc_mat[i-1][j-1] + 1;
			} else {
				cmlsc_mat[i][j] = max(cmlsc_mat[i][j-1], cmlsc_mat[i-1][j]);
			}
		}
	}
	
	// read the subsequence from the matrix
	// DESCRIPTION: we start with the bottom right corner of the matrix
	// and whenever the char on the current position coincides, we move vertically (up-left)
	// and otherwise we move either up or left, depending on which option promises
	// the longer subsequence
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
	
	// OUTPUT
	ofstream outdata("cmlsc.out");
	outdata << subsequence.size() << endl;
	for (int i = subsequence.size() - 1; i >= 0; i--) {
		outdata << subsequence[i] << " ";
	}
	outdata.close();
	return 0;
}
