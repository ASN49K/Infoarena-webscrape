#include <bits/stdc++.h>
#define MAXSIZE 1025

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,v[MAXSIZE],w[MAXSIZE],i,j;
int dp[MAXSIZE][MAXSIZE];
int main()
{
    fin >>m>>n;
    for(i=1;i<=m;i++)
        fin >> v[i];
    for(i=1;i<=n;i++)
        fin>>w[i];


    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            dp[i][j] = max(dp[i][j-1], max(dp[i-1][j],dp[i-1][j-1] + (v[i] == w[j])));
        }
    }
    fout<<dp[m][n]<<'\n';
    for(i=1;i<=dp[m][n];i++)
        fout<<i<<' ';
    fout<<'\n';
    return 0;
}