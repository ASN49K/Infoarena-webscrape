#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the LCS of two vectors
vector<int> findLCS(const vector<int>& A, const vector<int>& B) {
    int M = A.size();
    int N = B.size();
    vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));

    // Fill dp table
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruct the LCS
    vector<int> lcs;
    int i = M, j = N;
    while (i > 0 && j > 0) {
        if (A[i - 1] == B[j - 1]) {
            lcs.push_back(A[i - 1]);
            --i;
            --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }

    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main() {
    ifstream infile("cmlsc.in");
    ofstream outfile("cmlsc.out");

    if (!infile || !outfile) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    int M, N;
    infile >> M >> N;

    vector<int> A(M), B(N);
    for (int i = 0; i < M; ++i) {
        infile >> A[i];
    }
    for (int i = 0; i < N; ++i) {
        infile >> B[i];
    }

    vector<int> lcs = findLCS(A, B);

    outfile << lcs.size() << endl;
    for (int num : lcs) {
        outfile << num << " ";
    }
    outfile << endl;

    infile.close();
    outfile.close();

    return 0;
}
