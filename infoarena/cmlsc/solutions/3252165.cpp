#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NMAX = 1024;

int n, m;
int a[NMAX+1];
int b[NMAX+1];

int dp[NMAX+1][NMAX+1];

vector <int> ans;

int main()
{
    fin >> n >> m;
    for(int i=1; i<=n; i++)
        fin >> a[i];
    for(int j=1; j<=m; j++) 
        fin >> b[j];

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1]+1;  
            else    
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int i = n, j = m;
    while(i >= 1 && j>=1)
    {
        if(a[i] == b[j])
            ans.push_back(a[i]), i--, j--;
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }
    fout << dp[n][m] << '\n'
    for(int i=dp[n][m]-1; i>=0; i--)
        fout << ans[i] << ' ';
    return 0;
}


