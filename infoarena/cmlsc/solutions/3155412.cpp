#include <bits/stdc++.h>

#define N_MAX 1050

using namespace std;

ifstream fin("cmlsc.in");

ofstream fout("cmlsc.out");

short int dp[N_MAX][N_MAX];

int n, m;

short int A[N_MAX], B[N_MAX];

short int recon[N_MAX];

int k;

int main()
{
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> A[i];
    for (int j = 1; j <= m; j++)
        fin >> B[j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (A[i] == B[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    fout << dp[n][m] << '\n';
    for (int i = n, j = m; i;)
    {
        if (A[i] == B[j])
        {
            recon[++k] = A[i];
            i--;
            j--;
        }
        else if(dp[i][j-1]>dp[i-1][j])
        j--;
        else i--;
    }
    for(;k;k--)
    {
        fout<<recon[k]<<" ";
    }
}