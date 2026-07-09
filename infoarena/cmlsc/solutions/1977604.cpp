//
// Created by littlewho on 5/1/17.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<int> X(n + 1);
    vector<int> Y(m + 1);
    X[0] = Y[0] = -1;

    for (int i = 1; i <= n; i++) {
        cin >> X[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> Y[i];
    }

    vector< vector<int> > C(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; i++) C[i][0] = 0;
    for (int i = 0; i <= m; i++) C[0][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (X[i] == Y[j]) {
                C[i][j] = 1 + C[i - 1][j - 1];
            } else {
                C[i][j] = max(C[i - 1][j], C[i][j - 1]);
            }
        }
    }
    cout << C[n][m] << "\n";

    stack<int> solution;
    for (int i = n, j = m; C[i][j];) {
        if (X[i] == Y[j]) {
            solution.push(X[i]);
            i--;
            j--;
        } else {
            if (C[i][j - 1] > C[i - 1][j]) {
                j--;
            } else {
                i--;
            }
        }
    }

    while (!solution.empty()) {
        cout << solution.top() << " ";
        solution.pop();
    }
    cout << "\n";

    return 0;
}