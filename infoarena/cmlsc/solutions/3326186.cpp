#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

enum retrace_t { SUBTRACT_I, SUBTRACT_J, SUBTRACT_BOTH };

int32_t main() {
    // Let N, M be the sizes of our vectors
    size_t N, M;

    // Input N, M
    fin >> N >> M;

    // Let a, b be our vectors
    vector<size_t> a(N);
    vector<size_t> b(M);

    // Input a
    for (size_t &x : a)
        fin >> x;

    // Input b
    for (size_t &x : b)
        fin >> x;

    // Longest common substring ending at a[i] and b[j]
    vector<vector<size_t>> dp(a.size() + 1, vector<size_t>(b.size() + 1, 0));

    // Create a retrace matrix
    vector<vector<retrace_t>> backtrack(a.size() + 1, vector<retrace_t>(b.size() + 1));

    for (size_t i = 1; i <= a.size(); ++i)
        for (size_t j = 1; j <= b.size(); ++j) {
            size_t c1, c2, c3;

            // Case 1: we add a character to the common substring
            c1 = dp[i - 1][j - 1] + (a[i - 1] == b[j - 1]);

            // Case 2: we don't add a character and we only advance on string b
            c2 = dp[i - 1][j];

            // Case 3: we don't add a character and we only advance on string a
            c3 = dp[i][j - 1];

            // Case 1 is optimal
            if (c1 >= c2 && c1 >= c3)
                backtrack[i][j] = SUBTRACT_BOTH;
            // Case 2 is optimal
            if (c2 >= c3 && c2 >= c1)
                backtrack[i][j] = SUBTRACT_I;
            // Case 3 is optimal
            if (c3 >= c2 && c3 >= c1)
                backtrack[i][j] = SUBTRACT_J;

            // Use the optimal case
            dp[i][j] = max(c1, max(c2, c3));
        }


    // Output the length of the longest common subsequence
    fout << dp[a.size()][b.size()] << endl;

    // Use a stack to efficiently reverse answer
    stack<size_t> ans;

    // Backtrack and push into a stack
    size_t i = a.size(), j = b.size();

    // Go to base case
    while (i != 0 || j != 0) {
        // Depending on what the bactrack value is
        switch (backtrack[i][j]) {
            // Subtract I and don't add any chars
            case SUBTRACT_I:
                --i;
                break;
            // Subtract J and don't add any chars
            case SUBTRACT_J:
                --j;
                break;
            // Go diagonally and add char if equal
            case SUBTRACT_BOTH:
                --i; --j;

                // Handle the inequality case
                if (a[i] == b[j])
                    ans.push(a[i]);
                break;
        }
    }

    // Dump the stack
    while (!ans.empty()) {
        fout << ans.top() << ' ';
        ans.pop();
    }
}