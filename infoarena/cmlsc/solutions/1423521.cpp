#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
typedef vector<vector<int> > IMATRIX;
typedef vector<vector<char> > CMATRIX;
int main() {
	fstream input("cmlsc.in", ios_base::in);
	fstream output("cmlsc.out", ios_base::out);
	int n, m;
	input >> n >> m;
	vector<int> a(n, 0), b(m, 0);
	for(int i = 0; i < n; i++)
		input >> a[i];
	for(int i = 0; i < m; i++) 
		input >> b[i];
	/* Matrix with longest common subsequences */
	IMATRIX L(n + 1, vector<int>(m + 1, 0));
	/* Matrix for reconstructing LCS */
	CMATRIX path(n + 1, vector<char>(m + 1, '0'));
	
	for(int row = 1; row <= n; row++) {
		for(int col = 1; col <= m; col++) {
			// If equal elements
			if (a[row - 1] == b[col - 1]) {
				L[row][col] = 1 + L[row - 1][col - 1];
				path[row][col] = '\\';
			}
			else 
				if(L[row - 1][col] > L[row][col - 1]) {
					L[row][col] = L[row - 1][col];
					path[row][col] = '^';
				}
				else {
					L[row][col] = L[row][col - 1];
					path[row][col] = '<';
				}	
		}
	}
	/* Reconstructing solution */
	int max = L[n][m];
	vector<int> solution(max, 0);
	int i = n, j = m;
	for(int k = max - 1; k >= 0; k--) {
		while(path[i][j] != '\\') {
			if(path[i][j] == '<')
				j--;
			else
				i--;
		}
		solution[k] = a[i - 1];
		i--;
		j--;
	}
	output << max << "\n";
	for(int i = 0; i < max; i++)
		output << solution[i] << " ";
	output.close();
	input.close();
}