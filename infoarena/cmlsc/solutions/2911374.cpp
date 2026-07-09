#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    
    int n, m; cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    
    vector<vector<int>> lcs(n, vector<int>(m));
    for (int i = 1; i < n; ++i) {
        lcs[i][0] = lcs[i - 1][0] + int(a[i] == b[0]);
    }
    for (int j = 1; j < m; ++j) {
        lcs[0][j] = lcs[0][j - 1] + int(a[0] == b[j]);
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (a[i] == b[j]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            } else {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }
    cout << lcs[n - 1][m - 1] << endl;
    stack<int> sol;
    int i = n - 1, j = m - 1;
    while (i >= 0 && j >= 0) {
        if (a[i] == b[j]) {
            sol.push(a[i]);
            i--;
            j--;
        } else if (lcs[i][j] == lcs[i - 1][j]) {
            i--;
        } else {
            j--;
        }
    }
    while (!sol.empty()) {
        cout << sol.top() << " ";
        sol.pop();
    }

    return 0;
}