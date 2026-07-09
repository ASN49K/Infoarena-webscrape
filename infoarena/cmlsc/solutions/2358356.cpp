#include <bits/stdc++.h>
#define nmax 1025

using namespace std;

ofstream fout("cmlsc.out");
ifstream fin("cmlsc.in");

int n,m,a[nmax],b[nmax],dp[nmax][nmax],sol[nmax],len;

int main()
{
    int i,j;
    fin >> n >> m;
    for(i = 1; i <= n; i++)
        fin >> a[i];
    for(i = 1; i <= m; i++)
        fin >> b[i];

    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);

    fout << dp[n][m] << "\n";
    for(i = n, j = m; j; )
        if(a[i] == b[j]) sol[++len] = a[i], i--, j--;
        else if(dp[i-1][j] < dp[i][j-1]) j--;
        else i--;

    while(len)
        fout << sol[len--] << " ";

    fin.close();
    fout.close();
    return 0;
}
