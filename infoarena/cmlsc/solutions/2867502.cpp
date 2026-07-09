#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
#define NMAX 1050
int n, m, best, dp[NMAX][NMAX], a[NMAX], b[NMAX], sir[NMAX];
int main() {
    fin >> n >> m;
    for (int i=1;i<=n;i++){
        fin >> a[i];
    }
    for (int i=1;i<=m;i++){
        fin >> b[i];
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i] == b[j]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int i, j;
    for (i=n, j=m; i;){
        if (a[i] == b[j]){
            sir[++best] = a[i];
            i --;
            j --;
        }else if (dp[i-1][j] < dp[i][j-1]){
            j --;
        }else{
            i --;
        }
    }

    fout << best << '\n';
    for (int i=best;i>=1;i--){
        fout << sir[i] << ' ';
    }
    fout << '\n';
    return 0;
}
