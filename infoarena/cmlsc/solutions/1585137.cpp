#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

vector<int> common_substring(const vector<int>& A, const vector<int>& B) {
    int n = static_cast<int>(A.size());
    int m = static_cast<int>(B.size());
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= A.size(); ++i) {
	for (int j = 1; j <= B.size(); ++j) {
	    if (A[i - 1] == B[j - 1]) {
		dp[i][j] = dp[i - 1][j - 1] + 1;
	    } else {
		dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	    }
	}
    }

    vector<int> result;
    int i = n, j = m;
    while (i != 0 && j != 0) {
	if (A[i - 1] == B[j - 1]) {
	    result.push_back(A[i - 1]);
	    --i; --j;
	} else if (dp[i - 1][j] > dp[i][j - 1]) {
	    --i;
	} else {
	    --j;
	}
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    
    int n, m;
    fin >> n >> m;

    vector<int> A(n);
    vector<int> B(m);
    for (int i = 0; i < n; ++i) {
	fin >> A[i];
    }
    for (int i = 0; i < m; ++i) {
	fin >> B[i];
    }

    auto result = common_substring(A, B);
    fout << result.size() << endl;
    for (auto x : result) {
	fout << x << " ";
    }

    return 0;
}
