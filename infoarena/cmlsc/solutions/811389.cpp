#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define NMAX 1024

int dp[NMAX][NMAX];
pair <int, int> where[NMAX][NMAX];

void make_path (int x, int y, vector <int> &A, vector <int> &B) {
	if (where[x][y].first == -1) {
		if (A[x] == B[y])
			cout << A[x] << ' ';
		return ;
	}

	make_path (where[x][y].first, where[x][y].second , A, B);
	if (A[x] == B[y])
			cout << A[x] << ' ';
}

void cmlsc (vector <int> &A, vector <int> &B) {
	
	for (int i = 0; i < A.size (); i++) {
		for (int j = 0; j < B.size (); j++) {
			dp[i][j] = 0;
			where[i][j].first = -1;
			where[i][j].second = -1;
			
			if (j > 0) {
				dp[i][j] = dp[i][j-1];
				where[i][j].first = i;
				where[i][j].second = j - 1;
				if (i > 0 && dp[i][j] < dp[i-1][j-1]) {
					dp[i][j] = dp[i-1][j-1];
					where[i][j].first = i - 1;
					where[i][j].second = j - 1;
				}
			}
			
			if (i > 0 && dp[i][j] < dp[i-1][j]) {
				dp[i][j] = dp[i-1][j];
				where[i][j].first = i-1;
				where[i][j].second = j;
			}
			
			if (A[i] == B[j]) {
				if (i == 0 || j == 0) dp[i][j] = 1;
				else if (dp[i][j] < dp[i-1][j-1] + 1) {
					dp[i][j] = dp[i-1][j-1] + 1;
					where[i][j].first = i - 1;
					where[i][j].second = j - 1;
				}
			}
		}
	}
	
	cout << dp[ A.size () - 1 ][ B.size () - 1 ] << endl;
	make_path ( A.size () - 1, B.size () - 1, A, B);
}

int main () {
	
	freopen ("cmlsc.in", "r", stdin);
	freopen ("cmlsc.out", "w", stdout);
	
	int N, M, value;
	vector <int> A, B;
	
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		cin >> value;
		A.push_back (value);
	}
	
	for (int i = 0; i < M; i++) {
		cin >> value;
		B.push_back (value);
	}

	cmlsc (A, B);
	
	return 0;
}
