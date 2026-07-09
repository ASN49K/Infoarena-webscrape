#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m;
int dp[1025][1025];
int a[1025], b[1025];

void lmax()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
           if(a[i]==b[j])
            dp[i][j]=1+dp[i-1][j-1];
           else
            dp[i][j]=max(dp[i-1][j] , dp[i][j-1]);
        }
}

void afisare(int i=n, int j=m)
{
    if(dp[i][j]==0)
        return ;
    if(dp[i-1][j]==dp[i][j-1])
        afisare(i-1, j-1);
    else if(dp[i-1][j]!=dp[i][j-1])
    {
        if(dp[i-1][j]>dp[i][j-1])
            afisare(i-1, j);
        else
            afisare(i, j-1);
    }
    if(a[i]==b[j])
        fout << a[i] << " ";

}

int main()
{
    fin >> n >> m;
    for(int i=1; i<=n; i++)
        fin >> a[i];
    for(int i=1; i<=m; i++)
        fin >> b[i];
    lmax();
    fout << dp[n][m] << "\n";
    afisare();
    return 0;
}
