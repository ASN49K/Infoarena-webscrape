#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int dp[1030][1030];

int main() {

    int n, m;
    vector<int> v;
    vector<int> w;
    ifstream fin ("cmlsc.in");
    ofstream fout ("cmlsc.out");
    int x;
    fin >> n >> m;
    v.push_back(0);
    w.push_back(0);
    for (int i = 0; i < n; i++) {
        fin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        fin >> x;
        w.push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <=m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (v[i] == w[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
        }
    }
    fout << dp[n][m] << endl;

    int res = dp[n][m];
    int i_pos = n;
    int j_pos = m;
    vector<int> sol;
    while (res > 0) {
        if (v[i_pos] == w[j_pos]) {
            res--;
            sol.push_back(v[i_pos]);
            i_pos = i_pos - 1;
            j_pos = j_pos - 1;
        } else {
            if (dp[i_pos][j_pos - 1] > dp[i_pos - 1][j_pos]) {
                j_pos--;
            } else {
                i_pos--;
            }
        }
    }
    for (int i = sol.size() - 1; i >= 0; i--) {
        fout << sol[i] << " ";
    }
    fout << endl;


    fin.close();
    fout.close();
    return 0;

}
