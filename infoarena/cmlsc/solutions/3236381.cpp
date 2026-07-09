#include<bits/stdc++.h>

std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");

const int MAX = 1030;
int n, m, lastI, lastJ, maxim, dp[MAX][MAX], val[MAX][MAX], A[MAX], B[MAX];
std::pair<int, int> path[MAX][MAX];

void print(int i, int j){
    if(dp[i][j] == 0)
        return;
    print(path[i][j].first, path[i][j].second);
    fout << val[i][j] << ' ';
}

int main(){
    fin >> n >> m;

    for(int i = 1; i <= n; ++i)
        fin >> A[i];

    for(int i = 1; i <= m; ++i)
        fin >> B[i];

    for(int i = 0; i <= m; ++i)
        path[0][i] = std::make_pair(-1, -1);

    for(int i = 0; i <= n; ++i)
        path[i][0] = std::make_pair(-1, -1);

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(A[i] == B[j]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
                path[i][j] = std::make_pair(i - 1, j - 1);
                val[i][j] = A[i];
                if(dp[i][j] > maxim){
                    maxim = dp[i][j];
                    lastI = i;
                    lastJ = j;
                }
            }
            else{
                if(dp[i - 1][j] > dp[i][j]){
                    dp[i][j] = dp[i - 1][j];
                    path[i][j] = path[i - 1][j];
                    val[i][j] = val[i - 1][j];
                }
                if(dp[i][j - 1] > dp[i][j]){
                    dp[i][j] = dp[i][j - 1];
                    path[i][j] = path[i][j - 1];
                    val[i][j] = val[i][j - 1];
                }
                if(dp[i - 1][j - 1] > dp[i][j]){
                    dp[i][j] = dp[i - 1][j - 1];
                    path[i][j] = path[i - 1][j - 1];
                    val[i][j] = val[i - 1][j - 1];
                }
            }

    fout << dp[n][m] << '\n';
    print(lastI, lastJ);
}
