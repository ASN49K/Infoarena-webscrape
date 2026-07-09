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
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (A[i] == B[j]) {
				dp[i][j] = 1 + dp[i - 1][j - 1]	;
			} else {
				dp[i][j] = max(dp[i][j], dp[i][j - 1]);
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			}
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	g << dp[N][M] << '\n';

	// Get numbers in sequence by moving backwards.
	int first_index = N, second_index = M;
	while (first_index > 0 && second_index > 0) {
		if (A[first_index] == B[second_index]) {
			max_seq.push_back(A[first_index]);
			first_index--;
			second_index--;
		} else if (dp[first_index][second_index] == dp[first_index - 1][second_index]) {
			first_index--;
		} else {
			second_index--;
		}
	}

	for (int i = dp[N][M] - 1; i >= 0; --i) {
		g << max_seq[i] << ' ';
	}
}
void read() {
	int nr;
	f >> N >> M;
	// dummy push_backs
	A.push_back(-1);
	B.push_back(-2);
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