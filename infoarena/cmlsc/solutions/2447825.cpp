#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, a[1030], m , b[1030];
int dp[1030][1030];
int aux[1030];

int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> a[i];
    for(int i = 1; i <= m; i++)
        fin >> b[i];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            if(a[i] == b[j]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
        }

//    for(int i = 1; i <= n; i++, cout << "\n")
//        for(int j = 1; j <= m; j++)
//            cout << dp[i][j] << " ";

    fout << dp[n][m] << "\n";
    int i = n, j = m;
    int x = dp[n][m];

    while(x)
    {
        if(a[i] == b[j])
        {
            aux[x] = a[i];
            x--;
            i--;
            j--;
        }
        else if(dp[i-1][j] < dp[i][j - 1])
            j--;
        else i--;
    }

    for(int i = 1; i <= dp[n][m]; i++)
        fout << aux[i] << " ";

    return 0;
}
