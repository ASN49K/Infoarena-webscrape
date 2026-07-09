#include <bits/stdc++.h>
#define MAXN 1026
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int N, M;
vector<int> A;
vector<int> B;

vector<int> max_seq;
void cmlsc() {
	int dp[MAXN][MAXN] = {0};
	// Get size of sequence using DP.
	if (A[0] == B[0]) {
		dp[0][0] = 1;
	}
	if (A[1] == B[0]) {
		dp[1][0] = 1;
	}
	if (B[1] == A[0]) {
		dp[0][1] = 1;
	}
	for (int i = 1; i < N; ++i) {
		for (int j = 1; j < M; ++j) {
			if (A[i] == B[j]) {
				dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	g << dp[N - 1][M - 1] << '\n';

	// Get numbers in sequence by moving backwards.
	int seq_size = dp[N - 1][M - 1];
	int first_index = 0, second_index = 0;
	while (seq_size != 0) {
		if (dp[first_index][second_index] + 1 == dp[first_index + 1][second_index + 1]) {
			seq_size--;
			max_seq.push_back(A[first_index + 1]);
			first_index++;
			second_index++;
		} else if (dp[first_index][second_index] == dp[first_index + 1][second_index]) {
			first_index++;
		} else {
			second_index++;
		}
	}

	for (int i = 0; i < dp[N - 1][M - 1]; ++i) {
		g << max_seq[i] << ' ';
	}
}
void read() {
	int nr;
	f >> N >> M;
	for (int i = 0; i < N; ++i) {
		f >> nr;
		A.push_back(nr);
	}
	for (int i = 0; i < M; ++i) {
		f >> nr;
		B.push_back(nr);
	}
}
int main() {
	read();
	cmlsc();

	return 0;
}