#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int NMAX = 1025;
int n, m, a[NMAX], b[NMAX], dp[NMAX][NMAX];

int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> a[i];
    for(int i = 1; i <= m; i++)
        fin >> b[i];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i] == b[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    fout << dp[n][m] << "\n";
    vector<int> subsir;
    while(dp[n][m] != 0)
    {
        if(a[n] == b[m])
        {
            subsir.push_back(a[n]);
            n--, m--;
        }
        else if(dp[n-1][m] > dp[n][m-1])
            n--;
        else
            m--;
    }
    reverse(subsir.begin(), subsir.end());
    for(int i : subsir)
        fout << i << " ";

    fin.close();
    fout.close();
    return 0;
}
