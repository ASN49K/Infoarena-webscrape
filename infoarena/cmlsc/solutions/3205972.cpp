#include <bits/stdc++.h>
const int NMAX = 1e3 + 30;
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int dp[NMAX + 5][NMAX + 5];
vector<int>sol;
int A[NMAX + 5], B[NMAX + 5], n, m, posx, posy;
int main() {
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> A[i];
    for (int j = 1; j <= m; j++)
        fin >> B[j];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (A[i] == B[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    posx = n, posy = m;
    while (posx && posy){
        if (A[posx] == B[posy]) {
            sol.push_back(A[posx]);
            posx--, posy--;
        }
        else if (dp[posx - 1][posy] > dp[posx][posy - 1])
            posx--;
        else
            posy--;

    }
    fout << dp[n][m] << "\n";
    for (int i = sol.size() - 1; i >= 0; i--)
        fout << sol[i] << " ";
    return 0;
}
