#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
	vector<int> W, P;
	ifstream infile; 
   	infile.open("cmlsc.in");
	ofstream outfile;
	outfile.open("cmlsc.out");

	int M, N, val;
	vector<int> A, B, sol;
	infile >> M >> N;
     
	for (int i = 0; i < M; i ++) {
		infile >> val;
		A.push_back(val);
	}

	for (int i = 0; i < N; i ++) {
		infile >> val;
		B.push_back(val);
	}

	int matr[M][N], a = 0, b = 0;
	for (int i = 0; i < M; i ++) {
		if (A[i] == B[0])
			a = 1;
		matr[i][0] = a;
	}

	for (int i = 0; i < N; i ++) {
		if (A[0] == B[i])
			b = 1;
		matr[0][i] = b;
	}
	
	for (int i = 1; i < M; i ++)
		for (int j = 1; j < N; j ++) {
			if (A[i] == B[j])
				matr[i][j] = matr[i - 1][j - 1] + 1;
			else matr[i][j] = max(matr[i - 1][j], matr[i][j - 1]);
		}
	
	int maxi = 0;
	pair<int,int> p;

	for (int i = 1; i < M; i ++)
		for (int j = 1; j < N; j ++) 
			if (matr[i][j] > maxi) {
				maxi = matr[i][j];
				p = make_pair(i, j);
			}
	int i = p.first, j = p.second;

	while (i >= 1 && j >= 1) {
		if (matr[i][j] == matr[i - 1][j - 1] + 1 && A[i] == B[j]) {
			sol.push_back(A[i]);
			i --;
			j --;
		}
		else {
			if (max(matr[i - 1][j], matr[i][j - 1]) == matr[i - 1][j])
				i --;
			else j --;
		}
	}
	while (matr[i][j] == 1)
		if (A[i] == B[j]) {
			sol.push_back(A[i]);
			break;
		}
		else if (i > 0)
			i --;
		else j--;

	outfile << sol.size() << endl;
	for (int k = sol.size() - 1; k >= 0; k --)
		outfile << sol[k] << " ";

	return 0;
}
