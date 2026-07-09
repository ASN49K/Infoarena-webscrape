#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

#define lim 1030
int n,m,dr;
int a[lim],b[lim];
int dp[lim][lim], sol[lim];

int main()
{
    fin>>n>>m;
    for (int i=1; i<=n; i++)    fin>>a[i];
    for (int i=1; i<=m; i++)    fin>>b[i];

    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (a[i]==b[j]) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max (dp[i-1][j], dp[i][j-1]);

    fout<<dp[n][m]<<'\n';
    int i=n, j=m;
    while (i>0 && j>0)
    {
        if (a[i]==b[j]) sol[++dr]=a[i], i--, j--;
        else if (dp[i-1][j] > dp[i][j-1])   i--;
        else j--;
    }
    for (int i=dr; i>=1; i--)
        fout<<sol[i]<<' ';

    fout.close();
    return 0;
}
