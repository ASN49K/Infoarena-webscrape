
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


int main() {
	ifstream fin("clmsc.in");
	ofstream fout("clmsc.out");

	vector<int> v1, v2;
	int M, N;

	fin >> N >> M;
	for (int i = 0; i < N; i++) {
		int aux;
		fin >> aux;
		v1.push_back(aux);
	}
	for (int i = 0; i < M; i++) {
		int aux;
		fin >> aux;
		v2.push_back(aux);
	}

	vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));



	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = ((v1[i-1] == v2[j-1]) ? dp[i-1][j-1] + 1 : max(dp[i-1][j], dp[i][j-1]));
		}
	}
	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	 */	
	cout << endl;
	//cout << dp[N][M] << endl;
	fout << dp[N][M] << endl;
	// reconsituire
	int i = N, j = M;
	while(i > 0 && j > 0) {
		if (v1[i - 1] == v2[j - 1]) { // dp[i][j] 
			fout << v1[i - 1] << " ";	
			i--; j--;
		} else if (dp[i - 1][j] > dp[i][j - 1]) {
			i--;
		} else {
			j--;
		}
			
	}

	return 0;
}
