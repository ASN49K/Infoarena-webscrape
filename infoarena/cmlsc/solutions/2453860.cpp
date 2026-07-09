#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");

    int n, m;
    in >> n >> m;

    vector<int> a(n);

    for (int &x: a)
        in >> x;

    vector<int> b(m);

    for (int &x: b)
        in >> x;

    in.close();

    vector<vector<int>> dp(n);

    for (int i = 0; i < n; i++){
        dp[i].resize(m, 0);

        for (int j = 0; j < m; j++){
            if (a[i] == b[j]){
                if (i - 1 >= 0 && j - 1 >= 0)
                    dp[i][j] = dp[i - 1][j - 1];

                ++dp[i][j];
            } else {
                if (i - 1 >= 0 && j - 1 >= 0){
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                } else if (i - 1 >= 0){
                    dp[i][j] = dp[i - 1][j];
                } else if (j - 1 >= 0){
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
    }

    out << dp[n - 1][m - 1] << endl;

    vector<int> answer;

    int i = n - 1, j = m - 1;

    while (i >= 0 && j >= 0){
        if (a[i] == b[j]){
            answer.push_back(a[i]);
            i--; j--;
        } else if (i - 1 >= 0 && dp[i][j] == dp[i - 1][j]){
            i--;
        } else if (j - 1 >= 0 && dp[i][j] == dp[i][j - 1]){
            j--;
        }
        else {
            break;
        }
    }

    reverse(begin(answer), end(answer));

    for (int x: answer){
        out << x << " ";
    }

    out << endl;

    return 0;
}