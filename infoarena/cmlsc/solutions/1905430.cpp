#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1100;

int N, M;
int A[NMAX], B[NMAX];
int DP[2][NMAX], from[2][NMAX];

void solveDP(int left, int right, int leftB, int rightB) {
	int i, j;
	if (leftB > rightB)
		return;
	if (left == right) {
		for (i = leftB; i <= rightB; ++i)
			if (A[left] == B[i]) {
				cout << A[left] << ' ';
				break;
			}
		return;
	}
	int mid = (left + right) / 2;
	int curr = 1, prev = 0;
	memset(DP[prev], 0, sizeof DP);
	for (i = left; i <= right; ++i) {
		swap(prev, curr);
		for (j = leftB; j <= rightB; ++j)
			if (A[i] == B[j]) {
				DP[curr][j] = 1 + DP[prev][j - 1];
				from[curr][j] = i <= mid ? j : from[prev][j - 1];
			} else {
				if (DP[curr][j - 1] > DP[curr][j]) {
					DP[curr][j] = DP[curr][j - 1];
					from[curr][j] = i <= mid ? j : from[curr][j - 1];
				} else {
					DP[curr][j] = DP[prev][j];
					from[curr][j] = i <= mid ? j : from[prev][j];
				}
			}
	}
	if (left == 1 && right == N)
		cout << DP[curr][M] << '\n';
	int midState = from[curr][rightB];
	solveDP(left, mid, leftB, midState);
	solveDP(mid + 1, right, midState + 1, rightB);
}

int main() {
	assert(freopen("cmlsc.in", "r", stdin));
	assert(freopen("cmlsc.out", "w", stdout));
	int i;
	cin >> N >> M;
	for (i = 1; i <= N; ++i)
		cin >> A[i];
	for (i = 1; i <= M; ++i)
		cin >> B[i];
	solveDP(1, N, 1, M);
	cout << '\n';
	return 0;
}
