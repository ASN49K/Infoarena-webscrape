
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


int main() {
	ifstream fin("clmsc.in");
	ofstream fout("clmsc.out");

	int M, N;

	fin >> N >> M;

	int v1[N], v2[M];

	for (int i = 0; i < N; i++) {
		fin >> v1[i];
	}
	for (int i = 0; i < M; i++) {
		fin >> v2[i];
	}
	int dp[N+1][M+1];


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = ((v1[i-1] == v2[j-1]) ? dp[i-1][j-1] + 1 : max(dp[i-1][j], dp[i][j-1]));
		}
	}
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
