#include <bits/stdc++.h>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int n, m, a[1024], b[1024], dp[1030][1030], sir[1030], l;

int main()
{
    fin >> n >> m;

    for (int i = 1; i <= n; ++i){
        fin >> a[i];
    }

    for (int i = 1; i <= m; ++i){
        fin >> b[i];
    }

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (a[i] == b[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    for (int i = n, j = m; i > 0; ) {
        if (a[i] == b[j])
            sir[++l] = a[i], i--, j--;
        else if (dp[i-1][j] < dp[i][j-1])
            j--;
        else i--;
    }

    for (int i = l; i >=1; i--)
        fout << sir[i] << " ";
    return 0;
}
