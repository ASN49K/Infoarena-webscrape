#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cstdio>
using namespace std;

int lcss(vector<int>& A, vector<int>& B, vector<int>& seq) {


	int m = A.size();
	int n = B.size();
	vector<vector<int> > dp(m+1, vector<int>(n+1,0));

	for (int i=1; i<=m; ++i) {
		for (int j=1; j<=n; ++j) {
			dp[i][j] = (A[i] == B[j] ? dp[i-1][j-1] + 1 : max(dp[i-1][j], dp[i][j-1]));
		}
	}

	seq.clear();
	for (int i=m, j=n; i>=1 && j>=1;) {
		if (A[i] == B[j]) {
			seq.push_back(A[i]);
			i--;
			j--;
		}
		else if (dp[i-1][j] < dp[i][j-1]) {
			j--;
		}
		else {
			i--;
		}
	}

	return dp[m][n];
}

int main () {


	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	int m,n;
	cin >> m >> n;
	vector<int> A(m+1), B(n+1);
	for (int i=1; i<=m; ++i) {
		cin >> A[i]; 
	}
	for (int i=1; i<=n; ++i) {
		cin >> B[i]; 
	}

	vector<int> seq;
	int res = lcss(A,B,seq);

	cout << res << "\n";
	for (int i=int(seq.size())-1; i>=0; --i) {
		cout << seq[i] << " ";
	}

	return 0;
}