#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

typedef long long int64;

const int oo = 0x3f3f3f3f;

vector<int> A, B, Answer;

vector<int> LongestCommonSubsequence(const vector<int> &first, const vector<int> &second) {
    int n = int(first.size()), m = int(second.size());
    vector< vector<int> > dp = vector< vector<int> >(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (first[i - 1] == second[j - 1])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    vector<int> sequence;
    for (int i = n, j = m; i > 0 && j > 0; ) {
        if (first[i - 1] == second[j - 1] && dp[i][j] == dp[i - 1][j - 1] + 1) {
            sequence.push_back(first[i - 1]);
            --i;
            --j;
            continue;
        }
        if (dp[i][j] == dp[i - 1][j]) {
            --i;
            continue;
        }
        if (dp[i][j] == dp[i][j - 1]) {
            --j;
            continue;
        }
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

void Solve() {
    Answer = LongestCommonSubsequence(A, B);
}

void Read() {
    int n, m;
    cin >> n >> m;
    A = vector<int>(n);
    B = vector<int>(m);
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    for (int i = 0; i < m; ++i)
        cin >> B[i];
}

void Print() {
    cout << int(Answer.size()) << "\n";
    for (int i = 0; i < int(Answer.size()); ++i)
        cout << Answer[i] << " ";
    cout << "\n";
}

int main() {
    assert(freopen("cmlsc.in", "r", stdin));
    assert(freopen("cmlsc.out", "w", stdout));
    Read();
    Solve();
    Print();
    return 0;
}
