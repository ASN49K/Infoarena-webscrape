#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, a[1030], b[1030], dp[1030][1030];

int main()
{
    fin >> n >> m;
    for(int i=1; i<=n; i++) fin >> a[i];
    for(int i=1; i<=m; i++) fin >> b[i];
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(a[i] == b[j]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    fout << dp[n][m] << '\n';
    int i = n, j = m;
    vector<int> rez;
    while(i >= 1 && j >= 1) {
        if(a[i] == b[j]) rez.push_back(a[i--]), j--;
        else if(dp[i - 1][j] > dp[i][j - 1]) i--;
        else j--;
    }
    reverse(rez.begin(), rez.end());
    for(int i : rez) fout << i << " ";

    return 0;
}
